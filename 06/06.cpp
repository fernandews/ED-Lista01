#include <stdio.h>
#include "../TAD.h"

class NoInt {
    public:
        int dado;
        NoInt *ant_referencia;
        NoInt *prox_referencia;

        NoInt(int e){
            dado = e;
            ant_referencia = nullptr;
            prox_referencia = nullptr;
        }
};

class PilhaMin {
    public:
        Pilha p;
        NoInt *min;
        NoInt *min_antes;
        NoInt *primeiro_indice;
        NoInt *ultimo_indice;

        PilhaMin(){
            min = nullptr;
            min_antes = nullptr;
            primeiro_indice = nullptr;
            ultimo_indice = nullptr;
        };

        void empilha(char dado) {
        //  método de empilhar
            NoInt *novo = new NoInt{dado};

            if(primeiro_indice == nullptr && ultimo_indice == nullptr) {
            // caso não tenha nada no deque
                primeiro_indice = novo;
                ultimo_indice = novo;
                min = ultimo_indice;

                return;
            }
            else {
                novo->ant_referencia = ultimo_indice;
                ultimo_indice->prox_referencia = novo;

                ultimo_indice = novo;

                if (ultimo_indice->dado < min->dado) {
                    min_antes = min;
                    min = ultimo_indice;
                }
            }

            return;
        }

        int topo() {
            int i = ultimo_indice->dado;
            return i;
        }

        int desempilha() {
            if (ultimo_indice == min) {
                min = min_antes;
            }
            
            if (ultimo_indice == primeiro_indice) {
                int c = ultimo_indice->dado;

                delete ultimo_indice;
                delete primeiro_indice;

                primeiro_indice = nullptr;
                ultimo_indice = nullptr;

                return c;
            }
            else {
                NoInt *novo_ultimo = ultimo_indice->ant_referencia;
                int c = ultimo_indice->dado;

                delete ultimo_indice;
                ultimo_indice = novo_ultimo;

                return c;
            }
        }

        NoInt *obterMinimo() {
            return min;
        }
};

int main() {
    PilhaMin *p = new PilhaMin;

    p->empilha(3);
    printf("Minimo: %d \n", p->obterMinimo()->dado);
    
    p->empilha(1);
    printf("Minimo: %d \n", p->obterMinimo()->dado);
    
    p->desempilha();
    printf("Minimo: %d \n", p->obterMinimo()->dado);

    delete p;
    return 0;
}