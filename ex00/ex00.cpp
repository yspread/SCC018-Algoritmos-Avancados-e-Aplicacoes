#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int x = 0, ncasos, ncomandos;
    string comando;
    vector<string> listacomandos; //vetor que vai guardar todos os comandos ja feitos no caso teste atual
    
    cin >> ncasos;
    for(int i = 0; i < ncasos; i++)
    {   
        x = 0;
        cin >> ncomandos;
        for (int j = 0; j < ncomandos; j++)
        {
            cin >> comando;

            if (comando == "REPETE"){ //numero do comando que será repetido durante o comando "REPETE"
                int nrepetir;
                cin >> nrepetir;

                comando = listacomandos[nrepetir];
            }
            
            if (comando == "ESQUERDA"){ 
                x--;
            }
            else if (comando == "DIREITA"){
                x++;
            }

            listacomandos.push_back(comando); //adiciona o comando utilizado na lista (no caso de "REPETE", guarda o comando executado de fato)    
        }
        cout << x << endl;
        listacomandos.clear(); //reinicia a lista de comandos usados, pra ir pro próximo caso teste
    }
}