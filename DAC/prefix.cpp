#include <climits>
#include <string>
#include <iostream>
using namespace std;

string prefixString(string str1, string str2){
    string ret = "";
    int l1 = str1.length(); //Cambiar por sizeof(str1)
    int l2 = str2.length();

    for (int i = 0; i < l1 && i < l2; i++){
        if(str1.charAt(i) == str2.charAt(i)) ret += str1.charAt(i);
    }

    return ret;
}

string DACPrefix(string[] prueba, int inicio, int fin){
    if(inicio == fin) return prueba[inicio];
    int mitad = (fin + inicio) / 2;

    string prefixIzq = DACPrefix(prueba, inicio, mitad);
    string prefixDer = DACPrefix(prueba, mitad + 1, fin);

    return prefixString(prefixIzq, prefixDer);
}

int main (){
    string [4] prueba = {"ABC", "AB", "ABB", "ABE"};
    string solucion = DACPrefix(prueba, 0, prueba.length() -1);
    cout << solucion << endl;

    return 0;
}

//ERRORES:
/*
prefix.cpp:12:17: error: no member named 'charAt' in 'std::string'
        if(str1.charAt(i) == str2.charAt(i)) ret += str1.charAt(i);
           ~~~~ ^
prefix.cpp:12:35: error: no member named 'charAt' in 'std::string'
        if(str1.charAt(i) == str2.charAt(i)) ret += str1.charAt(i);
                             ~~~~ ^
prefix.cpp:12:58: error: no member named 'charAt' in 'std::string'
        if(str1.charAt(i) == str2.charAt(i)) ret += str1.charAt(i);
                                                    ~~~~ ^
prefix.cpp:18:27: error: expected ')'
string DACPrefix(string[] prueba, int inicio, int fin){
                          ^
prefix.cpp:18:17: note: to match this '('
string DACPrefix(string[] prueba, int inicio, int fin){
                ^
prefix.cpp:19:8: error: use of undeclared identifier 'inicio'
    if(inicio == fin) return prueba[inicio];
       ^
prefix.cpp:19:18: error: use of undeclared identifier 'fin'
    if(inicio == fin) return prueba[inicio];
                 ^
prefix.cpp:19:30: error: use of undeclared identifier 'prueba'
    if(inicio == fin) return prueba[inicio];
                             ^
prefix.cpp:19:37: error: use of undeclared identifier 'inicio'
    if(inicio == fin) return prueba[inicio];
                                    ^
prefix.cpp:20:18: error: use of undeclared identifier 'fin'
    int mitad = (fin + inicio) / 2;
                 ^
prefix.cpp:20:24: error: use of undeclared identifier 'inicio'
    int mitad = (fin + inicio) / 2;
                       ^
prefix.cpp:22:34: error: use of undeclared identifier 'prueba'
    string prefixIzq = DACPrefix(prueba, inicio, mitad);
                                 ^
prefix.cpp:22:42: error: use of undeclared identifier 'inicio'
    string prefixIzq = DACPrefix(prueba, inicio, mitad);
                                         ^
prefix.cpp:23:34: error: use of undeclared identifier 'prueba'
    string prefixDer = DACPrefix(prueba, mitad + 1, fin);
                                 ^
prefix.cpp:23:53: error: use of undeclared identifier 'fin'
    string prefixDer = DACPrefix(prueba, mitad + 1, fin);
                                                    ^
prefix.cpp:29:22: error: brackets are not allowed here; to declare an array, place the brackets after the name
    string [4] prueba = {"ABC", "AB", "ABB", "ABE"};
           ~~~~      ^
                     [4]
prefix.cpp:30:50: error: member reference base type 'std::string[4]' is not a structure or union
    string solucion = DACPrefix(prueba, 0, prueba.length() -1);
*/