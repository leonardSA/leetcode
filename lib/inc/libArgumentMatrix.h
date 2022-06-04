#ifndef _ARGUMENT_MATRIX_H_
#define _ARGUMENT_MATRIX_H_

#include "./libArgumentArray.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MATRIX_OPEN_TOKEN        ('[')
#define MATRIX_CLOSE_TOKEN       (']')
#define MATRIX_INITIAL_CAPACITY  (1 << 5)

/**
 * @brief Struct ArgumentArray to store an array passed as command line argument.
 */
struct ArgumentMatrix {
    void** matrix;                  //!< Matrix  
    struct ArgumentArray** array;   //!< Array of Arrays
    size_t size;                    //!< Number of rows
    size_t capacity;                //!< Capacity of array
    size_t typeSize;                //!< Size of matrix data type
};


/**
 * @brief Initialize ArgumentMatrix.
 *
 * Allocates memory. Be sure to free using provided function ArgumentMatrix_free.
 *
 * @param typeSize  size of type of array
 *
 * @return pointer to newly allocated ArgumentMatrix
 */
struct ArgumentMatrix* ArgumentMatrix_new(const size_t typeSize);


/**
 * @brief Frees ArgumentMatrix structure.
 *
 * @param argMatrix
 */
void ArgumentMatrix_free(struct ArgumentMatrix* argMatrix);


/**
 * @brief Returns number of rows in matrix.
 *
 * @param argMatrix
 *
 * @return number of rows in matrix
 */
const size_t ArgumentMatrix_rows(struct ArgumentMatrix* argMatrix);


/**
 * @brief Returns number of cols per row in matrix.
 *
 * Allocates array. User must free.
 *
 * @param argMatrix
 *
 * @return number of cols per row in matrix
 */
int* ArgumentMatrix_cols(struct ArgumentMatrix* argMatrix);


/**
 * @brief Converts matrix of int as string to array of int stored in ArgumentMatrix.
 *
 * @param argMatrix  structure to store array
 * @param string     matrix of int as string (format: [[1,2,3],[4,5,6,7]...])
 *
 * @return pointer to array of ArgumentMatrix
 */
int** ArgumentMatrix_toIntMatrix(struct ArgumentMatrix* argMatrix, char* string);


#endif
