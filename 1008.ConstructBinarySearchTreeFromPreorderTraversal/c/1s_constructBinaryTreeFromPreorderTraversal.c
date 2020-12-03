#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode* new(int val);

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize);

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};




int main(void) {
    int preorder[6] = {8,5,1,7,10,12};
    int preorderSize = 6;
    bstFromPreorder(preorder, preorderSize);
    return 0;
}

struct TreeNode* new(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* tree(int* preorder, int preorderSize, int* index, 
        int min, int max) {
    if (*index >= preorderSize)
        return NULL;
    if (preorder[*index] < min || preorder[*index] > max)
        return NULL;

    struct TreeNode* node = new(preorder[*index]); 
    *index = *index + 1;

    node->left = tree(preorder, preorderSize, index, min, node->val);
    node->right = tree(preorder, preorderSize, index, node->val, max);

    return node;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    if (preorderSize == 0)
        return NULL;
    int index = 0;
    return tree(preorder, preorderSize, &index, INT_MIN, INT_MAX);
}
