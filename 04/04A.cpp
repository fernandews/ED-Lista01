#include <stdio.h>
#include "../TAD.h"

void usandoFila(Pilha *p) {
    FilaEnc *fila = new FilaEnc;
    for (char i = 'a'; i < 'e'; i++) {
        fila->enfilera(p->desempilha());
    }

    for (char i = 'a'; i < 'e'; i++) {
        p->empilha(fila->desenfilera());
        printf("%c ", p->topo());
    }
    
    delete fila;
}

int main() {
    Pilha *p = new Pilha;

    for (char i = 'a'; i < 'e'; i++) {
        p->empilha(i);
        printf("%c ", p->topo());
    }

    printf("\n --------- INVERTENDO ---------- \n");
    usandoFila(p);

    delete p;
    return 0;
}