#include <iostream>
#include <string>
#include <utility>
using namespace std;

int encontraCombinacao(string *cores, int n, pair<string, string> *pares_ruins, int m, 
                       string *melhor_pintura, string *pintura_atual, int *usada, 
                       int posicao_atual, int &encontrou_melhor);

int isUgly(string cor1, string cor2, pair<string, string> *pares_ruins, int m);

int main()
{
    int t, n, m;

    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;//numero de faixas veriticais
        string cores[n];   
        for(int j = 0; j < n; j++){
            cin >> cores[j]; //leitura de todas as cores que serão usadas nas faixas verticais
        }

        cin >> m; //numero de pares de cores não podem estar lado a lado
        pair<string, string> pares_ruins[m];
        for (int j = 0; j < m; j++){
            cin >> pares_ruins[j].first >> pares_ruins[j].second;
        }

        string melhor_pintura[n]; //vai armazenar a melhor pintura
        string pintura_atual[n]; //armazena pintura atual na recursão
        int posicao_atual = 0; //esse valor é a posição atual na qual vamos inserir uma cor na pintura
        int encontrou_melhor = 0; //flag para salvar apenas a primeira pintura favorita

        int usada[n]; //controla quais cores já foram usadas
        for (int j = 0; j < n; j++){
            usada[j] = 0;
        } 
        
        int pinturas_possiveis = encontraCombinacao(cores, n, pares_ruins, m, melhor_pintura,
                                                    pintura_atual, usada, posicao_atual, encontrou_melhor); //vai armazenar a quantidade de pinturas que não são horríveis
    
        cout << pinturas_possiveis << endl;
        for(int j = 0; j < n; j++){
            cout << melhor_pintura[j];
            if (j != n - 1) cout << " ";
        }
        cout << endl;               
    }
}

/*
Função que verifica todas as combinações de cores possíveis
Retorna a quantidade de pinturas não horríveis possíveis
Atualiza o array melhor_pintura conforme progride na recursão
*/
int encontraCombinacao(string *cores, int n, pair<string, string> *pares_ruins, int m, 
                       string *melhor_pintura, string *pintura_atual, int *usada, 
                       int posicao_atual, int &encontrou_melhor) {

    //Caso base: completou a pintura
    if (posicao_atual == n) {
        //A primeira combinação válida encontrada é salva como a favorita
        if (!encontrou_melhor) {
            for (int i = 0; i < n; i++) {
                melhor_pintura[i] = pintura_atual[i];
            }
            encontrou_melhor = true;
        }
        return 1; //Encontrou 1 pintura válida
    }

    int total_validas = 0;

    for (int i = 0; i < n; i++) {
        if (!usada[i]) {
            //se não for a primeira cor, verifica se forma um par horrível com a anterior
            if (posicao_atual > 0 && isUgly(pintura_atual[posicao_atual - 1], cores[i], pares_ruins, m)) {
                continue;
            }

            //escolhe a cor
            usada[i] = true;
            pintura_atual[posicao_atual] = cores[i];

            //avança para a próxima posição
            total_validas += encontraCombinacao(cores, n, pares_ruins, m, melhor_pintura, 
                                                pintura_atual, usada, posicao_atual + 1, encontrou_melhor);

            //backtracking
            usada[i] = false;
        }
    }
    return total_validas;
}

/*
Função para verificar se uma sequência de 2 cores é considerada horrível ou não
retorna 1 se for horrível, retorna 0 se não
*/
int isUgly(string cor1, string cor2, pair<string, string> *pares_ruins, int m){
    for(int i = 0; i < m; i++){
        if((pares_ruins[i].first == cor1 && pares_ruins[i].second == cor2) || 
            (pares_ruins[i].first == cor2 && pares_ruins[i].second == cor1)){
            return 1;
        }
    }
    return 0;
}