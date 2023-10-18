

#include <stdio.h>
#include <stdlib.h>
#define TAM 3


    typedef struct{
         
        char nome[50];
        int idade;
       
   }Pessoa;
    
    typedef struct{
        
        int topo;
        Pessoa pessoa[TAM]; 
        
        
    }Pilha;
    
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


     Pilha* criar(){
        
        Pilha *nova = malloc(sizeof(Pilha));
        nova->topo = -1;
        return nova;
    }
    
    void push(Pilha *p){
        
        if(p->topo == TAM - 1){
            
            printf("\nLista cheia!");
            
        }else{
            
            p->topo++;
            p->pessoa[p->topo] = setPessoa();
            
        }
        
    }
    
    Pessoa* pop(Pilha *p){
        
        if(p->topo == -1){
            
            printf("\nPilha vazia!");
            return NULL;
            
        }else{
            
            Pessoa *remover; 
            *remover = p->pessoa[p->topo];
            p->topo--;
            return remover;
        }
    }
    
    void imprimir(Pilha *p){
       
       printf("\n\n--------Pilha--------Tamanho: %i\n\n",TAM);
       
       if(p->topo != -1){
           
       
           int i = 0;
           
           while(i < p->topo + 1){
              
                getPessoa(p->pessoa[i]);
                i++;
                
            
            }   
            
        }else{
               printf("\n\nPilha Vazia!\n\n");
        }
       
       printf("\n\n--------Fim da pilha--------\n\n");
   }
   
   void limpar(Pilha *p){
       
       free(p);
       p->topo = -1;
   }


int main(){

    
    
   Pessoa * remover;
    
    
   Pilha *p = criar();
   int op;
    
    do{
        
    printf("\n\n0 - sair\n1 - Push\n2 - Pop\n3 - Imprimir\n4 - limpar\n");
    
    printf("\nDigite a opcao: ");
    scanf("%i",&op);
    
    switch(op){
        
        case 0: 
                return 0;
                break;
        
        case 1: 
                
                push(p);
                break;
                
        case 2: 
               
                remover = pop(p);
                
               
                if(remover){
                    printf("\nNo removido com sucesso!");
                    getPessoa(*remover);
                    
                }else{
                    printf("\nSem no a remover!");
                }
                break;
                
        case 3: 
                imprimir(p);
                 break;
                
        case 4: 
                
                limpar(p);
                break;
                
        default:
        
            printf("\nOpcao invalida!");
        
        
    }
    
}while(op != 0);
    
    
    
    return 0;
}