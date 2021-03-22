#include <stdio.h>
#include "../TAD.h"

class Fila {
    public:
        Pilha pilha1;
        Pilha pilha2;
        unsigned int tam;

        Fila() {
            tam = 0;
        }

        void enfilera(char dado) {
            pilha1.empilha(dado);
            tam++;
        }

        char desenfilera() {
            for (size_t i = 0; i < tam - 1; i++) {
                pilha2.empilha(pilha1.desempilha());
            }

            char c = pilha1.desempilha();

            for (size_t i = 0; i < tam - 1; i++) {
                pilha1.empilha(pilha2.desempilha());
            }
            
            tam--;
            return c;
        }

        char frente() {
            for (size_t i = 0; i < tam - 1; i++) {
                pilha2.empilha(pilha1.desempilha());
            }

            char c = pilha1.topo();
            for (size_t i = 0; i < tam - 1; i++) {
                pilha1.empilha(pilha2.desempilha());
            }
            
            return c;
        }
};

int main() {
    Fila *f = new Fila;

    f->enfilera('a');
    f->enfilera('p');
    printf("%c", f->desenfilera());
    printf("%c", f->frente());
    printf("%c", f->desenfilera());

    delete f;
    return 0;
}
