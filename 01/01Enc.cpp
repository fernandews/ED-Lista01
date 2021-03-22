#include <stdio.h>
#include "../TAD.h"

int main() {
    DequeEnc *deque = new DequeEnc;

    deque->insereFim('a');
    deque->insereInicio('P');
    deque->removeInicio();
    deque->insereFim('u');
    deque->removeFim();
    deque->insereInicio('R');

    printf("%c", deque->buscaInicio());
    printf("%c", deque->buscaFim());

    delete deque;
    return 0;
}