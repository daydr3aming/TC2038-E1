#include <iostream>
#include <stdio.h>
#include <string.h>



void LPS(char const*pat, int M, int *lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while(i<M){
        if(pat[i]==pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0 ){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }


    }
}


void KMPSearch(char const* pat, char const* text){
    int M = strlen(pat);
    int N = strlen(text);

    int lps[M];

    LPS(pat, M, lps);

    int i = 0;
    int j = 0;
    while(i < N){
        if(pat[j] == text[i]){
            j++;
            i++;
        }

        if(j == M){
            printf("Found pattern at index %d \n", i-j);
            j = lps[j-1];

        }

        else if( i < N && pat[j]!= text[i]){

            if( j != 0){
                j = lps[j-1];
            }
            else{
                i = i + 1;
            }
        }
    }
}
int main(){

    char const* pal = "ABXAB";
    char const* texto = "ABXABABXAB";

    KMPSearch(pal, texto);


    return 0;
}