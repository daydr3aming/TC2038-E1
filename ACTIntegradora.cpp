#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <string.h>

// Actividad Integradora: A01639914 y A01633817


void ArregloLPS(char const* patron, int size, int *arreglo){ // arreglo
    int len = 0;
    arreglo[0] = 0;
    int i = 1;

    while(i<size){
        if(patron[i]==patron[len]){
            len++;
            arreglo[i] = len;
            i++;
        }
        else{
            if(len != 0 ){
                len = arreglo[len - 1];
            }
            else{
                arreglo[i] = 0;
                i++;
            }
        }
    }
}


void KMPSearch(std::vector<std::string> mcode, std::string transmission, int t, int m){
    const int length =  transmission.length();
    char* tranPalabra = new char[length + 1];
    strcpy(tranPalabra,  transmission.c_str());

    int N = strlen(tranPalabra);

    int contador = 0;

    for(int l=0; l< mcode.size(); l++){
            
        const int length2 =  mcode[l].length();
        char* mcodePalabra = new char[length2 + 1];
        strcpy(mcodePalabra,  mcode[l].c_str());

        int M = strlen(mcodePalabra);

        int lpsArr[M];

        ArregloLPS(mcodePalabra, M, lpsArr);

        int i = 0;
        int j = 0;
        

        while(i < N){
            if(mcodePalabra[j] == tranPalabra[i]){
                j++;
                i++;
            }

            if(j == M){
                std::cout<<"True el archivo transmission"<<t<<".txt contiene el codigo ";
                for(int i=0; i<M; i++){
                    std::cout<<mcodePalabra[i];
                }
                std::cout<<" contenido en el archivo mcode"<<m<<".txt en el indice "<< i-j<<std::endl;
                contador++;
                j = lpsArr[j-1];

            }
            else if( i < N && mcodePalabra[j]!= tranPalabra[i]){

                if( j != 0){
                    j = lpsArr[j-1];
                }
                else{
                    i = i + 1;
                }
            }
        }
        

        delete[] mcodePalabra;
    }
    if(contador == 0){
            std::cout<<"False el archivo transmission"<<t<<".txt no contiene el codigo contenido en el archivo mcode"<<m<<".txt "<<std::endl;
        }
    delete[] tranPalabra;
}


int main(){
    std::fstream transmission1file("transmission1.txt");
    std::fstream transmission2file("transmission2.txt");
    std::fstream mcode1file("mcode1.txt");
    std::fstream mcode2file("mcode2.txt");
    std::fstream mcode3file("mcode3.txt");

    if(!transmission1file.is_open() && !transmission2file.is_open() && !mcode1file.is_open() && !mcode2file.is_open() && !mcode3file.is_open()){
        std::cout << "Error opening some or all files." << std::endl;
        return 1;
    }

    std::vector<std::string> allfiles{"transmission1", "transmission2", "mcode1", "mcode2", "mcode3"};


    std::string line;
    std::string transmission1;
    std::string transmission2;
    std::vector<std::string> mcode1;
    std::vector<std::string> mcode2;
    std::vector<std::string> mcode3;

    for(int i = 0; i < allfiles.size(); i++){
        std::fstream file(allfiles[i] + ".txt");

        while(getline(file, line)){
            if(i == 0){
                transmission1 += line;
            }
            else if(i == 1){
                transmission2 += line;
            }
            else if(i == 2){
                mcode1.push_back(line);
            }
            else if(i == 3){
                mcode2.push_back(line);
            }
            else if(i == 4){
                mcode3.push_back(line);
            }
        }
    }



    // Pruebas 

    KMPSearch(mcode1, transmission1, 1, 1);
    KMPSearch(mcode2, transmission1, 1, 2);
    KMPSearch(mcode3, transmission1, 1, 3);
    KMPSearch(mcode1, transmission2, 2, 1);
    KMPSearch(mcode2, transmission2, 2, 2);
    KMPSearch(mcode3, transmission2, 2, 3);



    
    transmission1file.close();
    transmission2file.close(); 
    mcode1file.close();
    mcode2file.close();
    mcode3file.close();





    return 0;
}
 