#include <stdio.h>
#include "../TAD.h"

int main () {
    DequeSeq deque;

    deque.novo();
    // printf("puro, tam = %d", deque.tam);

    deque.insereFim('a');
    // printf("\na, tam = %d \n", deque.tam);
    // for (size_t i = 0; i < 5; i++) {
    //     printf("%c", deque.elementos[i]);
    // };

    deque.insereInicio('P');
    // printf("\nPa, tam = %d\n", deque.tam);
    // for (size_t i = 0; i < 5; i++) {
    //     printf("%c", deque.elementos[i]);
    // }

    deque.removeInicio();
    // printf("\na, tam = %d\n", deque.tam);
    // for (size_t i = 0; i < 5; i++) {
    //     printf("%c", deque.elementos[i]);
    // }

    deque.insereFim('u');
    // printf("\nau, tam = %d\n", deque.tam);
    // for (size_t i = 0; i < 5; i++) {
    //     printf("%c", deque.elementos[i]);
    // }

    deque.removeFim();
    // printf("\na, tam = %d\n", deque.tam);
    // for (size_t i = 0; i < 5; i++) {
    //     printf("%c", deque.elementos[i]);
    // }

    deque.insereInicio('R');
    // printf("\nRa, tam = %d\n", deque.tam);
    // for (size_t i = 0; i < 5; i++) {
    //     printf("%c", deque.elementos[i]);
    // }

    printf("%c", deque.buscaInicio());
    printf("%c", deque.buscaFim());

}