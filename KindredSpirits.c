#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "KindredSpirits.h"

typedef struct Stack
{
    int *array;
    int size;
    int capacity; 
}Stack;

// capacity of node is stored into stack
int count_node(node *root)
{
    if (root == NULL)
        {return 0;}

    if (root->left == NULL && root->right == NULL)
        {return 1;}

    return 1+(count_node(root->left) + count_node(root->right));
}

// returns 1 if trees are reflection, 0 otherwise
int isReflection(node *a, node *b)
{
    // empty tree = reflection
    if (a == NULL && b == NULL)
        {return 1;}
    
    // if either is NULL then they are not reflections
    if (a == NULL || b == NULL)
        {return 0;}
    
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

    // make a new node and allocate memory
    node *newNode;
    newNode = malloc(sizeof(node));

    // copy data into the newNode
    newNode->data = root->data;

    // makes recursive call the duplicate the nodes for the tree
    newNode->left  = makeReflection(root->right); // mirror right to left
    newNode->right = makeReflection(root->left);  // mirror left to right

    return newNode;
}

// used for create a stack object
Stack *create_stack(int capacity)
{
    Stack *new_stack = malloc(sizeof(Stack));

    if (new_stack == NULL)
        {printf("Could not allocate memory for the new Stack object.\n");}

    new_stack->array = malloc(sizeof(int) * capacity);
    new_stack->size = 0;            // empty stack
    new_stack->capacity = capacity; // capacity is defined in function call

    return new_stack;
}

// if Stack object is full, return 1. 0 otherwise
int is_full(Stack *s)
{
    // if full
    if (s->size >= s->capacity)
        {return 1;}

    // if NOT full 
    return 0;
}

// checks if the stack is empty or not.
int is_empty(Stack *s)
{
    return (s == NULL || s->size == 0);
}

// removes first element of stack and returns it
int pop(Stack *s)
{
    if (is_empty(s))
        {return 0;} // empty stack
    
    return s->array[--s->size];
}

// removes the passed Stack
Stack *destroy_stack(Stack *s)
{
    if (s == NULL)
        {
            free(s);
            return NULL;
        }

    return s;
}

// adds element to top of stack
void push(Stack *s, int data)
{
    if(is_full(s))
        {return;}
    
    s->array[s->size++] = data;
}

// preorder algorithm traversal
void preorder(node *root, Stack *s)
{
    if (root == NULL)
        {return;}

    push(s, root->data);
    preorder(root->left, s);
    preorder(root->right, s);
}

// POSTorder algorithm traversal
void postorder(node *root, Stack *s)
{
    if (root == NULL)
        {return;}

    postorder(root->left, s);
    postorder(root->right, s);
    push(s, root->data);
}

// useful function that works with 
int helper(Stack *s_1, Stack *s_2)
{
    while(!is_empty(s_1))
    {
        // pop returns the element most recently popped
        if(pop(s_1) != pop(s_2))
        {
            return 0;
        }
    }

    return 1;
}

// a KindredSpirit is when a trees preorder traversal is the same
// as the postoreder traversal
int kindredSpirits(node *a, node *b)
{
    Stack *s_1 = create_stack(count_node(a)); // stack for 'a'
    Stack *s_2 = create_stack(count_node(b)); // stack for 'b'

    if (a == NULL && b == NULL)
        {return 1;}

    if (count_node(a) != count_node(b))
        {return 0;}

    preorder(a, s_1);
    postorder(b, s_2);

    if(helper(s_1, s_2))
    {
        destroy_stack(s_1);
        destroy_stack(s_2);
        return 1;
    }

    // THIS NOW CHECK INVERSE OF THE NODES

    destroy_stack(s_1);
    destroy_stack(s_2);

    // create stack for s_1, s_2
    s_1 = create_stack(count_node(a));
    s_2 = create_stack(count_node(b));

    postorder(a, s_1);
    preorder(b, s_2);

    if(helper(s_1, s_2))
    {
        destroy_stack(s_1);
        destroy_stack(s_2);
        return 1;
    }
    
    destroy_stack(s_1);
    destroy_stack(s_2);

    return 0;
}

double difficultyRating(void)
{
    return 3.0;
}

double hoursSpent(void)
{
    return 5.0;
}