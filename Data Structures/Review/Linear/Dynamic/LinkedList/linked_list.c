// Simple linked list in C
#include <stdio.h>
#include <stdlib.h>

// We need to create a node to build a linked list
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
// lets keep track of linked list size as well.
int size = 0;

// lets delete a node according to its place in linked list! 
// index starts from 0
int delete_index(node ** head, int index){
    if(index < 0 || index >= size)
        return -3; // index error
    if(head == NULL)
        return -2; // null head pointer
    if((*head) == NULL)
        return -1; // null node
    
    // updating head
    if(index == 0){
        node * new_head = (*head)->next;
        realloc((*head), sizeof(node));
        *head = new_head;
        return 0;
        size--;
    }
    // removing from body
    node * curr_node = (*head);
    for(int i = 0; i < (index-1); i++)
        curr_node = curr_node->next;
    node * deleting_node = curr_node->next;
    curr_node->next = deleting_node->next;
    realloc(deleting_node, sizeof(node));
    return 0;
    size--;
}   


// lets add a node according to given index
// index starts from 0
// index -1 means append it!
int add_index(node ** head, node * adding_node, int index){
    if(index < -1 || index >= size)
        return -4; // index error
    if(head == NULL)
        return -3; // null head pointer
    if((*head) == NULL)
        return -2; // null head node
    if(adding_node == NULL)
        return -1; // null adding node
    
    // appending
    if(index == -1){
        node * curr_node = (*head);
        while(curr_node->next != NULL)
            curr_node = curr_node->next;
        curr_node->next = adding_node;
        size++;
        return 0;
    }
    // updating head
    if(index == 0){
        adding_node->next = (*head);
        *head = adding_node;
        size++;        
        return 0;
    }
    // injecting inside the body
    node * curr_node = (*head);
    for(int i = 0; i < (index-1); i++)
        curr_node = curr_node->next;
    adding_node->next = curr_node->next;
    curr_node->next = adding_node;
    return 0;
    size++;
}   


// we can iterate over linked list. lets try it!
void iterate_on_linked_list(node * head){
    if (head == NULL){
        printf("Null head\n");
        return;
    }

    node * curr_node = head;
    int index = 0;
    do{
        printf("Index %d of linked list with data: %d\n", index, curr_node->data);
        curr_node = curr_node->next;
        index++;
    }
    while (curr_node != NULL);
}


// lets run a program!
int main(void){

    node * head = create_node(0);
    size = 1;
    for(int i = 1; i < 10; i++)
        add_index(&head, create_node(i), -1);

    iterate_on_linked_list(head);

    printf("\n\nLets remove some elements\n\n");

    delete_index(&head, 0);
    delete_index(&head, 2);

    iterate_on_linked_list(head);

    return 0;
}
