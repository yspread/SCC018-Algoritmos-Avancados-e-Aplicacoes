#include <iostream>
#include <string>
#include <utility>
using namespace std;

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
            cin >> pares_ruins[m].first >> pares_ruins[m].second;
        }

        string melhor_pintura[n]; //vai armazenar a melhor pintura
        int pinturas_possiveis; //vai armazenar a quantidade de pinturas que não são horríveis

    }
}

/*
Função que verifica todas as combinações de cores possíveis
Retorna a quantidade de pinturas não horríveis possíveis
Atualiza o array melhor_pintura conforme progride na recursão
*/
int encontraCombinacao(string *cores, int n, pair<string, string> *pares_ruins, int m, string *melhor_pintura){
    
}