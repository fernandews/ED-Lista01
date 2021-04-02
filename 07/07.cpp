#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int prioridade (char x){
    int prioridade;
    switch (x){
        // mais prioridade
        case '*':
        case '/':
            prioridade = 3;
            break;

        // menos prioridade
        case '+':
        case '-':
            prioridade = 2;
            break;

        // sempre por último
        case '(':
            prioridade = 1;
            break;
    }
    return prioridade;
}

int main(void){
    char expressao;//elemento atual
    stack<char> p; //pilha auxiliar
    queue<char> npr, f; //notação polonesa reversa

    printf("Expressao: ");
    while (expressao != '\n') { // até apertar entr 
        scanf("%c", &expressao);
        if ('A'<=expressao && expressao<='Z'){ //se for letra maiúscula
            npr.push(expressao); // fica no começo
        }

        else if (expressao == '+'|| expressao == '-'|| expressao == '*'|| expressao == '/'){ //se operador
            int prioridadeElemento = prioridade(expressao);

            if (p.empty()) { //pilha pura
                p.push(expressao);
            }
            else{
                if (prioridadeElemento > prioridade(p.top())){
                    p.push(expressao); //empilha o operador
                }

                else{
                // ajeita a ordem
                    while (prioridadeElemento <= prioridade(p.top())){
                        f.push(p.top());
                        p.pop();
                    }
                    
                    p.push(expressao);
                }     
            }
        }
        
        else if (expressao=='('){
            p.push(expressao);
        }

        else if (expressao==')'){
        // acha o (
            while (p.top() != '('){
                f.push(p.top());
                p.pop();
            }
        //tira o (
            p.pop();
        }
    }

    while(!f.empty()){
        npr.push(f.front());
        f.pop();
    }
    while(!p.empty()){
        npr.push(p.top());
        p.pop();
    }
    
    printf("Notacao Polonesa Reversa: ");
    while (!npr.empty()){
        printf("%c", npr.front());
        npr.pop();
    }
    return 0;
}