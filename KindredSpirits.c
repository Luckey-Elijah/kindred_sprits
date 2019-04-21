#include <stdlib.h>
#include <stdio.h>
#include "KindredSpirits.h"

typedef struct kindred_spirit
{
    int *pre_data;  // current value at PREorder traversal of node A
    int *post_data; 
}kindred_spirit;

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

    return newNode;
}
// TODO: A stack for checking traversals?

// preorder algorithm traversal
int *preorder(node *root, int *pre_a, int counter)
{
    if (root == NULL)
        {return NULL;}
    preorder(root->left, pre_a, counter++);
    preorder(root->right, pre_a, counter++);
    printf("[%d]=%d ",counter, root->data);
    pre_a[counter] = root->data;
    return pre_a;
}

// postorder algorithm traversal
int *postorder(node *root, int *post_a, int counter)
{
    if (root == NULL)
        {return NULL;}
    
    printf("[%d]=%d ",counter, root->data);
    post_a[counter] = root->data;
    postorder(root->left, post_a, counter++);
    postorder(root->right, post_a, counter++);

    return post_a;
}

// a KindredSpirit is when a trees preorder trav is the same
// as the postoreder traversal
int kindredSpirits(node *a, node *b){

    int counter = 0;
    int *pre_a;
    int *post_a;

    post_a = postorder(a, post_a, counter);
    printf("\n");
    pre_a = preorder(b, pre_a, counter);
    printf("\n");

    printf("PRE-Order: ");
    int i;
    for(i = 0; i < ((sizeof(pre_a))/(sizeof(int))); i++){
        printf("%d ", pre_a[i]);
    } printf("\n");

    printf("POST-Order: ");
    for(i = 0; i < ((sizeof(post_a))/(sizeof(int))); i++){
        printf("%d ", post_a[i]);
    } printf("\n");

    return 0;
}

// int main(int argc, char const *argv[])
// {
//     node *root1, *root2;

// 	// These are the trees from Figure 9 in the assignment PDF, used for testing
// 	// the kindredSpirits function.
// 	root1 = create_node(23);
// 	root1->left = create_node(12);
// 	root1->left->left = create_node(5);
// 	root1->left->right = create_node(18);
// 	root1->right = create_node(71);
// 	root1->right->right = create_node(56);

// 	root2 = create_node(56);
// 	root2->left = create_node(23);
// 	root2->right = create_node(71);
// 	root2->right->left = create_node(5);
// 	root2->right->left->right = create_node(12);
// 	root2->right->right = create_node(18);

//     return kindredSpirits(root1, root2);
// }


double difficultyRating(void)
{
    return 1.0;
}

double hoursSpent(void)
{
    return 2.0;
}