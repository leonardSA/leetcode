#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct ListNode 
{
    int val;
    struct ListNode* next;
};


/**
 * @brief Adds two ListNodes.
 *
 * @param l1 
 * @param l2
 *
 * @return Resulting ListNode.
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

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
void ListNode_print(struct ListNode* l);


int main()
{
    struct ListNode* l1 = ListNode_new(2);
    struct ListNode* l2 = ListNode_add(l1, 4);
    struct ListNode* l3 = ListNode_add(l2, 3);

    struct ListNode* r1 = ListNode_new(5);
    struct ListNode* r2 = ListNode_add(r1, 6);
    struct ListNode* r3 = ListNode_add(r2, 4);

    struct ListNode* res = addTwoNumbers(l1, r1);
    printf("  ");
    ListNode_print(l1); 
    printf("+ ");
    ListNode_print(r1); 
    printf("= ");
    ListNode_print(res);

    ListNode_del(l1);
    ListNode_del(r1);
    ListNode_del(res);

    return 0;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* result = ListNode_new(0);
    struct ListNode* node = result;
    int carry = 0;
    for(;;)
    {
        int l1_n = 0;
        int l2_n = 0;
        int x = 0;
        int y = 0;

        if (l1 != NULL)
        {
            x = l1->val;
            l1 = l1->next;
            l1_n = 1;
        }
        if (l2 != NULL)
        {
            y = l2->val;
            l2 = l2->next;
            l2_n = 1;
        }

        int sum = x + y + carry;
        if (sum == 0 && l1_n == 0 && l2_n == 0)
        {
            struct ListNode* res = result->next;
            free(result);
            return res;
        }

        if (sum > 9)
        {
            sum %= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        ListNode_add(node, sum);
        node = node->next;
    }
}


struct ListNode* ListNode_new(int val)
{
    struct ListNode* l = malloc(sizeof(struct ListNode));
    l->val = val;
    l->next = NULL;
    return l;
}


struct ListNode* ListNode_add(struct ListNode* l, int val)
{
    l->next = ListNode_new(val);
    return l->next;
}


void ListNode_del(struct ListNode* l)
{
    if (l->next != NULL)
        ListNode_del(l->next);
    free(l);
}


void ListNode_print(struct ListNode* l)
{
    struct ListNode* ite = l;
    while (ite != NULL)
    {
        printf("%d -> ", ite->val);
        ite = ite->next;
    }   
    printf("NULL\n");
}
