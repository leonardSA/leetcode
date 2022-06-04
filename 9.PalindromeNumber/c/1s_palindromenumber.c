#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 * @brief Checks if an integer is a palindrome.
 *
 * @param x 
 *
 * @return true if is a palindrome else false
 */
bool isPalindrome(int x);


/**
 * @brief Returns a reverse list of an int.
 *
 * Allocates a list of integers and adds digits 
 * of x in reverse order.
 *
 * Note: allocates by multiple of 2 as realloc 
 * is a heavy function.
 *
 * @param x     integer to convert as list
 * @param size  size of list
 *
 * @return list of digits in reverse order
 */
int* nb_aslist(int x, int* size);


int main()
{
    int test = 121;
    if (isPalindrome(test))
        printf("%d is a palindrome\n", test);
    else
        printf("%d is not a palindrome\n", test);
    return 0;
}


bool isPalindrome(int x)
{   
    if (x < 0)
        return false;

    int size = 0;
    int* list = nb_aslist(x, &size);

    int low = 0;
    int high = size - 1;
    while (high > low)
    {
        if (list[high] != list[low])
        {
            free(list);
            return false;
        }

        ++low;
        --high;
    }

    free(list);

    return true;
}


int* nb_aslist(int x, int *size)
{
    *size = 0;
    int* list = NULL;

    if (x == 0)
    {
        list = malloc(sizeof(int));
        list[0] = 0;
        *size = 1;
        return list; 
    }

    int n = x;
    int v_size = 1;
    while (n > 0)
    {
        n /= 10;
        ++(*size);
        if (*size >= v_size)
        {
            v_size *= 2;
            list = realloc(list, v_size * sizeof(int));
        }
        list[*size - 1] = x - n * 10;
        x = n;
    }

    return list;
}
