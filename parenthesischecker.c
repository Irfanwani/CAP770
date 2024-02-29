#include<stdio.h>
int main()
{
    char expression[50]; // declaration of char type array
    int x=0, i=0; // declaration of two integer type variables
    printf("\nEnter an expression\n");
    scanf("%[^\n]s", expression); // to consider spaces too, we use %[^\n]s
// Scanning the expression until we reach the end of the expression.
 while(expression[i]!= '\0')
    {
        printf("inside loop\n");
    // Condition to check the symbol is '('
     if(expression[i]=='(')
        {
            x++;    // incrementing 'x' variable
        }
     // condition to check the symbol is ')'
     else if(expression[i]==')')
        {
            x--;   // decrementing 'x' variable
            if(x<0)
            break;
        }
    i++;       // incrementing 'i' variable.
    }
    // Condition to check whether x is equal to 0 or not.
    if(x==0)
    {
        printf("Expression is balanced");
    }

    else
    {
        printf("Expression is unbalanced");
    }
    return 0;
}