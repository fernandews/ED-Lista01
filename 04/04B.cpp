#include <stdio.h>
#include "../TAD.h"
#define TAM 5 

void usandoPilhas(Pilha *p, int tam) {
    Pilha *pilha1 = new Pilha;
    Pilha *pilha2 = new Pilha;

    for (size_t i = 0; i < tam; i++) {
        pilha1->empilha(p->desempilha());
    }

    for (size_t i = 0; i < tam; i++) {
        pilha2->empilha(pilha1->desempilha());
    }

    for (size_t i = 0; i < tam; i++) {
        p->empilha(pilha2->desempilha());
        printf("%c ", p->topo());
    }

    delete pilha1;
    delete pilha2;
}

int main() {
    Pilha *p = new Pilha;
   

    for (char i = 'a'; i < 'e'; i++) {
        p->empilha(i);
        printf("%c ", p->topo());
    }

    printf("\n --------- INVERTENDO ---------- \n");
    usandoPilhas(p, 4);

    delete p;
    return 0;
}