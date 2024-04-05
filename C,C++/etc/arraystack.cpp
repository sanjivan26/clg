//Program to implement stack using linked list
#include<stdio.h>
#include<stdlib.h>

class arrstack
{  
    private: 
        char arr[50];
        int top;

    public:
        arrstack()
        {
            top = -1;
        }
        int push(char);
        int pop();
        void peek();
};

int top=-1;

int main()
{   
    arrstack l;    
    int choice,data;
    char num;
    while(1)    
    {   getchar();
        getchar();
        system("clear"); 
        printf("Enter your choice: \n 1. Push \n2. Pop \n3. Peek \n4. Exit");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case(1):
                printf("\n Enter the character to insert into stack:");
                scanf("%c",&num);
                if(l.push(num))
                {
                    printf("Successfully inserted into stack");
                }   
                else
                {
                    printf("Stack is full");
                }    
                break;

            case(2):
                if(l.pop())
                {
                    printf("Stack is popped successfully");
                }
                else
                {
                    printf("Stack is empty");
                }
                break;

            case(3):
                l.peek();
                break;

            case(4):
                exit(0);                
        }
    }
    return 0;
}        


//Method to push into stack
int arrstack::push(char num)
{
    if(top==5)
    {
        return 0;
    }
    top++;
    arr[top]=num;
    return 1;
}

//Method to pop stack
int arrstack::pop()
{
    if(top==-1)
    {
        return 0;
    }
    top--;
    return 1;
}

//Method to peek into stack
void arrstack::peek()
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("The value at the top of the stack is %c", arr[top]);
    }
}