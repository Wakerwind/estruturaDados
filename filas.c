

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    
    char nome[50];
    int idade;
    
}Pessoa;

typedef struct no{
    
    Pessoa pessoa;
    struct no *proximo;
    
    
}No;

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

void imprime_fila(No *fila){
    
    No *aux = fila;
    
    printf("\n\n--------Fila--------\n\n");
    
    if(aux != NULL){
        
        while(aux != NULL){
        
            getPessoa(aux->pessoa);
            aux = aux->proximo;
        
        }
        
    }else
        printf("\n\nFila Vazia!");
    
    
    
    printf("\n\n--------Fim da fila--------\n\n");
    
}

void inserir_no(No **fila){
    
    No *aux, *novo = malloc(sizeof(No));
    
    if(novo != NULL){
        
        novo->pessoa = setPessoa();
        novo->proximo = NULL;
        
        if(*fila == NULL){
            
            *fila = novo;
            printf("\n\nNo inserido com sucesso!\n\n");
        }else{
            
            aux = *fila;
            
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            
            aux->proximo = novo;
            printf("\n\nNo inserido com sucesso!\n\n");
        }
        
    }else{
        printf("\n\nFalha ao alocar memoria!");
    }
    
}

No* remover_no(No **fila){
    
    if(*fila != NULL){
    
    No *remover = *fila;
    
    *fila = remover->proximo;
    
    return remover;
    
    }else{
        
        return NULL;
    }
}

void limpar(No **fila){
    
    No *remover;
    No *aux = *fila;
   
    if(*fila){
        
        while(*fila != NULL){
            remover = remover_no(fila);
            free(remover);
            aux = aux->proximo;
        }
        
        printf("\n\nFilha Limpa com sucesso!\n\n");
    }else{
        printf("\n\nFila vazia!\n\n");
    }
    
    
}


   
int main()
{
    No *remover;
    No *fila = NULL;
    int op;
    
    
    
    do{
        
    printf("0 - sair\n1 - Inserir no\n2 - Remover no\n3 - Imprimir\n4 - limpar\n");
    
    printf("\nDigite a opcao: ");
    scanf("%i",&op);
    
    switch(op){
        
        case 0: 
                return 0;
                break;
        
        case 1: 
                
                inserir_no(&fila);
                break;
                
        case 2: 
                
                remover = remover_no(&fila);
                
                if(remover){
                
                printf("\n\nNo removido com sucesso!\n\n");
                getPessoa(remover->pessoa);
                free(remover);
                }else{
                    printf("\n\nFila vazia!\n\n");
                }
               
                break;
                
        case 3: 
                imprime_fila(fila);
                break;
                
        case 4: 
                limpar(&fila);
                break;
                
        default:
            printf("\nOpcao invalida!");
        
        
        
    }
    
    }while(op != 0);

    return 0;
}
