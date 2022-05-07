#ifndef _NODE_H_ 
#define _NODE_H_ 

struct Node 
{
    int key;
    int val;
    struct Node* next;
};


/**
 * @brief Instantiates a node.
 *
 * @param key   value of member key
 * @param val   value of member val
 *
 * @return  new allocated node
 */
struct Node* Node_new(int key, int val);


/**
 * @brief Frees a chain of nodes.
 *
 * @param node  first node of the chain
 */
void Node_destruct(struct Node* node);


/**
 * @brief Adds a node to a node.
 *
 * Adds a node to the last node of the chain
 * of nodes starting with the given node.
 *
 * @param node  first node
 * @param key   value of member key for new node
 * @param val   value of member val for new node
 */
void Node_add(struct Node* node, int key, int val);


/**
 * @brief Seeks a node with for the given key.
 *
 * Parses through the chain of nodes to find the node 
 * corresponding to the given key.
 *
 * @param node      first node of chain of node
 * @param key       key of node
 *
 * @return  node pointer if found else NULL
 */
struct Node* Node_seek(struct Node* node, int key);


/**
 * @brief Prints a chain of nodes.
 *
 * @param node  first node of the chain
 */
void Node_print(struct Node* node);


#endif
