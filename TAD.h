#ifndef TAD_H

#define TAD_H
#define MAX 5

#include <stdio.h>
#include <string.h>

class No {
    public:
        char dado;
        No *ant_referencia;
        No *prox_referencia;

        No(char e){
            dado = e;
            ant_referencia = nullptr;
            prox_referencia = nullptr;
        }
};

class FilaSeq {
    public:
        int tam;
        char elementos[MAX] = {'.', '.', '.', '.', '.'};

        void nova() {
            this->tam = 0;
        };

        void enfilera(char dado) {
            this->elementos[tam] = dado; // dado entra no fim
            this->tam++;
        };

        char desenfilera() {
            char c = this->frente();

            for (int i = 0; i < tam-1 ; i++) {
                this->elementos[i] = this->elementos[i + 1];
                this->tam--;
            };

            return c;
        };

        char frente() {
            char c = this->elementos[0];
            return c;
        };
};

class DequeEnc {
    public:
        No *primeiro_indice;
        No *ultimo_indice;

        DequeEnc(){
            primeiro_indice = nullptr;
            ultimo_indice = nullptr;
        };

        void insereFim(char dado) {
            No *novo = new No{dado};

            if(primeiro_indice == nullptr && ultimo_indice == nullptr) {
            // caso não tenha nada no deque
                primeiro_indice = novo;
                ultimo_indice = novo;

                return;
            }
            else {
                novo->ant_referencia = ultimo_indice;
                ultimo_indice->prox_referencia = novo;

                ultimo_indice = novo;
            }
        };

        void insereInicio(char dado) {
            No *novo = new No{dado};

            if(primeiro_indice == nullptr && ultimo_indice == nullptr) {
            // caso não tenha nada no deque
                primeiro_indice = novo;
                ultimo_indice = novo;

                return;
            }
            else {
                novo->prox_referencia = primeiro_indice;
                primeiro_indice->ant_referencia = novo;

                primeiro_indice = novo;
            }
        };

        char removeFim() {
            if (ultimo_indice == primeiro_indice) {
                char c = ultimo_indice->dado;

                delete ultimo_indice;
                delete primeiro_indice;

                primeiro_indice = nullptr;
                ultimo_indice = nullptr;

                return c;
            }
            else {
                No *novo_ultimo = ultimo_indice->ant_referencia;
                char c = ultimo_indice->dado;

                delete ultimo_indice;
                ultimo_indice = novo_ultimo;

                return c;
            }
        };

        char removeInicio() {
            if (ultimo_indice == primeiro_indice) {
                char c = primeiro_indice->dado;

                delete ultimo_indice;
                delete primeiro_indice;

                primeiro_indice = nullptr;
                ultimo_indice = nullptr;

                return c;
            }
            else {
                No *novo_inicio = primeiro_indice->prox_referencia;
                char c = primeiro_indice->dado;

                delete primeiro_indice;
                primeiro_indice = novo_inicio;

                return c;
            }
        };

        char buscaInicio () {
            int i = primeiro_indice->dado;
            return i;
        }

        char buscaFim () {
            int i = ultimo_indice->dado;
            return i;
        }
};

class FilaEnc {
    public:
        DequeEnc d;

        void enfilera(char dado) {
            d.insereFim(dado);
        }

        char desenfilera() {
            return d.removeInicio();
        }

        char frente() {
            return d.buscaInicio();
        }

        void destroi() {
            while (this->frente() != '\0') {
                d.removeInicio();
            }
            
        }
};

class DequeSeq {
    public:
        unsigned int tam;
        char elementos[MAX] = {'.', '.', '.', '.', '.'};

        void novo() {
            this->tam = 0;
        };

        void insereFim(char dado) {
            this->elementos[tam] = dado;
            this->tam++;
        };

        void insereInicio(char dado) {
            if (this->elementos[0] == '\0') {
                printf("primeiro elemento era nulo");
                this->elementos[0] = dado;
            }
            else {
                char temp[MAX] = {'.', '.', '.', '.', '.'};
                temp[0] = dado;
                
                for (size_t i = 1; i < this->tam + 1; i++) {
                    temp[i] = this->elementos[i - 1];
                };

                memcpy(elementos, temp, MAX * sizeof(char));
            }

            this->tam++;
        };

        void removeFim() {
            this->elementos[tam - 1] = '\0';
            this->tam--;
        };

        void removeInicio() {
            for (size_t i = 0; i < tam; i++) {
                this->elementos[i] = this->elementos[i + 1];
            };

            this->tam--;
        };

        char buscaInicio () {
            char c = this->elementos[0];
            return c;
        }

        char buscaFim () {
            char c = this->elementos[tam - 1];
            return c;
        }

        
};

class Pilha {
    public:
        DequeEnc d;

        void empilha(char dado) {
            d.insereFim(dado);
        }

        char topo() {
            return d.buscaFim();
        }

        char desempilha() {
            return d.removeFim();
        }
};

#endif