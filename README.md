# ORT-Algoritmos2

## Como compilar
### C++
#### compilar
##### unix
g++ -o ejemplo ejemplo.cpp
##### Win
g++ -o ejemplo.exe ejemplo.cpp


#### ejecutar "sin salida"
##### unix
./ejemplo < 1000.in.txt > nul 
##### Win
ejemplo.exe < 1000.in.txt > nul


#### ejecutar y crear archivo
##### unix
./ejemplo < 1000.in.txt > 1000.out.txt
##### Win
ejemplo.exe < 1000.in.txt > 1000.out.txt


### JAVA
#### compilar
javac Ejemplo.java
    
#### ejecutar "sin salida"
java ejemplo < 1000.in.txt > nul
    
#### ejecutar y crear archivo
java ejemplo < 1000.in.txt > 1000.out.txt


### Comparar archivos
#### unix
diff  diff command in Linux with examples 
ejemplo: diff --strip-trailing-cr file1Path file2Path 
#### Win
FC -> guia: How to Use FC (File Compare) from the Windows Command Prompt 
winMerge https://winmerge.org
con VS code How to compare contents of two files in Visual Studio Code? 
etc