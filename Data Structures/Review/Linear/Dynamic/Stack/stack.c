// Simple stack in C
#include <stdio.h>
#include <stdlib.h>

// We need to create a node to build a stack
// each node must contain a place for data and a pointer to next node
typedef struct node
{
    int data;
    struct node * next;
} node;

// we need a node builder function!
// this function must build a node it must return with a pointer
node * create_node(int data){
    // create a node with size of my node struct!
    node * new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
// lets keep track of stack size as well.
int size = 0;


// pop an item from stack
node * pop(node ** top){
    if(top == NULL)
        return NULL; // null top address
    if((*top) == NULL){
        printf("Empty stack");
        return NULL;
    }   

    node * item = *top;
    *top = (*top)->next;
    size--;
    return item;
}   


// push an item into stack
int push(node ** top, node * new_node){
    if(new_node == NULL)
        return -2; // null push
    if(top == NULL)
        return -1; // null top

    new_node->next = *top;
    *top = new_node;
    size++;
    return 0;
}


// Lets iterate over our stack
int iterate_over_stack(node * stack){
    while(stack != NULL){
        int data = stack->data;
        printf("Stack data popped: %d\n", data);
        pop(&stack);
    }
}

// lets try our code
int main(void){

    node * stack = NULL;

    for(int i = 0; i < 10; i++)
        push(&stack, create_node(i));
    
    iterate_over_stack(stack);

    return 0;
}
