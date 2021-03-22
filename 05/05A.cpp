#include <stdio.h>
#include "../TAD.h"

void usandoPilha(FilaEnc *fila) {
    Pilha *pilha = new Pilha;

    for (char i = 'a'; i < 'e'; i++) {
        pilha->empilha(fila->desenfilera());
        printf("%c ", pilha->topo());
    }

    printf("\n --------- INVERTENDO ---------- \n");

    for (char i = 'a'; i < 'e'; i++) {
        printf("%c ", pilha->topo());
        fila->enfilera(pilha->desempilha());
    }
    
    delete pilha;
}

int main() {
    FilaEnc *f = new FilaEnc;

    for (char i = 'a'; i < 'e'; i++) {
        f->enfilera(i);
    }

    usandoPilha(f);

    delete f;
    return 0;
}