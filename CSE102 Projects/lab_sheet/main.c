#include <stdio.h>
#include <stdlib.h>

#define SENT -1

typedef struct list_node_s {
    int digit;
    struct list_node_s *restp;
} list_note_t;

// recursive print list
void print_list(list_note_t *headp)
{
    if(headp == NULL)
        printf("\n");
    else
    {
        printf("%d",headp->digit);
        print_list(headp->restp);
    }
}

//iterative print list
void print_list(list_note_t *headp)
{
    list_note_t *cur_nodep;
    for (cur_nodep = headp; cur_nodep != NULL; cur_nodep = cur_nodep->restp)
    {
        printf("%d", cur_nodep->digit);
    }
    printf("\n");
}

//creating a list while taking inputs from user
list_note_t * get_list(void)
{
    int data;
    list_note_t *ansp;

    scanf("%d",&data);
    if(data == SENT) {
        ansp = NULL;
    }
    else
    {
        ansp = (list_note_t *)malloc(sizeof(list_note_t));
        ansp->digit = data;
        ansp->restp = get_list();
    }

    return (ansp);
}

int main(){

    
    return 0;
}