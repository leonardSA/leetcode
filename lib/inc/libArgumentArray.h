#ifndef _ARGUMENT_ARRAY_H_
#define _ARGUMENT_ARRAY_H_

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>

#define ARRAY_OPEN_TOKEN        ('[')
#define ARRAY_CLOSE_TOKEN       (']')
#define ARRAY_DELIMITER_TOKEN   (",")
#define ARRAY_INITIAL_CAPACITY  (1 << 5)


/**
 * @brief Struct ArgumentArray to store an array passed as command line argument.
 */
struct ArgumentArray {
    void*  array;       //!< Array of any type 
    size_t size;        //!< Size of array
    size_t capacity;    //!< Capacity of array
    size_t typeSize;    //!< Size of type of array
};


/**
 * @brief Initialize ArgumentArray.
 *
 * Allocates memory. Be sure to free using provided function ArgumentArray_free.
 *
 * @param typeSize  size of type of array
 *
 * @return pointer to newly allocated ArgumentArray
 */
struct ArgumentArray* ArgumentArray_new(const size_t typeSize);


/**
 * @brief Frees ArgumentArray structure.
 *
 * @param argArray
 */
void ArgumentArray_free(struct ArgumentArray* argArray);


/**
 * @brief Returns number of elements in array.
 *
 * @param argArray
 *
 * @return length of array.
 */
const size_t ArgumentArray_len(struct ArgumentArray* argArray);


/**
 * @brief Converts array of int as string to array of int stored in ArgumentArray.
 *
 * @param argArray  structure to store array
 * @param string    array of int as string (format: [1,2,3...])
 *
 * @return pointer to array of ArgumentArray
 */
int* ArgumentArray_toIntArray(struct ArgumentArray* argArray, char* string);


#endif
