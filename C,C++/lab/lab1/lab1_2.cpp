#include <stdio.h>
#include "func.h"

int main()
{    int n1,n2,choice;

     //Getting inputs
     printf("Enter number");
     scanf("%d",&n1);

     printf("Enter number");
    scanf("%d",&n2);

    //Menu with function calls
    while(1)
    {   printf("1.Set\n2.Addition\n3.Subtraction\n4.Multiplication\n5.Division\n6.Exit\n");
        scanf("%d",&choice);

        if(choice == 1)
        {   printf("Enter number 1");
            scanf("%d",&n1);
            printf("Enter number 2");
            scanf("%d",&n2);
        }    
        
        else if(choice == 2)
        {   printf("Addition\n");
            add(n1,n2);
        }
        
        else if(choice == 3)
        {   printf("Subtraction\n");
            sub(n1,n2);
        }
        
        else if(choice == 4)
        {   printf("Multiplication\n");
            mult(n1,n2);
        }

        else if(choice == 5)
        {   printf("Division\n");
            div(n1,n2);
        }
        else
            break;
        
    }
    return 0;
}