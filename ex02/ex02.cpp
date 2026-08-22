#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t, n, p, q, conta_ovos, conta_peso;
    
    cin >> t; //numero de casos teste
    for(int i = 0; i < t; i++){
        conta_ovos = 0; //conta quantos ovos podem ser fervidos juntos
        conta_peso = 0; //conta o peso total dos ovos que estão na tigela
        cin >> n >> p >> q;
        
        //leitura do peso dos ovos
        int peso_ovos[n];
        for (int j = 0; j < n; j++){
            cin >> peso_ovos[j];
        }
        //ordenando o array por ordem de peso
        sort(peso_ovos, peso_ovos + n - 1);

        //para a nossa solução gulosa, basta ir botando os ovos de menor peso na tigela, até
        //que não se caiba mais na tigela
        for (int j = 0; j < n; j++){
            if(conta_ovos < p && conta_peso + peso_ovos[j] <= q){
                conta_ovos++;
                conta_peso += peso_ovos[j];
            }
        }
        cout << "Caso " << (i + 1) << ": " << conta_ovos << endl;
    }
}