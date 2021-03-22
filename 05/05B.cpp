#include <stdio.h>
#include "../TAD.h"

void usandoFilas(FilaEnc *fila, int tam) {
    FilaEnc *fila1 = new FilaEnc;
    FilaEnc *fila2 = new FilaEnc;
    int size = tam - 1;
    
// fila vazia, contaúdo em fila1
    for (size_t i = 0; i < tam; i++){
        fila1->enfilera(fila->desenfilera());
    }
    

    while (size != -1) {
        for (size_t i = 0; i < size; i++) {
            fila2->enfilera(fila1->desenfilera());
        }
        printf("%c ", fila1->frente());
        fila->enfilera(fila1->desenfilera());
        fila1 = fila2;

        size--;
    }
    
}

int main() {
    FilaEnc *f = new FilaEnc;

    for (char i = 'a'; i < 'e'; i++) {
        f->enfilera(i);
        printf("%c ", i);
    }

    printf("\n --------- INVERTENDO ---------- \n");
    usandoFilas(f, 4);

    delete f;
    return 0;
}