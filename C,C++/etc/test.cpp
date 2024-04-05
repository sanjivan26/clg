#include <iostream>
#include <cstdlib>

class doublink {
    struct node {
        struct node *prev;
        int data;
        struct node *next;
    };
    struct node *head;
    struct node *tail;

public:
    doublink() {
        head = NULL;
        tail = NULL;
    }
    int insevenodd(int, int, int);
    void display();
    void insbeg(int);
    void insend(int);
    int inspos(int, int);
    int delbeg();
    int delend();
    int delpos(int);
    int search(int);
    int searchpos(int);
};

int newpage(int, doublink&);
int front(doublink&);
int back(doublink&);
void display(doublink&);

int cur = 0;

int main() {
    int choice, result;
    doublink b1;
    while (true) {
        printf("Enter a choice\n 1. New Webpage\n 2. Front\n 3. Back\n 4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case (1):
                result = newpage(rand(), b1);
                if (result == 1) {
                    printf("\n New webpage inserted");
                } else {
                    printf("\n Insertion failed");
                }
                break;

            case (2):
                result = front(b1);
                if (result == 1) {
                    printf("\n Navigation successful");
                } else {
                    printf("\n Navigation failed");
                }
                break;

            case (3):
                result = back(b1);
                if (result == 1) {
                    printf("\n Navigation successful");
                } else {
                    printf("\n Navigation failed");
                }
                break;

            case (4):
                exit(0);
                break;
        }
        display(b1);
    }
    return 1;
}

int newpage(int data, doublink &b1) {
    // Node insertion
    cur++;
    b1.inspos(data, cur);

    // Deleting following nodes
    while (b1.delpos(cur + 1) != -1) {
        b1.delpos(cur + 1);
    }
    return 1;
}

int front(doublink &b1) {
    if (b1.searchpos(cur + 1) != 0) {
        cur += 1;
        return 1;
    } else {
        return 0;
    }
}

int back(doublink &b1) {
    if (b1.searchpos(cur - 1) != 0) {
        cur -= 1;
        return 1;
    } else {
        return 0;
    }
}

void display(doublink &b1) {
    printf("\nYou are currently in webpage %d \nIt has data %d", cur, b1.searchpos(cur));
}


/*Method to insert data at nth odd/even segment
int doublink::insevenodd(int odev,int n,int num)
{
    int pos=(2*n)-odev;

    
	if(head==NULL)
	    {
	    	insbeg(num);
            return 1;
		}

    else
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        struct node *add;
        add=head;
        int count;
        while(add->next!=NULL)
        {
            count+=1;
            add=add->next;
        }

        if(pos>count+1)
        {
            return 0;
        }

       
	    else
		{
		    struct node* temp;
	        temp = head;
	
	        for(int i=0;i<pos-2;i++)
	        {
		        temp = temp->next;
	        }
	        newnode->data = num;
	        newnode->next = temp->next;
	        temp->next = newnode;
            newnode->prev=temp;
            temp=temp->next;
            temp->prev=newnode;
            }
        return 1;
    }
}*/    

//Method to search for data given position of node
int doublink::searchpos(int cur)
{
    if(head==NULL)
    {
        return 0;
    }
    struct node *add;
    add=head;
    int count=1;
    while(add->next!=NULL)
    {
        add=add->next;
        count+=1;
    }
    if(cur>count+1||cur<1)
    {
        return 0;
    }

    struct node* temp;
    temp = head;
    
	for(int i=0;i<cur-1;i++)
    {
	    temp = temp->next;
    }
    return temp->data;
}

//Method to insert value at the beginning
void doublink::insbeg(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    if(head!=NULL)
    {
        head->prev=newnode;
        
    }
    else
    {
        tail=newnode;
    }
    head=newnode;
}

//Method to insert value at the end
void doublink::insend(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->prev=tail;
    if(tail!=NULL)
    {
        tail->next=newnode;

    }
    else
    {
        head=newnode;
    }
    tail=newnode;  
}

//Method to insert a value
int doublink::inspos(int num,int pos)
{   
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        struct node *add;
        add=head;
        int count=1;
        while(add->next!=NULL)
        {
            add=add->next;
            count+=1;
        }

        if(pos>count+1||pos<1)
        {
            return 0;
        }
        else if(pos==1)
        {
            insbeg(num);
            return 1;
        }
        else if(pos==count+1)
        {
            insend(num);
            return 1;
        }
	    struct node* temp;
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
	    temp = head;
	    for(int i=0;i<pos-2;i++)
	    {
	        temp = temp->next;
	    }
	    newnode->data = num;
	    newnode->next = temp->next;
	    temp->next = newnode;
        newnode->prev=temp;
        temp=newnode->next;
        temp->prev=newnode;
    
        return 1;
    }
}

//Method to delete value at the beginning
int doublink::delbeg()
{
    if(head==NULL)
    {
        return 0;        
    }  
    else if(head==tail)
    {
        free(head);
        head=NULL;
        tail=NULL;
        return 1;
    }
    else
    {
        struct node *target;
        target=head;
        head=head->next;
        head->prev=NULL;
        free(target);
        return 1;
    }
}

//Method to delete value at the end
int doublink::delend()
{
    if(head==NULL)
    {
        return 0;        
    }  
    else if(head==tail)
    {
        free(head);
        head=NULL;
        tail=NULL;
        return 1;
    }
    else
    {
        struct node *target;
        target=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(target);
        return 1;
    }
}

//Method to delete a value
int doublink::delpos(int pos)
{
    if(head==NULL)
	    {
	    	return 0;
		}
    else
    {
        struct node *add;
        add=head;
        int count=1;
        while(add->next!=NULL)
        {
            add=add->next;
            count+=1;
        }

        if(pos>count||pos<1)
        {
            return 0;
        }
        else if(pos==1)
        {
            delbeg();
            return 1;
        }
        else if(pos==count)
        {
            delend();
            return 1;
        }

       
	else
	{
	    struct node* temp;
        struct node *target;
	    temp = head;
	    for(int i=0;i<pos-2;i++)
	    {
	        temp = temp->next;
	    }
	    target=temp->next;
        temp->next=target->next;
        temp=target->next;
        temp->prev=target->prev;
        free(target);
        return 1;
    }
    return 1;
    }
}    

//Method to check if element exists in list
int doublink::search(int num)
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

//Method to display the List
void doublink::display()
{
    struct node *add;
    add=head;
    printf("Printing in forward \n [ %d",add->data);
    while(add!=tail)
    {
        add=add->next;
        printf(", %d",add->data);
    }
    printf(" ] \n ");
    add=tail;
    printf("\n Printing in reverse \n [ %d",add->data);
    
    while(add!=head)
    {
        add=add->prev;
        printf(", %d",add->data);
    }
    printf(" ]");
}