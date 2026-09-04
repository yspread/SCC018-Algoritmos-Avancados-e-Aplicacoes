#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int buscaBinariaNaResposta(int *duracoes_artistas, int t, int low, int high, int k);

int getDays(int *duracoes_artistas, int t, int duracao_max);

int main(){
    //k = dias de festival, t = nro de artistas
    int n, t, k;
    int duracao_max;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t >> k;
        int duracoes_artistas[t]; //contém a duração do show de cada artista
        int duracao_total = 0; //vai armazenar o valor maximo possível para a resposta

        for(int j = 0; j < t; j++){
            cin >> duracoes_artistas[j];
            duracao_total += duracoes_artistas[j];
        }

        //o menor elemento possível do conjunto de respostas é a duração do maior show
        duracao_max = buscaBinariaNaResposta(duracoes_artistas, t, *(max_element(duracoes_artistas, duracoes_artistas + t)), duracao_total, k);
    
        cout << "Caso " << i + 1 << ": " << duracao_max << endl;
    }
}

//essa função faz uma busca binária pelo range possível de valores da resposta
//a resposta com certeza será um valor entre 0 e a soma da duração do show de todos os artistas
//a cada iteração da busca binária, verificamos se a quantidade de dias de festival necessários
//para aquele valor de resposta condiz com o fornecido pelo usuário.
//caso sim, encontramos a resposta correta
int buscaBinariaNaResposta(int *duracoes_artistas, int t, int low, int high, int k){
    if (low > high) return low; //caso base, low vai ser a menor duração máxima
    
    int duracao_atual = low + (high - low)/2; //a duração que estamos verificando nesta iteração
    int qtd_dias = getDays(duracoes_artistas, t, duracao_atual);

    if (qtd_dias <= k){
        //se a duração atual do festival for menor que a inserida pelo usuário, devemos ir diminuindo
        //a duração máxima de um dia (resultando em mais dias de festival)
        //pode ser que exista + de 1 duração máxima para certa qtd de dias, portanto devemos ir diminuindo a duração máxima até qtd dias > k
        return buscaBinariaNaResposta(duracoes_artistas,  t, low, duracao_atual - 1, k);
    }
    else{ 
        //caso contrario, devemos aumentar a duração máxima atual, o que diminuirá a duração em dias do festival
        return buscaBinariaNaResposta(duracoes_artistas, t, duracao_atual + 1, high, k);
    }
}

//função para retornar quantos dias o festival deve durar para que seja possível
//que o parâmetro duracao_max seja de fato a resposta pro problema
int getDays(int *duracoes_artistas, int t, int duracao_max){
    //duracao_atual -> contador que serve pra comparar com duracao_max e ir formando os grupos por dia
    //conta_dias -> conta quantos dias o limite de duracao atual foram
    int conta_dias = 1, duracao_atual = 0;
    for (int i = 0; i < t; i++){
        if (duracao_atual + duracoes_artistas[i] <= duracao_max){
            duracao_atual += duracoes_artistas[i];
        }
        else{
            duracao_atual = duracoes_artistas[i];
            conta_dias++;
        }
    }
    return conta_dias;
}