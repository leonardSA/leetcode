#ifndef _HASHMAP_H_ 
#define _HASHMAP_H_ 

#include "Node.h"


#define KNUTH_CONST (2654435769)


struct HashMap
{
    struct Node** list;
    int length; 
    int* occupied;
};


/**
 * @brief Instantiates a hash map.
 *
 * @param length    length of hash map member list 
 *
 * @return  new allocated hash map
 */
struct HashMap* HashMap_new(int length);


/**
 * @brief Add a new key-value pair to the hash map.
 *
 * @param hm    hash map for which we add a new pair
 * @param key   
 * @param val   
 */
void HashMap_add(struct HashMap* hm, int key, int val);


/**
 * @brief Find the value for the given key in the hash map.
 *
 * @param hm        searched hash map
 * @param key       searched key
 *
 * @return value for given key if found else -1
 */
int HashMap_value(struct HashMap* hm, int key);


/**
 * @brief Frees a hash map.
 *
 * @param hm   
 */
void HashMap_destruct(struct HashMap* hm);


/**
 * @brief Print a hash map.
 *
 * @param hm    hash map to print
 */
void HashMap_print(struct HashMap* hm);


#endif
