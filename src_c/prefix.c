#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct bin_tree {
    int data;
    struct bin_tree * right, * left;
};

typedef struct bin_tree node;

void print_preorder(node * tree)
{
    if (tree)
    {
        if(tree->left)
        {
            printf("(");
        }
        printf("%c",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
        if(tree->right)
        {
            printf(")");
        }
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        if(tree->left)
        {
            printf("(");
        }
        print_inorder(tree->left);
        printf("%c",tree->data);
        print_inorder(tree->right);
        if(tree->right)
        {
            printf(")");
        }
    }
}

void print_postorder(node * tree)
{
    if (tree)
    {
        if(tree->left)
        {
            printf("(");
        }
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%c",tree->data);
        if(tree->right)
        {
            printf(")");
        }
    }
}

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

int is_valid_operator(char c)
{
   if(c == '+' | c == '-' | c == '*' | c == '/')
   {
      return 1;
   }
   return -1;
}

int is_valid_operand(char c)
{
   if(isalpha(c))
   {
      return 1;
   }
   return -1;
}

char *trim_braces(char *expression, int i)
{
   char *subExpression;
   int j = strlen(expression);

   if(expression[i] != '(')
    {
        subExpression = (char *)malloc(j);
        memcpy(subExpression, &expression[0], j);
        subExpression[j] = '\0';
        return subExpression;
    }

    int k = i+1;
    while(k<j & expression[k] != ')')
    {
        k++;
    }

    if(k==j | expression[k] != ')' )
    {
        subExpression = (char *)malloc(0);
        subExpression[0] = '\0';
        return subExpression;
    }

    subExpression = (char *)malloc(k-i-2);
    memcpy(subExpression, &expression[i+1], k-i-1);
    subExpression[k-i-1] = '\0';
    return subExpression;
}

char *extract_operand(char *expression, int i)
{
    int j = strlen(expression);
    int k = i+1;
    while(k<j & is_valid_operator(expression[k]) < -1)
    {
        k++;
    }

    char *operand = (char *)malloc(k-i);
    memcpy(operand, &expression[i], k-i);
    operand[k-i] = '\0';

    return operand;
}

char *extract_sub(char *expression, int i)
{
    char *subExpression;
    int j = strlen(expression);
    if(expression[i] == '(')
    {
        return trim_braces(expression, i);
    }

    return extract_operand(expression, i);
}


void init(node ** tree)
{
    if(!(*tree))
    {
        node *temp = NULL;
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        *tree = temp;
    }
}

int evaluate_preorder(char *expression)
{
    char* trimmed_expression = trim_braces(expression, 0);
    int len = strlen(trimmed_expression);
    if(len<=0)
    {
        return 0;
    }

    if(len==1)
    {
        return is_valid_operand(trimmed_expression[0]);
    }

    if(is_valid_operator(trimmed_expression[0])<0)
    {
        return -1;
    }

    int i = 1;
    char* sub1 = extract_sub(trimmed_expression, i);
    int result = evaluate_preorder(sub1);
    if(result <= 0)
    {
        return -1;
    }

    i= i+strlen(sub1);
    char* sub2 = extract_sub(trimmed_expression, i);
    int result2 = evaluate_preorder(sub2);
    if(result2 <= 0)
    {
         return -1;
    }

    return 1;
}

int evaluate_postorder(char *expression)
{
    char* trimmed_expression = trim_braces(expression, 0);
    int len = strlen(trimmed_expression);
    if(len<=0)
    {
        return 0;
    }

    if(len==1)
    {
        return is_valid_operand(trimmed_expression[0]);
    }

    int i = 0;
    char* sub1 = extract_sub(trimmed_expression, i);
    int result = evaluate_postorder(sub1);
    if(result <= 0)
    {
        return -1;
    }
    i= i+strlen(sub1);

    char* sub2 = extract_sub(trimmed_expression, i);
    int result2 = evaluate_postorder(sub2);
    if(result2 <= 0)
    {
         return -1;
    }
    i= i+strlen(sub2);

    if(is_valid_operator(trimmed_expression[i])<0)
    {
        return -1;
    }

    return 1;
}

int evaluate_inorder(char *expression)
{
    char * trimmed_expression = trim_braces(expression, 0);
    int len = strlen(trimmed_expression);
    if(len==0)
    {
        return 0;
    }

    if(len==1)
    {
        return is_valid_operand(trimmed_expression[0]);
    }


    int i = 0;
    char* sub1 = extract_sub(trimmed_expression, i);
    int result = evaluate_inorder(sub1);
    if(result <= 0)
    {
        return -1;
    }
    i= i+strlen(sub1);

    if(is_valid_operator(trimmed_expression[i])<0)
    {
        return -1;
    }
    i++;

    char* sub2 = extract_sub(trimmed_expression, i);
    int result2 = evaluate_inorder(sub2);
    if(result2 <= 0)
    {
         return -1;
    }

    return 1;
}

void insert_preorder(node ** tree, char *expression)
{
    char * trimmed_expression = trim_braces(expression, 0);

    if(evaluate_preorder(trimmed_expression) < 0)
    {
        return;
    }

    int len = strlen(trimmed_expression);
    if(len<=0)
    {
        return;
    }

    init( &(*tree));

    (* tree)->data = trimmed_expression[0];

    if(len==1)
    {
        return;
    }

    int i = 1;
    char* val = extract_sub(trimmed_expression, i);
    insert_preorder(&((*tree)->left), val);

    i= i+strlen(val);
    char* val2 = extract_sub(trimmed_expression, i);
    insert_preorder(&((*tree)->right), val2);

}

void insert_postorder(node ** tree, char *expression)
{
    char * trimmed_expression = trim_braces(expression, 0);

    if(evaluate_postorder(trimmed_expression) < 0)
    {
        return;
    }

    int len = strlen(trimmed_expression);
    if(len<=0)
    {
        return;
    }

    init(&(*tree));

    int i = 0;
    if(len!=1)
    {
        char* val = extract_sub(trimmed_expression, i);
        insert_postorder(&((*tree)->left), val);

        i= i+strlen(val);
        char* val2 = extract_sub(trimmed_expression, i);
        insert_postorder(&((*tree)->right), val2);
        i= i+strlen(val2);
    }

    (*tree)->data = trimmed_expression[i];

    return;
}

void insert_inorder(node ** tree, char *expression)
{
    char * trimmed_expression = trim_braces(expression, 0);

    if(evaluate_inorder(trimmed_expression) < 0)
    {
        return;
    }

    int len = strlen(trimmed_expression);
    if(len<=0)
    {
        return;
    }

    init( &(*tree) );

    int i = 0;
    if(len!=1)
    {
        char* val = extract_sub(trimmed_expression, i);
        insert_inorder(&((*tree)->left), val);
        i= i+strlen(val);
    }

    (*tree)->data = trimmed_expression[i];

    i++;
    if(len!=1)
    {
        char* val2 = extract_sub(trimmed_expression, i);
        insert_inorder(&((*tree)->right), val2);
    }

    return;
}

int main(int argc, char *argv[])
{
    node *root;
    root = NULL;

    printf("\nCurrent limitations: No spaces allowed. One char (alphabet) per operand only.");

    char * expression;
    printf("\nPlease input an expression :");
    fgets(expression, 100, stdin);

    printf("\nProvided expression:%s",expression);

    if(evaluate_inorder(expression) > 0)
    {
        printf("\nFound an in-order expression!");
        insert_inorder(&root, expression);
    }
    else if(evaluate_preorder(expression) > 0)
    {
        printf("\nFound a pre-order expression!");
        insert_preorder(&root, expression);
    }
    else if(evaluate_postorder(expression) > 0)
    {
        printf("\nFound a post-order expression!");
        insert_postorder(&root, expression);
    }
    else{
        printf("\nInvalid Expression!");
        return -1;
    }

    /* Printing nodes of tree */
    printf("\nPre Order Display\n");
    print_preorder(root);

    printf("\nIn Order Display\n");
    print_inorder(root);

    printf("\nPost Order Display\n");
    print_postorder(root);

    /* Deleting all nodes of tree */
    deltree(root);
    return 0;
}