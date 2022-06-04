#include "../inc/libArgumentMatrix.h"

//*****************************
// PRIVATE FUNCTION DECLARATION
//*****************************


/**
 * @brief Reallocates more capacity for the matrix.
 *
 * @param argMatrix
 */
static void ArgumentMatrix_resize(struct ArgumentMatrix* argMatrix);


//*******************************
// PUBLIC FUNCTION IMPLEMENTATION
//*******************************

int** ArgumentMatrix_toIntMatrix(struct ArgumentMatrix* argMatrix, char* string)
{
    assert(MATRIX_OPEN_TOKEN  == string[0]                   && "Input array: wrong format");
    assert(MATRIX_CLOSE_TOKEN == string[strlen(string) - 1]  && "Input array: wrong format");

    string[0]                  = ' ';  // remove MATRIX_OPEN_TOKEN
    string[strlen(string) - 1] = ' ';  // remove MATRIX_CLOSE_TOKEN

    // tokenize the matrix input into arrays [[1],[2]] => [1] [2] 
    // pass the arrays to ArgumentArray
    char* token = strchr(string, MATRIX_OPEN_TOKEN);
    while (token)
    {
        char* close = strchr(token, MATRIX_CLOSE_TOKEN) + 1U; // look for the end of the array
        *close = '\0';                                        // close the string

        // parse token and insert argArray
        if (argMatrix->capacity <= argMatrix->size) { ArgumentMatrix_resize(argMatrix); } 

        struct ArgumentArray* argArray      = ArgumentArray_new(argMatrix->typeSize);     
        argMatrix->matrix[argMatrix->size]  = (int*) ArgumentArray_toIntArray(argArray, token);     
        argMatrix->array[argMatrix->size++] = argArray;                                   
         
        *close = MATRIX_CLOSE_TOKEN;                          // reset the string
        token = strchr(close, MATRIX_OPEN_TOKEN);             // look for beginning of the array 
    }

    return ((int**) argMatrix->matrix);
}


struct ArgumentMatrix* ArgumentMatrix_new(const size_t typeSize)
{
    struct ArgumentMatrix* argMatrix = (struct ArgumentMatrix*) malloc(sizeof(struct ArgumentMatrix));
    assert(argMatrix && "Allocation of ArgumentMatrix failed");
    argMatrix->matrix   = (void**) malloc(sizeof(void*) * MATRIX_INITIAL_CAPACITY);
    argMatrix->array    = (struct ArgumentArray**) malloc(sizeof(struct ArgumentArray*) * MATRIX_INITIAL_CAPACITY);
    argMatrix->size     = 0U;
    argMatrix->capacity = ARRAY_INITIAL_CAPACITY;
    argMatrix->typeSize = typeSize;
    return argMatrix;
}


void ArgumentMatrix_free(struct ArgumentMatrix* argMatrix)
{
    // loop side effect => frees matrix[i]
    for (unsigned i = 0U ; i < argMatrix->size ; i++) { ArgumentArray_free(argMatrix->array[i]); }
    free(argMatrix->matrix);
}


const size_t ArgumentMatrix_rows(struct ArgumentMatrix* argMatrix)
{
    return argMatrix->size;
}


int* ArgumentMatrix_cols(struct ArgumentMatrix* argMatrix)
{
    int* cols = (int*) malloc(sizeof(int) * argMatrix->size);
    for (unsigned i = 0U ; i < argMatrix->size ; i++)
    {
        cols[i] = argMatrix->array[i]->size;
    }
    return cols;
}


//*******************************
// PRIVATE FUNCTION IMPLEMENTATION
//*******************************


static void ArgumentMatrix_resize(struct ArgumentMatrix* argMatrix) 
{
    argMatrix->capacity <<= 1;
    argMatrix->matrix = (void**) realloc(argMatrix->matrix, argMatrix->typeSize * argMatrix->capacity);
    argMatrix->array  = (struct ArgumentArray**) realloc(argMatrix->array, 
                        sizeof(struct ArgumentArray*) * argMatrix->capacity);
    //  capacity is never 0 hence never null ptr
    assert(argMatrix->matrix && "Reallocation of ArgumentArray->array failed"); 
}
