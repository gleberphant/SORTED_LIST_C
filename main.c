#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE NODE;

struct NODE
{
    int number;
    NODE *next;
};


/* Função que libera a memoria alocada dinamicamente
  * 
 */
void freeNode(NODE* node){
    
    // quando for o ultimo no retorna sem fazer nada   
    if(node == NULL) return;

    // chama o proximo n
    freeNode(node->next);
    
    // quando retornar da função que liberou o proximo libera o nó
    printf("*%d ", node->number);
    free(node);
}

/* Função que imprime uma lista
 * 
 */
void printList(NODE* listHead){
    
    printf("\n Lista Organizada: "  );

    for(NODE* current = listHead; current != NULL; current = current->next){
        printf(" < %d", current->number);
    }
    
}

/* Função que percorre a lista e insere o novo nó na posição correta
 * recebe um ponteiro para o listHead e o novo Nó
 * 
 */
void insertNode(NODE** listHead, NODE* newNode ){
   
    NODE **current;   

    // PERCORRE A LISTA PARA ENCONTRAR A POSIÇÃO CORRETA
    for(current = listHead ; *current != NULL ; current = &(*current)->next ){
        // quando o novo nó for menor que o nó  atual,  quebra o laço
        if( newNode->number < (*current)->number ){
            break;
        }       
        // se o novo nó for maior que o nó atual então avança a lista
    }
    // define que nó seguinte do novo nó é o da posição atual
    newNode->next = *current;

    // define que a posição atual agora passa a ser o novo nó
    *current = newNode;

    // finaliza a função
    return;
}


int main(int argc, char *argv[])
{

    NODE* listHead = NULL;
    NODE* newNode = NULL;
        
    printf("\n Lista original : ");

    // PARA cada numero passado como argumento cria um novo nó e insere na lista
    for (int i = 1; i < argc ; i++)
    {
        newNode = malloc(sizeof(NODE));

        if(newNode == NULL){
            printf("erro alocação de memoria");
            return 1;
        }
        
        newNode->number = atoi(argv[i]);
        newNode->next = NULL;
        
        printf(" %d :", newNode->number);
        
        insertNode(&listHead,  newNode );
                             
    }
   
    printf("\n ---------------------------------");
   
    printList(listHead);

    printf("\n ---------------------------------");
    printf("\n Liberando memoria:  ");

    freeNode(listHead);

    return 0;
}


