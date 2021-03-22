#include <stdio.h>
#include "../TAD.h"
#define TAM 5 

void usandoPilha(Pilha *p, int tam) {
    Pilha *temp = new Pilha;

    for (size_t i = 0; i < tam; i++) {
        temp->empilha(p->desempilha());
        printf("%c ", temp->topo());
    }

    p = temp;
    delete temp;
}

int main() {
    Pilha *p = new Pilha;
   
    for (char i = 'a'; i < 'e'; i++) {
        p->empilha(i);
        printf("%c ", p->topo());
    }

    printf("\n --------- INVERTENDO ---------- \n");
    usandoPilha(p, 4);

    delete p;
    return 0;
}
