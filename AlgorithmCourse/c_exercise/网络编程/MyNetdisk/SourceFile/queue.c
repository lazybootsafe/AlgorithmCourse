#include "../HeaderFile/queue.h"

void que_init(que_t* p_queue,int queue_capacity)
{
    p_queue->que_capacity = queue_capacity;
    p_queue->head = NULL;
    p_queue->tail = NULL;
    p_queue->que_size = 0;
}

int que_push(que_t* p_queue,int client_fd,int ctl_no)
{
    if(p_queue->que_size == p_queue->que_capacity)
        return -1;
    struct Queue_node* new_node = (struct Queue_node*)malloc(sizeof(struct Queue_node));
    memset(new_node,0,sizeof(struct Queue_node));
    new_node->client_fd = client_fd;
    new_node->ctl_no = ctl_no;
    if(p_queue->que_size == 0)
    {
        p_queue->head = new_node;
        p_queue->tail = new_node;
    }
    else
    {
        p_queue->tail->next = new_node;
        p_queue->tail = new_node;
    }
    p_queue->que_size++;
    return 0;
}

int que_pop(que_t* p_queue,struct Queue_node** pop_node)
{
    if(p_queue->que_size == 0)
        return -1;
    *pop_node = p_queue->head;
    p_queue->head = p_queue->head->next;
    p_queue->que_size--;
    return 0;
}

void que_free(que_t* p_queue)
{
    if(p_queue->que_size == 0)
        return;
    for(int i = 0;i < p_queue->que_size; ++i)
    {
        struct Queue_node* node = p_queue->head;
        p_queue->head = p_queue->head->next;
        free(node);
    }
    p_queue->head = p_queue->tail = NULL;
    p_queue->que_size = 0;
}

