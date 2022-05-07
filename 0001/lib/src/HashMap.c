#include "../inc/HashMap.h"
#include <stdlib.h>
#include <stdio.h>


//*****************************
// PRIVATE FUNCTION DECLARATION
//*****************************


/**
 * @brief Hashing function for hash map.  
 *
 * @param hm    hash map for which we hash the key
 * @param key   key to hash
 *
 * @return  hashed key 
 */
static int HashMap_keygen(struct HashMap* hm, int key);


//*******************************
// PUBLIC FUNCTION IMPLEMENTATION
//*******************************


struct HashMap* HashMap_new(int length) {
    struct HashMap* hm = malloc(sizeof(struct HashMap));
    hm->length = length;
    hm->occupied = calloc(length, sizeof(int));
    hm->list = malloc(length * sizeof(struct Node*));
    return hm;
}


void HashMap_add(struct HashMap* hm, int key, int val) {
    int i = HashMap_keygen(hm, key);
    if (hm->occupied[i])
    {
        Node_add(hm->list[i], key, val);
    }
    else
    {
        struct Node* node = Node_new(key, val);
        hm->list[i] = node;
        hm->occupied[i] = 1;
    }
}


int HashMap_value(struct HashMap* hm, int key) {
    int i = HashMap_keygen(hm, key);

    if (hm->occupied[i])
    {
        struct Node* node = Node_seek(hm->list[i], key);
        if (node != NULL) return node->val;
    }

    return -1;
}


void HashMap_destruct(struct HashMap* hm) {
    for (int i = 0 ; i < hm->length ; i++)
        if (hm->occupied[i])
            Node_destruct(hm->list[i]);
    free(hm->list);
    free(hm->occupied);
    free(hm);
}


void HashMap_print(struct HashMap* hm) {
    for (int i = 0 ; i < hm->length ; i++)
        Node_print(hm->list[i]);
}


//*******************************
// PRIVATE FUNCTION IMPLEMENTATION
//*******************************


static int HashMap_keygen(struct HashMap* hm, int key) {
    int sign = 1;
    if (key < 0) sign = -1;
    return ((key * KNUTH_CONST) * sign) % hm->length;
}

