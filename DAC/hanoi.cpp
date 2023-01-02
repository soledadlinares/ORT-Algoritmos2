#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

//Usando DAC:
/*
1- n-1 discos se mueven al pilar auxiliar (recursion)
2- El disco mayor se mueve a destino
3- El pilar original pasa a ser el auxiliar
*/

//n cantidad de discos
void hanoi(int n, string origen, string destino, string auxiliar){
    if(n == 1) cout<< "Muevo disco " << n << " desde " << origen << " a " << destino << endl;
    else{
        hanoi(n -1, origen, auxiliar, destino);
        cout<< "Muevo disco " << n << " desde " << origen << " a " << destino << endl;
        hanoi(n -1, auxiliar, destino, origen);
    }
}

int main (){
    hanoi(6, "A", "B", "C");
    return 0;
}