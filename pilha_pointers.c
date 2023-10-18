
#include <stdio.h>
#include <stdlib.h>

 
   typedef struct{
       
       char nome[50];
       int idade;
       
   }Pessoa;
   
   
   typedef struct no{
       
       Pessoa p;
       struct no  *proximo;
       
   }No;
   
   
   typedef struct{
       
       No *topo;
       int tam;
       
   }Pilha;
   
   void criar(Pilha *p){
       
       p->topo = NULL;
       p->tam = 0;
   }
   
  
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
   
   
   void getPessoa(Pessoa p){
       
       
       printf("\n\nNome: %s",p.nome);
       printf("\nIdade: %i\n\n",p.idade);
       
   }
   
   void imprimir(Pilha *p){
       
       printf("\n\n--------Pilha--------Tamanho: %i\n\n",p->tam);
       
           No *aux = p->topo;
           
           if(aux != NULL){
               
               while(aux != NULL){
                   
                   getPessoa(aux->p);
                   aux = aux->proximo;
                  
                   
               }
       }else printf("\n\nPilha Vazia!");
       
       printf("\n\n--------Fim da pilha--------\n\n");
   }
   
   
   void push(Pilha *p){
       
       
    No *no1 = malloc(sizeof(No));
    
    
    if(no1){
        
        no1->p = setPessoa();
       
        no1->proximo = p->topo;
        p->topo = no1;
        p->tam++;
       
        
        
    }else{
        
        printf("\nNão foi possível alocar memória!");
        
    }
       
       
   }
   
   
   No* pop(Pilha *p){
       
       
       if(p->topo != NULL){
           
          
           No *remover = p->topo;
           
           
           
           p->topo = remover->proximo;
           
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
                
                push(&p);
                break;
                
        case 2: 
                
                remover = pop(&p);
                
               
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


    


