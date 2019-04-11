#include <stdlib.h>
#include <stdio.h>
#include "KindredSpirits.h"

// passing references
node *create_node(int data);

// returns 1 if trees are reflection, 0 otherwise
int isReflection(node *a, node *b)
{
    if (a == NULL && b == NULL)
    {
        // case of when both are NULL
        return 1;
    }
    if (a == NULL || b == NULL)
    {
        // case when one or the other is NULL
        return 0;
    }
    
    // recursive call of the function
    return isReflection(a->left, b->right) && isReflection(a->right, b->left);
}

// create a new tree which is a reflection of node passed
node *makeReflection(node *root)
{
    // base case for NULL pointer
    if (root == NULL){
        return NULL;
    }

    // make a node for non-NULL node (see above)
    node *newNode;
    newNode = create_node(root->data); // pass the given data from root node
    
    newNode->left  = makeReflection(root->right); // mirror right to left
    newNode->right = makeReflection(root->left);  // mirror left to right
}

//     Preorder traversal (recursive):
//         - visit the root node
//         - traverse the left subtree using preorder traversal
//         - traverse the right subtree using preorder traversal

// TODO: A stack for checking traversals?

// preorder algorithm traversal
void preorder(node *root)
{
    if (root = NULL)
        return;

    preorder(root->left);
    preorder(root->right);
    // push root data to stack HERE
}

// postorder algorithm traversal
void postorder(node *root)
{
    if (root = NULL)
        return;

    // push root->data to stack HERE
    return postorder(root->left) && postorder(root->right);
}

int kindredSpirits (node *a, node *b){
    // check if kindred spirits
    if (postorder())
}

double difficultyRating(void)
{
    return 1.0;
}

double hoursSpent(void)
{
    return 2.0;
}