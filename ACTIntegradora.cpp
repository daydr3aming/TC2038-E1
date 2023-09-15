#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
    std::string transmission3;
    std::string mcode1;
    std::string mcode2;
    std::string mcode3;


    for(int i = 0; i < allfiles.size(); i++){
        std::fstream file(allfiles[i] + ".txt");
        while(getline(file, line)){
            if(i == 0){
                transmission1 += line + "\n";
            }
            else if(i == 1){
                transmission2 += line + "\n";
            }
            else if(i == 2){
                mcode1 += line + "\n";
            }
            else if(i == 3){
                mcode2 += line + "\n";
            }
            else if(i == 4){
                mcode3 += line + "\n";
            }
        }
    }

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
    
    transmission1file.close();
    transmission2file.close(); 
    mcode1file.close();
    mcode2file.close();
    mcode3file.close();
    return 0;
}
 