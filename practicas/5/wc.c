#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <stdbool.h> 

int main() {
    char c;
    unsigned caracteres = 0,
             palabras = 0,
             lineas = 0;
    bool isSpace = false;

    while(read(STDIN_FILENO,&c,1) != 0) {
		if(c == '\n') {
            lineas++;
            if (isSpace) palabras++;
        } 
        else if(c != ' ') {
            isSpace = true;
        } 
        else if(isSpace) {
            palabras++;
            isSpace = false;
        }
        caracteres++;
    }
    printf("Numero de lineas: %u\n", lineas);
    printf("Numero de palabras: %u\n", palabras);
    printf("Numero de caracteres: %u\n", caracteres);
    return 0;
}