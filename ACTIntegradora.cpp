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


void KMPSearch(char const* patron, char const* palabra, int m, int t){
    int M = strlen(patron);
    int N = strlen(palabra);

    int lpsArr[M];

    ArregloLPS(patron, M, lpsArr);

    int i = 0;
    int j = 0;
    while(i < N){
        if(patron[j] == palabra[i]){
            j++;
            i++;
        }

        if(j == M){
            printf("True, transmission %d con mcode %d : patron en el indice: %d \n", t, m, i-j);
            j = lpsArr[j-1];

        }
        else if( i < N && patron[j]!= palabra[i]){

            if( j != 0){
                j = lpsArr[j-1];
            }
            else{
                i = i + 1;
            }
        }
    }
}

void parte1(std::vector<std::string> mcode, std::vector<std::string> transmission, int tNumber, int mNumber){



    for(int i=0; i<transmission.size(); i++){

        const int length =  transmission[i].length();
        char* tranPalabra = new char[length + 1];
        strcpy(tranPalabra,  transmission[i].c_str());


        for(int j=0; j< mcode.size(); j++){
            
            const int length2 =  mcode[j].length();
            char* mcodePalabra = new char[length2 + 1];
            strcpy(mcodePalabra,  mcode[j].c_str());


            // Aqui ya tenemos en variables, la palabra de transmission y mcode, solo falta comparar

  
            KMPSearch(mcodePalabra, tranPalabra, mNumber, tNumber);


            delete[] mcodePalabra;
        }

        delete[] tranPalabra;
    }

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
    std::vector<std::string> transmission1;
    std::vector<std::string> transmission2;
    std::vector<std::string> transmission3;
    std::vector<std::string> mcode1;
    std::vector<std::string> mcode2;
    std::vector<std::string> mcode3;

    for(int i = 0; i < allfiles.size(); i++){
        std::fstream file(allfiles[i] + ".txt");

        while(getline(file, line)){
            if(i == 0){
                transmission1.push_back(line);
            }
            else if(i == 1){
                transmission2.push_back(line);
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

    /*
    std::cout << "tranmission1: " << std::endl;
    std::cout << transmission1 << std::endl;
    std::cout << "tranmission2: " << std::endl;
    std::cout << transmission2 << std::endl;
    std::cout << "mcode1: " << std::endl;
    std::cout << mcode1 << std::endl;
    std::cout << "mcode2: " << std::endl;
    std::cout << mcode2 << std::endl;
    std::cout << "mcode3: " << std::endl;
    std::cout << mcode3 << std::endl;
*/


   // parte1(mcode1, transmission1, 1, 1);
    //parte1(mcode2, transmission1, 1, 2);


    parte1(mcode3, transmission1, 1, 3);
    /*
    parte1(mcode1, transmission2, 2, 1);
    parte1(mcode2, transmission2, 2, 2);
    parte1(mcode3, transmission2, 2, 3);
    */

    //KMPSearch("znxc1m34", "znxc1m34jn413asd", 1,1);
    
    transmission1file.close();
    transmission2file.close(); 
    mcode1file.close();
    mcode2file.close();
    mcode3file.close();





    return 0;
}
 