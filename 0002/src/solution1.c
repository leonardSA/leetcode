#include <stdio.h>
#include <stdlib.h>
#include "../../lib/inc/libArgumentArray.h"
#include "../lib/inc/ListNode.h"
#include "../lib/inc/usage.h"


/**
 * @brief Adds two ListNodes.
 *
 * @param l1 
 * @param l2
 *
 * @return Resulting ListNode.
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);


int main(int argc, char* argv[])
{
    if (3 > argc)
    {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    struct ArgumentArray* arg1 = ArgumentArray_new(sizeof(int));
    const int* input1 = ArgumentArray_toIntArray(arg1, argv[1]);
    const size_t len1 = ArgumentArray_len(arg1);

    struct ArgumentArray* arg2 = ArgumentArray_new(sizeof(int));
    const int* input2 = ArgumentArray_toIntArray(arg2, argv[2]);
    const size_t len2 = ArgumentArray_len(arg2);

    struct ListNode* x = ListNode_fromArray(input1, len1);
    struct ListNode* y = ListNode_fromArray(input2, len2);
    struct ListNode* r = addTwoNumbers(x, y);
    
    printf("  ");
    ListNode_print(x); 
    printf("+ ");
    ListNode_print(y); 
    printf("= ");
    ListNode_print(r);

    ArgumentArray_free(arg1);
    ArgumentArray_free(arg2);

    ListNode_del(x);
    ListNode_del(y);
    ListNode_del(r);

    return EXIT_SUCCESS;
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
