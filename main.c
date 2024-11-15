#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE NODE;

struct NODE
{
    int number;
    NODE *next;
};


void freeNode(NODE* node){
    //ultimo node
    if(node != NULL){
        freeNode(node->next);
    } else{
        return;
    }
    printf("%p ", node);
    free(node);
}

void printList(NODE* listHead){
    
    printf("\n Lista Organizada: "  );

    for(NODE* current = listHead; current != NULL; current = current->next){
        
        printf(" < %d", current->number);
    

    }
    
}

void insertNode(NODE** listHead, NODE* newNode ){
    


    NODE **current;   
    // LISTA CONTEM MAIS DE UM ITEM
    // PERCORRE A LISTA PARA ENCONTRAR A POSIÇÃO
    for(current = listHead ; *current != NULL ; current = &((*current)->next) ){
        
        if( newNode->number < (* current)->number ){
            break;
        }
       
    }
        
        newNode->next = *current;
        *current = newNode;
        return;
}


int main(int argc, char *argv[])
{

    NODE* listHead = NULL;
    NODE* newNode = NULL;
    int number;
    

    printf("\n Lista original : ");

    // FOR DOS ARGUMENTOS
    for (int i = 1; i < argc ; i++)
    {
        number = atoi(argv[i]);

        printf(" %d :", number);
        
        newNode = malloc(sizeof(NODE));

        if(newNode == NULL){
            printf("erro alocação de memoria");
            return 1;
        }
        
        newNode->number = number;
        newNode->next = NULL;

        
        insertNode(&listHead,  newNode );

        //free(newNode);

                             
    }
   
    printf("\n ---------------------------------");
   
    printList(listHead);


    printf("\n ---------------------------------");
    printf("\n Liberando memoria:  ");

    freeNode(listHead);

    return 0;
}


