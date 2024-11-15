#include "nodes.c"


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

    freeNodeRecursive(listHead);

    return 0;
}


