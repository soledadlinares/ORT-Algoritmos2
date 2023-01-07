#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

long fiboVignaMemo(int n, int m, long ** memo, bool ** yaCalculado){
    if(n == 0 || m == 0) return 3;
    if (n + m == 3) return 8;
    if (!yaCalculado){
        memo[n][m] = fiboVignaMemo(n, m-1, memo, yaCalculado) + fiboVignaMemo(n - 1, m, memo, yaCalculado) + fiboVignaMemo(n - 1, m - 1, memo, yaCalculado);
        yaCalculado[n][m] = true;
    }
    return memo[n][m];
}

long fiboVigna(int n, int m){
    long ** memo = new long * [n + 1];
    bool ** yaCalculado = new bool * [n + 1];
    for(int i = 0; i < n + 1; i++){
        memo[i] = new long [m + 1]();
        yaCalculado[i] = new bool [m + 1] ();
        for(int j = 0; j < m + 1; j++){
            yaCalculado[i][j] = false;
        }
    }
    return fiboVignaMemo(n, m, memo, yaCalculado);
}

int main () {
    cout << "Ingrese n:";
    int n;
    cin >> n;
    cout << "Ingrese m:";
    int m;
    cin >> m;
    cout << "El fibovigna de " << n << " y " << m << " es " << fiboVigna(n, m);

    return 0;
}