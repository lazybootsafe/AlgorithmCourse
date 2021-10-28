#ifndef __QUEUE__PH
#define __QUEUE__PH
#include <stdlib.h>
#include <string.h>
#include "../HeaderFile/ctlno.h"


struct Queue_node
{
    int client_fd;
    int ctl_no;
    struct Queue_node* next;
};

typedef struct
{
    int que_capacity;
    int que_size;
    struct Queue_node* head,*tail;
}que_t;

void que_init(que_t*,int);
void que_free(que_t*);
int que_push(que_t*,int client_fd,int ctl_no);
int que_pop(que_t*,struct Queue_node**);


#endif
