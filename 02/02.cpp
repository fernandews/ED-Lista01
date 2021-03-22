#include <stdio.h>
#include "../TAD.h"

class PilhaFila {
    public:
        FilaEnc fila1;
        FilaEnc fila2;
        size_t tam;

        PilhaFila(){
            tam = 0;
        }

        void destroi () {
            fila1.destroi();
            fila2.destroi();
            tam = 0;
        };

        char topo () {
            for (size_t i = 0; i < tam - 1; i++) {
                fila2.enfilera(fila1.desenfilera());
            }

            char c = fila1.frente();
            fila2.enfilera(fila1.desenfilera());
            fila1 = fila2;
            
            return c;
        }

        void empilha (char dado) {
            fila1.enfilera(dado);
            tam++;
        };

        char desempilha () {
            for (size_t i = 0; i < tam - 1; i++) {
                fila2.enfilera(fila1.desenfilera());
            }

            tam--;
            return fila1.desenfilera();
        };
    
};

int main() {
    PilhaFila *p = new PilhaFila;

    p->empilha('a');
    p->empilha('P');
    printf("%c \n", p->topo());
    
    p->desempilha();
    printf("%c \n", p->topo());

    delete p;
    return 0;
}
