#include "../inc/libArgumentArray.h"

//*****************************
// PRIVATE FUNCTION DECLARATION
//*****************************

/**
 * @brief Reallocates more capacity for the array.
 *
 * @param argArray
 */
static void ArgumentArray_resize(struct ArgumentArray* argArray);


//*******************************
// PUBLIC FUNCTION IMPLEMENTATION
//*******************************

int* ArgumentArray_toIntArray(struct ArgumentArray* argArray, char* string) {
    assert(ARRAY_OPEN_TOKEN  == string[0]                   && "Input array: wrong format");
    assert(ARRAY_CLOSE_TOKEN == string[strlen(string) - 1]  && "Input array: wrong format");

    string[0]                  = ' ';  // remove ARRAY_OPEN_TOKEN
    string[strlen(string) - 1] = ' ';  // remove ARRAY_CLOSE_TOKEN

    // skip blanks
    bool blank = true;      
    for (unsigned i = 0U ; i < strlen(string) - 1U ; i++) { blank &= isblank(string[i]); }
    if  (blank) return NULL;

    char* context = NULL;
    for (
            char* token = strtok_r(string, ARRAY_DELIMITER_TOKEN, &context) ; 
            NULL != token ; 
            token = strtok_r(NULL, ARRAY_DELIMITER_TOKEN, &context)
        )
    {
        if (argArray->capacity <= argArray->size) { ArgumentArray_resize(argArray); } // increase capacity
        ((int*) argArray->array)[argArray->size++] = atoi(token);                     // insert and increment size
    }

    return ((int*) argArray->array);
}


struct ArgumentArray* ArgumentArray_new(const size_t typeSize) {
    struct ArgumentArray* argArray = (struct ArgumentArray*) malloc(sizeof(struct ArgumentArray));
    assert(argArray && "Allocation of ArgumentArray failed");
    argArray->array    = (void*) malloc(typeSize * ARRAY_INITIAL_CAPACITY);
    argArray->size     = 0U;
    argArray->capacity = ARRAY_INITIAL_CAPACITY;
    argArray->typeSize = typeSize;
    return argArray;
}


void ArgumentArray_free(struct ArgumentArray* argArray) {
    free(argArray->array);
    free(argArray);
}


const size_t ArgumentArray_len(struct ArgumentArray* argArray) {
    return argArray->size;
}


//*******************************
// PRIVATE FUNCTION IMPLEMENTATION
//*******************************

static void ArgumentArray_resize(struct ArgumentArray* argArray) {
    argArray->capacity <<= 1;
    argArray->array = realloc(argArray->array, argArray->typeSize * argArray->capacity);
    //  capacity is never 0 hence never null ptr
    assert(argArray->array && "Reallocation of ArgumentArray->array failed"); 
}
