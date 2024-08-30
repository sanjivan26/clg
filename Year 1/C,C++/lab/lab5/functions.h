#include <stdio.h>
#include <stdlib.h>

class DLList {
private:
    struct DNode {
        struct DNode *prev;
        int data;
        struct DNode *next;
    };
    struct DNode *Head;
    struct DNode *Tail;
    struct DNode *CurrentWebPage;
    int ID = 0;

public:
    DLList() {
        Head = nullptr;
        Tail = nullptr;
        CurrentWebPage = nullptr;
    }

    // Function to create a new node
    struct DNode *CreateNode();

    // Function to check if the list is empty
    int IsEmpty();

    // Function to add a new webpage to the list
    int NewWebPage();

    // Function to navigate to the previous webpage
    int Go_Prev();

    // Function to navigate to the next webpage
    int Go_Next();

    // Function to display the list
    void Display();
};

// Function to create a new node
struct DLList::DNode *DLList::CreateNode() {
    return (struct DNode *)malloc(sizeof(struct DNode));
}

// Function to check if the list is empty
int DLList::IsEmpty() {
    if (Head == nullptr) {
        return 1;
    } else {
        return 0;
    }
}

// Function to navigate to the previous webpage
int DLList::NewWebPage() {
    struct DNode *C_Node = CreateNode();
    C_Node->data = ID;
    ID++;
    C_Node->next = nullptr;
    if (IsEmpty() == 1) {
        C_Node->prev = nullptr;
        Head = C_Node;
        Tail = C_Node;
        CurrentWebPage = C_Node;
    } else {
        C_Node->prev = Tail;
        Tail->next = C_Node;
        Tail = C_Node;
        CurrentWebPage = Tail;
    }
    return ID - 1;
}

// Function to navigate to the next webpage
int DLList::Go_Prev() {
    if (CurrentWebPage != nullptr && CurrentWebPage->prev != nullptr) {
        CurrentWebPage = CurrentWebPage->prev;
        return CurrentWebPage->data;
    }
    return -1;
}

// Function to navigate to the next webpage
int DLList::Go_Next() {
    if (CurrentWebPage != nullptr && CurrentWebPage->next != nullptr) {
        CurrentWebPage = CurrentWebPage->next;
        return CurrentWebPage->data;
    }
    return -1;
}

// Function to display the list
void DLList::Display() {
    struct DNode *temp = Head;
    printf("[");
    while (temp != nullptr) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]");
}
