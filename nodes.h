#ifndef NODES_HEADER
#define NODES_HEADER


typedef struct NODE NODE;

struct NODE
{
    int number;
    NODE *next;
};

void freeNodeRecursive(NODE* node);

void printList(NODE* listHead);

void insertNode(NODE** listHead, NODE* newNode );

#endif