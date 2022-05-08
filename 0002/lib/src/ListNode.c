#include "../inc/ListNode.h"
#include <stdio.h>
#include <stdlib.h>


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


void ListNode_print(const struct ListNode* const l)
{
    const struct ListNode* ite = l;
    while (ite != NULL)
    {
        printf("%d -> ", ite->val);
        ite = ite->next;
    }   
    printf("NULL\n");
}


struct ListNode* ListNode_fromArray(const int* const array, const unsigned len) 
{
    if (0 == len) return NULL;
    struct ListNode* root = ListNode_new(array[0]);
    struct ListNode* ite  = root;
    for (unsigned i = 1 ; i < len ; i++)
    {
        ite = ListNode_add(ite, array[i]); // insert and iterate
    }
    return root;
}
