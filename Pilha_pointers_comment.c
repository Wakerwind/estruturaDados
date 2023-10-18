
#include <stdio.h>
#include <stdlib.h>

 //Crio o tipo pessoa que possui nome e idade
   typedef struct{
       
       char nome[50];
       int idade;
       
   }Pessoa;
   
   //Crio a struct que representa um nó
   typedef struct no{
       
       Pessoa p;
       struct no  *proximo;
       
   }No;
   
   //struct que representa a pilha, com um ponteiro para o topo da pilha e o seu tamanho
   typedef struct{
       
       No *topo;
       int tam;
       
   }Pilha;
   
   void criar(Pilha *p){
       
       p->topo = NULL;
       p->tam = 0;
   }
   
   //Função para receber os dados da Pessoa
   //Ela retorna uma Pessoa preenchida para o nó criado
   Pessoa setPessoa(){
       
       
       Pessoa p;
       
       getchar();
       printf("\nDigite o nome da pessoa: ");
       fgets(p.nome,50,stdin);
       
       printf("\nDigite a idade da pessoa: ");
       scanf("%i",&p.idade);
       printf("\n");
       
       return p;
   }
   
   //Imprime uma pessoa
   void getPessoa(Pessoa p){
       
       
       printf("\n\nNome: %s",p.nome);
       printf("\nIdade: %i\n\n",p.idade);
       
   }
   
   void imprimir(Pilha *p){
       
       printf("\n\n--------Pilha--------Tamanho: %i\n\n",p->tam);
       
       //Usamos um ponteiro auxiliar para percorrer a pilha, pq se usarmos p->topo...
       //E alterarmos seu valor, vamos alterar o topo da nossa pilha e bagnçar ela
       
           No *aux = p->topo;
           
           if(aux != NULL){
               
               while(aux != NULL){
                   
                   getPessoa(aux->p);
                   aux = aux->proximo;
                  
                   
               }
       }else printf("\n\nPilha Vazia!");
       
       printf("\n\n--------Fim da pilha--------\n\n");
   }
   
   
   
   //Crio uma função para criar e retorna um nó para o ponteiro topo na main
   //Como o ponteiro que aponta para o topo está agora dentro do struct pilha e não da main...
   //A função não precisa mais de retorno para alterar o topo da pilha
   
   
   void push(Pilha *p){
       
       
    //crio um nó e aloco memória para fazer a operação de push, inserir um novo nó na pilha
    No *no1 = malloc(sizeof(No));
    
    //Testa se a alocação funcionou
    if(no1){
        
        no1->p = setPessoa();
        //Como estamos inserindo um novo nó, fazemos o ponteiro proximo apontar para o elemento abaixo dele, ou seja, o antigo nó no topo
        no1->proximo = p->topo;
        p->topo = no1;
        p->tam++;
        //retorna o novo nó criado para o ponteiro que aponta para o primeiro nó da pilha
        
        
    }else{
        printf("\nNão foi possível alocar memória!");
    }
       
       
   }
   
   //Função que desempilha, ela recebe um ponteiro para o ponteiro que aponta para o topo da pilha na main
   //No final a função retorna o nó removido
   No* pop(Pilha *p){
       
       //Se o topo da pilha for nulo ela está vazia então retorna null pra quem chamou a função
       if(p->topo != NULL){
           
           //Crio um ponteiro qe vai apontar para o nó no topo a ser removido
           No *remover = p->topo;
           
           //Digo agora que o novo topo vai ser o nó abaixo do nó no topo( o próximo)
           
           p->topo = remover->proximo;
           //Retorno o nó removido
           return remover;
           p->tam--;
           
           
       }else{
           printf("\n\nPilha vazia!\n\n");
           return NULL;
       }
       
       
       
   }
   
   void limpar(Pilha *p){
       
       
       No *aux = p->topo;
       No *remover;
       
       if(aux != NULL){
           while(aux != NULL){
               
           remover = pop(p);
           free(remover);
           aux= aux->proximo;
           
           }
       
           p->tam = 0;
           printf("\n\nPilha limpa com sucesso!\n\n");
   
       }else{
        printf("\n\nPilha Vazia\n\n");
       }
   }
int main()
{
    
   
   
   //Crio minha pilha, que é esse ponteiro que aponta para o topo da pilha
   //Como eu crio a pilha vazia o ponteiro recebe NULL
    No *remover;
    Pilha p;
    
    criar(&p);
    int op;
    
    do{
    printf("0 - sair\n1 - Push\n2 - Pop\n3 - Imprimir\n4 - limpar\n");
    
    printf("\nDigite a opcao: ");
    scanf("%i",&op);
    
    switch(op){
        
        case 0: 
                return 0;
                break;
        
        case 1: 
                //O ponteiro que aponta para o topo da pilha recebe o novo nó criado na função push(empilhar)
                push(&p);
                break;
                
        case 2: 
                
                //O ponteiro remover recebe o nó removido na função pop
                //Passo como parametro o endereço do nó no topo para que seu valor seja alterado na main por outra função
                remover = pop(&p);
                
                //Se o retorno for nullo a pilha estava vazia
                //se não mostra os dados do nó removido
                if(remover){
                    
                    printf("\nNo removido com sucesso!");
                    getPessoa(remover->p);
                    free(remover);
                    
                }else{
                    
                    printf("\nSem no a remover!");
                }
                break;
                
        case 3: 
                imprimir(&p);
                break;
                
        case 4: 
                limpar(&p);
                break;
                
        default:
            printf("\nOpcao invalida!");
        
        
        
    }
    
    }while(op != 0);
    
    return 0;
    
}


    


