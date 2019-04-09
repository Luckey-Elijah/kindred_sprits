#include <stdlib.h>
#include <stdio.h>
#include "KindredSpirits.h"

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
    if (root == NULL){
        return NULL;
    }

    // node *newNode;
    node * newNode = create_node();
    
    newNode->left      = makeReflection(root->right);
    newNode->right     = makeReflection(root->left);
}

double difficultyRating(void)
{
    return 1.0;
}

double hoursSpent(void)
{
    return 1.0;
}