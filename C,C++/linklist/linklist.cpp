//Program to inplement singly linked list using adt
#include<stdio.h>
#include<stdlib.h>

class LinkList
{  
    private: 

    struct node
    {   
        int data;
        struct node *next;
    };

    struct node *head;


    int cursize()
    {
        struct node *add;
        int size = 0;
        while (add!=NULL)
        {
            add=add->next;
            size++;
        }
        return size;
    }

    struct node* accessprev(struct node* last)
    {
        struct node *temp = head;
        while(temp->next!=last)
        {
            temp=temp->next;
        }
        return temp;
    }   

    public:
        LinkList()
        {
            head=NULL;
        }
        void insbeg(int);
        void insend(int);
        int inspos(int,int);
        int delbeg();
        int delpos(int);
        int delend();
        int search(int);
        int revdisp();
        int revlist();
        void display();
};

int main()
{   
    LinkList ll1;    
    int choice,num,pos,result;
    while(1)    
    {   getchar();
        getchar();
        system("clear"); 
        printf("Enter your choice: \n 1. Insert at Beginning \n 2. Append \n 3. Insert");
        printf("\n 4. Delete beginning \n 5. Delete at position \n 6. Delete at end");
        printf("\n 7. Search \n 8. Display \n 9. Display Reverse \n 10. Reverse Link \n 11. Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case(1):
                printf("\n Enter the number to insert:");
                scanf("%d",&num);
                ll1.insbeg(num);
                printf("Successfully inserted");
                break;

            case(2):
                printf("\n Enter the number to append:");
                scanf("%d",&num);
                ll1.insend(num);
                printf("Successfully inserted");
                break;    

            case(3):
                printf("\n Enter the number to insert:");
                scanf("%d",&num);
                printf("\n Enter the location:");
                scanf("%d",&pos);
                if(ll1.inspos(num,pos))
                    printf("Successfully inserted");
                else
                    printf("Invlid Index");    
                break;

            case(4):
                result=ll1.delbeg();
                if(result==0)
                {   
                    printf("The list is empty");
                }    
                else 
                    printf("Sucessfully deleted %d",result);   
                break;     

            case(5):
                printf("\n Enter the location:");
                scanf("%d",&pos);
                result=ll1.delpos(pos);
                if (result!=0)  
                {   
                    printf("Successfully deleted %d",result);
                }    
                else 
                    printf("Invalid index");     
                break;             
            case(6):
                result=ll1.delend();
                if (result!=0)  
                {   
                    printf("Successfully deleted %d",result);
                }    
                else 
                    printf("Empty list");     
                break;    

            case(7):
                printf("\n Enter the number to search:");
                scanf("%d",&num);
                if (ll1.search(num)!=0)  
                {   
                    printf("Successfully deleted %d",ll1.search(num));
                }    
                else 
                    printf("Empty list");     
                break;    

            case(8):
                ll1.display();
                break;  

            case(9):
                ll1.revdisp();
                break;         

            case(10):
                if(ll1.revlist())
                {   
                    printf("Successfully reversed");
                }    
                else 
                    printf("The list is empty");     
                break;     

            case(11):
                exit(0);
                break;     
        }
    }
    return 0;
}



//Method to insert value at the beginning
void LinkList::insbeg(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
}

//Method to insert value at the end
void LinkList::insend(int num)
{
    struct node *add;
    add=head;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    while(add!=NULL)
    {   if (add->next==NULL)
        {   
            add->next=newnode;
            break;
        }    
        else
            add = add->next;
    }
    newnode->data=num;
}

//Method to insert value
int LinkList::inspos(int num,int pos)
{
	if(pos==1)
	    {
	    	insbeg(num);
            return 1;
		}
	else
		{
            printf("%d", cursize());
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = num;
		    struct node* temp;
	        temp = head;
            
	        for(int i=2;i<pos;i++)
	        {
		        temp = temp->next;
	        }
            newnode->next = temp->next;
	        temp->next = newnode;
            return 1;
        }    
}    

//Method to delete beginning character
int LinkList::delbeg()
{   
    struct node *add;
    if(head==NULL)
        return 0;
    else
    {
        add=head;
        head=head->next;
        int data=add->data;
        free(add);
        return data;
    }    
}

//Method to delete element in middle
int LinkList::delpos(int pos)
{   
    if(head==NULL)
        return 0;
    else if(pos==1)
    {
        int data = head->data;
        delbeg();
        return data;
    }
    else if(cursize()<pos)    
        {   
            return 0;
        }
    else
    {   
        struct node *temp;
        struct node *target;
	    temp = head;
        for(int i=2;i<pos-1;i++)
	    {
		    temp = temp->next;
	    }
        target=temp->next;
        temp->next=target->next;
        int data=target->data;
        free(target);
        return data;  
    }
}


//Method to delete end of list
int LinkList::delend()
{
    if(head==NULL)
    {
        return 0;
    }
    else if(cursize()==1)
    {   
        int data = head->data;
        delbeg();
        return data;
    }
    else
    {   struct node *temp;
        struct node *target;
	    temp = head;
        target=temp->next;
        while(target->next!=NULL)
	    {
		    temp = temp->next;
            target = target->next;
	    }
        target=temp->next;
        temp->next=NULL;
        int data = target->data; 
        free(target);
        return data; 
    }    
}

//Method to check if element exists in list
int LinkList::search(int num)
{
    struct node *temp;
    while(temp!=NULL)
    {
        if(temp->data==num)
        {
            return 1;
        }
        else
        {
            temp=temp->next;
        }
    }
    return 0;
}

//Method to print reverse of list
int LinkList::revdisp()
{

    //Actual code
    struct node *add;
    add=head;
        while(add->next!=NULL)
        {
            add=add->next;
        }
        printf("[ %d, ",add->data);
        while(add!=head)
        {   
            add=accessprev(add);
            printf("%d, ",add->data);

        }
    return 1;          
}

//Method to reverse List
int LinkList::revlist()
{   
    if(head==NULL)
    {
        return 0;
    }
    struct node *left;
    struct node *temp1;
    struct node *temp2;
	left = head;
    temp2=left->next;
    while(temp2!=NULL)
	{
	    temp1=left;
        left=temp2;
        temp2=left->next;
        left->next=temp1;
	}
    head->next=NULL;
    head=left;
    
    return 1;
}    

//Method to display the List
void LinkList::display()
{
    struct node *add;
    add=head;
    printf("[ ");
    while(add!=NULL)
    {
        printf("%d, ",add->data);
        add=add->next;
    }
    printf("]");
}


