#include <stdlib.h>
#include <stdio.h>
#include "KindredSpirits.h"

// passing references
node *create_node(int data)
{
	node *n = malloc(sizeof(node));

	n->data = data;
	n->left = n->right = NULL;

	return n;
}

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
// TODO: A stack for checking traversals?

// preorder algorithm traversal
void preorder(node *root)
{
    // if (root = NULL)
    //     {return NULL;}

    preorder(root->left);
    preorder(root->right);
    printf("%d ", root->data);
    // push root data to stack HERE
}

// postorder algorithm traversal
void postorder(node *root)
{
    // if (root = NULL)
    //     {return NULL;}
    
    printf("%d ", root->data);
    postorder(root->left);
    postorder(root->right); 
}

typedef struct kindred_spirit
{
    int pre_data;  // current value at PREorder traversal of node A
    int post_data; // current value at POSTorder traversal of node B
    //ony used in 
}kindred_spirit;

int pre_post_traversal(node *a, node *b){
    // return 0 -> a&b same
    // return 1 -> a&b not same
    return 0;
}


// a KindredSpirit is when a trees preorder trav is the same
// as the postoreder traversal
int kindredSpirits(node *a, node *b){

    printf("POSTORDER A: \n");
    postorder(a);

    printf("PREORDER B: \n");
    preorder(b);

    printf("Kindred Spirit Test: \n");
    printf("%d ", pre_post_traversal(a, b));

    return 0;
}

double difficultyRating(void)
{
    return 1.0;
}

double hoursSpent(void)
{
    return 2.0;
}