#include "../inc/Node.h"
#include <stdlib.h>
#include <stdio.h>


//*******************************
// PUBLIC FUNCTION IMPLEMENTATION
//*******************************


struct Node* Node_new(int key, int val) {
    struct Node* node = malloc(sizeof(struct Node));
    node->key  = key;
    node->val  = val;
    node->next = NULL;
    return node;
}


void Node_add(struct Node* node, int key, int val) {
    struct Node* n        = node;
    struct Node* new_node = Node_new(key, val);
    while (n->next != NULL) n = n->next;
    n->next = new_node;
}


struct Node* Node_seek(struct Node* node, int key) {
    struct Node* n = node;
    while (n != NULL) 
    {
        if (key == n->key) return n;
        n = n->next;
    }
    return n;
}


void Node_destruct(struct Node* node) {
    struct Node* n1 = node;
    struct Node* n2 = node->next;
    while (n2 != NULL)
    {
       free(n1);
       n1 = n2;
       n2 = n2->next;
    }
    free(n1);
}


void Node_print(struct Node* node) {
    struct Node* n = node;
    while (n != NULL)
    {
        printf("%d : %d -> ", n->key, n->val);
        n = n->next;
    }
    printf("NULL\n");
}
