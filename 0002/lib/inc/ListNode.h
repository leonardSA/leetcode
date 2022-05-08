#ifndef LIST_NODE
#define LIST_NODE

struct ListNode 
{
    int val;
    struct ListNode* next;
};


/**
 * @brief Instantiates a new ListNode.
 *
 * @param val value of ListNode.
 *
 * @return Instantiated ListNode.
 */
struct ListNode* ListNode_new(int val);


/**
 * @brief Adds a ListNode to a ListNode.
 *
 * @param l     set its next
 * @param val   value of next
 *
 * @return Pointer to instantiated ListNode.
 */
struct ListNode* ListNode_add(struct ListNode* l, int val);


/**
 * @brief Deallocates memory used by a ListNode.
 *
 * @param l 
 */
void ListNode_del(struct ListNode* l);


/**
 * @brief Prints a ListNode.
 *
 * @param l
 */
void ListNode_print(const struct ListNode* const l);


/**
 * @brief Takes an integer array and returns a ListNode.
 *
 * @param array integer array
 * @param len   length of the array
 *
 * @return pointer to newly allocated ListNode filled with passed array values.
 */
struct ListNode* ListNode_fromArray(const int* const array, const unsigned len);

#endif /* ifndef LIST_NODE */
