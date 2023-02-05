// Simple queue in C
#include <stdio.h>
#include <stdlib.h>

// We need to create a node to build a queue
// each node must contain a place for data and a pointer to next node
typedef struct node
{
    int data;
    struct node * next;
} node;

// Saving pointers of queue here
typedef struct queue
{
    node * head;
    node * tail;
} queue;


// we need a node builder function!
// this function must build a node it must return with a pointer
node * create_node(int data){
    // create a node with size of my node struct!
    node * new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
// lets keep track of queue size as well.
int size = 0;


// pop an item from queue
node * pop(queue * q){
    if(q == NULL)
        return NULL; // null q
    if(q->head == NULL)
        return NULL; // null queue
    
    node * item = q->head;
    if(size == 1){
        q->tail = NULL;
        q->head = NULL;
    }else{
        q->head = item->next;
    }
    size--;
    return item;
}   


// push an item into queue
int push(queue * q, node * new_node){
    if(new_node == NULL)
        return -2; // null node
    if(q == NULL)
        return -1; // null q

    if(size == 0){
        q->head = new_node;
        q->tail = new_node;
    }else{
        q->tail->next = new_node;
        q->tail = new_node;
    }
    size++;
    return 0;
}


// Lets iterate over our queue
int iterate_over_queue(queue * q){
    if(q == NULL)
        return -1; // null queue
    while (q->head != NULL)
    {
        int data = q->head->data;
        printf("Data of queue popped: %d\n", data);
        pop(q);
    }
}

// lets try our code
int main(void){

    queue * q = (queue *) malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;

    for(int i = 0; i < 10; i++)
        push(q, create_node(i));
    
    iterate_over_queue(q);

    return 0;
}
