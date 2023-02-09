// Simple binary tree in C
#include <stdio.h>
#include <stdlib.h>

// We need to create a node to build a binary tree!
// each node must contain a place for data and two pointer to left and right childs
typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
} node;

// we need a node builder function!
// this function must build a node it must return with a pointer
node * create_node(int data){
    // create a node with size of my node struct!
    node * new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
// lets keep track of binary tree size as well.
int size = 0;


// lets build a tree using recursion!
// I will talk about recursion in Review Algorithms!
void build_tree_level(node * parent, int level){
    if(level <= 0)
        return; // end of tree
    if(parent == NULL)
        return; // null parent
    node * left = create_node(0);
    node * right = create_node(1);
    parent->left = left;
    parent->right = right;
    level--;
    build_tree_level(left, level);
    build_tree_level(right, level);
}

// TODO: insert, update, delete of a binary tree can vary
// according to the type of binary tree or the abstract DS
// used to build a tree!
// I will cover this in next chapter!

// I will print this tree using a recursive bfs!
// I will cover bfs in algorithms section!

// here is process of level
void process_level(node * parent, int level){
    if(parent == NULL)
        return;
    
    if(level == 0){
        printf("%d ", parent->data);
    }else{
        process_level(parent->left, level - 1);
        process_level(parent->right, level - 1);
    }
}
// here is printer which is a level order traversal!
void print_level_order(node * parent, int height){
    if(parent == NULL)
        return;
    for(int i = 0; i < height; i++){
        process_level(parent, i);
        printf("\n");
    }
}

// lets see our tree!
int main(void){

    int height = 4;
    node * root = create_node(0);
    build_tree_level(root, height - 1);
    print_level_order(root, height);

    return 0;
}
