#include <stdio.h>
#include <stdlib.h>

typedef struct DouList
{
    struct DouList *nextlist;
    struct DouList *lastlist;
    int data;
}DList;

void printflist(DList *list)
{
    // printf("%d\t",list->data);
    while(list->nextlist != NULL)
    {
        printf("%d\t",list->data);
        list = list->nextlist;
    }
    printf("%d\t",list->data);
    printf("\n");
}

DList *DlistCrate(void)
{
    DList *dlist = NULL;
    dlist = (DList *)malloc(sizeof(DList));
    dlist->lastlist = NULL;
    dlist->nextlist = NULL;
    dlist->data = 0;
    return dlist;
}

DList *DlistHeadIn(DList *list, int data)
{
    DList *dlist = NULL;
    dlist = (DList *)malloc(sizeof(DList));
    dlist->lastlist = NULL;
    dlist->nextlist == NULL;
    dlist->data = data;
    
    dlist->nextlist = list;
    
    list->lastlist = dlist;

    return dlist;
}

DList *DlistTailIn(DList *list, int data)
{
    DList *dlist = NULL;
    DList *prelist = NULL;
    dlist = (DList *)malloc(sizeof(DList));
    dlist->lastlist = NULL;
    dlist->nextlist = NULL;
    dlist->data = data;

    prelist = list;
    
    while(prelist->nextlist != NULL)
    {
        prelist = prelist->nextlist;
    }
    prelist->nextlist = dlist;
    dlist->lastlist = prelist;
    
    return list;
}

DList *DlistDel(DList *list, int data)
{
    DList *prelist = NULL;
    prelist = list;
    if(prelist->data == data)
    {
        list = prelist->nextlist;
        list->lastlist = NULL;
        free(prelist);
        return list;
    }
    while(prelist->nextlist != NULL)
    {
        if(prelist->data == data)
        {
            prelist->lastlist->nextlist = prelist->nextlist;
            prelist->nextlist->lastlist = prelist->lastlist;
            free(prelist);
            break;
        }
        prelist = prelist->nextlist;
    }
    return list;
}
 
int main(void)
{
    DList *mylist = NULL;
    mylist = DlistCrate();
    mylist = DlistHeadIn(mylist, 1);
    mylist = DlistHeadIn(mylist, 2);
    mylist = DlistHeadIn(mylist, 3);
    mylist = DlistTailIn(mylist, 1);
    printflist(mylist);
    mylist = DlistDel(mylist, 2);
    printflist(mylist);
    return 0;
}