#include <stdio.h>
#include <stdlib.h>


#include "nodes.h"


/* Função que libera a memoria alocada dinamicamente
  * 
 */
void freeNodeRecursive(NODE* node){
    
    // quando for o ultimo no retorna sem fazer nada   
    if(node == NULL) return;

    // chama o proximo n
    freeNodeRecursive(node->next);
    
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
   
    NODE **current = NULL, **previous = NULL;

    // PERCORRE A LISTA PARA ENCONTRAR A POSIÇÃO CORRETA
    for(current = listHead ; (*current) != NULL ; current = &(*current)->next ){
        // quando o novo nó for menor que o nó  atual,  quebra o laço
        if( newNode->number < (*current)->number ){
            break;
        }       
        // se o novo nó for maior que o nó atual então avança a lista
        previous = current;
    }
    
    // Se previous for null então insere na cabeça senão insere no meio do corpo 
    if(previous == NULL){
        newNode->next = *listHead; 
        *listHead = newNode;
    } 
    else{
        newNode->next = *current;
        (*previous)->next = newNode;
        
    }
    
    
    
    // finaliza a função
    return;
}