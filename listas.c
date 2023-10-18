#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Teria como fazer implementando uma struct Lista
//Assim dispensaria o uso de ponteiro para ponteiro nas funções que alteram a lista:

/*
typedef struct{

    No *inicio;
    int tam;
    
}lista;

*/



typedef struct{
	
	int id;
    char nome[50];
	
}Pessoa;

typedef struct no{
    
        Pessoa p;
        struct no *prox;
        
    }No;
    
    Pessoa setPessoa(){
        
        Pessoa p;
        
        
        printf("\n\nDigite seu id: ");
        scanf("%i",&p.id);
        
        getchar();
        
        printf("\n\nDigite seu nome: ");
        fgets(p.nome,50,stdin); 
        
        return p;
    }
    
    void getPessoa(Pessoa p){
        
        printf("\n\nId: %i",p.id);
        printf("\nNome: %s",p.nome);
        
        
    }
    
    void imprimir(No *no){
        
        printf("\n\n-----Lista-----\n\n");
        
        if(no != NULL){
        
            No *aux = no;
            
            while(aux != NULL){
                
                getPessoa(aux->p);
                aux = aux->prox;
            }
        
        }else{
            printf("\n\nLista Vazia!\n\n");
        }
        
        printf("\n\n-----Fim Lista-----\n\n");
    }
    
    void inserir_meio(No **lista, char ant[50]){
        
        No *novo = malloc(sizeof(No));
        
        getchar();
        
        
        novo->p = setPessoa(); 
        
        
        
        if(*lista == NULL){
            
            novo->prox = NULL;
            *lista = novo;
            
            
            
        }else{
            
            
            No *aux = *lista;
            
            /*Procura na lista até achar o no o qual queremos inseir na frente... 
            ou até chegar no final da lista e não encontrar o valor passado*/
            
            while(strcmp(aux->p.nome, ant) != 0 && aux->prox != NULL){
                
                aux = aux->prox;
                
            }
            
            //Meu novo no aponta para quem o no anterior apontava...
            //E o no anterior aponta para o novo novo nó
            
            novo->prox = aux->prox;
            aux->prox = novo;
            
            
            
        }
        
        printf("\n\nNo inserido com sucesso!\n\n");
        
        
    }
    
    void inserir_inicio(No **lista){
        
        getchar();
        
        No *novo = malloc(sizeof(No));
        if(novo){
        	
	        
			
	        novo->p = setPessoa();
	        
	        novo->prox = *lista;
	        
	        *lista = novo;
	        
	        printf("\n\nNo inserido com sucesso!\n\n");
	        
        }else
        	printf("\n\nFalha ao alocar memoria\n\n");
        
    }
    
    void inserir_final(No **lista){
        
        No *novo = malloc(sizeof(No));
        
        if(novo){
        	
        	
        	
	        getchar();
	        
	        novo->p = setPessoa();
	        
	        novo->prox = NULL;
	        
	        
	            
	            
	            if(*lista == NULL){
	                
	                *lista = novo;
	                
	                
	            }else{
	                
	                No *aux = *lista;
	                
	                while(aux->prox != NULL){
	                    aux = aux->prox;
	                }
	                
	                aux->prox = novo;
	                
	                
	            }
	            
	            
	        
	        
	        printf("\n\nNo inserido com sucesso!\n\n");
    }else{
    	printf("\n\nFalha ao alocar memória\n\n");
	}
}
    
    void inserir_ordenado(No **lista){
        
        No *novo = malloc(sizeof(No));
        
        if(novo){
		
		getchar();
		
        
        
        novo->p = setPessoa();
        
        if(*lista == NULL){
            
            *lista = novo;
        
        //Meu novo no eh menor que o primeiro? se sim insere ele no inicio da lista
        }else if(novo->p.id < (*lista)->p.id){
            
            novo->prox = *lista;
            *lista = novo;
            
            
            
        }else{
        	
        	No *aux = *lista;
        	
        	
        	//Enquanto não chegar no final da lista e o meu no for maior que o valor do prox no eu itero na lista
        	
        	while(aux->prox != NULL && aux->p.id > aux->prox->p.id){
        		aux = aux->prox;
			}
        	// o novo aponta para o proximo do no anterior
        	//o anterior aponta para o novo
        	novo->prox = aux->prox;
        	aux->prox = novo;
        	
		}
        
      }  
        
    }
    
    No* remover(No **lista, int id){
	
	No *remover = NULL;
	No *aux;
	
	if(*lista != NULL){
		
		if((*lista) ->p.id == id){
			remover = *lista;
			*lista = remover->prox;
		}else{
			
			aux = *lista;
			
			//itera na lista até chegar no final ou achar o id procurado
			while(aux->prox != NULL && aux->prox->p.id != id){
				aux = aux->prox;
			}
			
			if(aux->prox != NULL){
				
				remover = aux->prox;
				aux->prox = remover->prox;
				
			}else
				printf("\n\nRegistro não encontrado\n\n");
			
			
		}
		
		
		
	}else
		printf("\n\nLista Vazia!\n\n");
		
	
	
	return remover;
	
	
}


int main()
{
    
    No *lista = NULL;
    No *removido;
    int op;
    int id;
    
    char valor[50];
    do{
    
    printf("\n\n 0 - Sair\n 1 - Inserir no inicio\n 2 - Inserir no meio\n 3 - Inserir no final\n 4 - Inserir ordenado\n 5 - Remover\n 6 - Imprimir");
    printf("\n\nDigite uma opcao: ");
    scanf("%i",&op);
    
    switch(op){
        
        case 0: 
                return 0;
                break;
                
        case 1: 
                inserir_inicio(&lista);
                break;
            
        case 2:
                getchar();
                printf("\n\nDigite o valor de referencia: ");
                fgets(valor,50,stdin);
                
                inserir_meio(&lista,valor);
                break;
                
        case 3:
        
                inserir_final(&lista);
                break;
                
        case 4: 
        
        		inserir_ordenado(&lista);
				break;
                
        case 5:
        		
        		printf("\n\nDigite o id do no a ser removido: ");
        		scanf("%i",&id);
        		removido = remover(&lista,id);
        		
        		if(removido != NULL){
        			
        			printf("\n\nNo removido com sucesso: ");
        			
        			getPessoa(removido->p);
        			
        			free(removido
					);
        			
        			
				}else
					printf("\n\nFalha ao rmeover o no\n\n");
				
                break;
                
        case 6:
        	
				imprimir(lista);
	            break;
        	
        
   
    }
    
 }while(op != 0);
    
    
        return 0;
}

