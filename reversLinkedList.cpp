/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *root;
struct node* createNode(int data)
{
    struct node *tmp = new node();
    tmp->data=data;
    return tmp;
}
void insert( int data)
{
    struct node *newNode = createNode(data);
    if(root ==NULL)
    {
        root = newNode;
        cout<<"Root is null"<<endl;
    }
    else
    {
        cout<<"root is not null"<<endl;
        struct node *lastNode = root;
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void printList()
{
    struct node *tmp=root;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<"->";
        tmp=tmp->next;
    }
    cout<<"NULL"<<endl;
}
void reverseList()
{
    struct node *prev=NULL;
    struct node *next=NULL;
    struct node *curr=root;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
        
    }
    root=prev;
}

struct node * reverseRecursion(struct node *head)
{
    if(head ==NULL || head->next ==NULL)
        return head;
    struct node *tmp = reverseRecursion(head->next);
    head->next->next=head;
    head->next=NULL;
    return tmp;
}
int main()
{
    cout<<"Hello World";
   // struct node *root=NULL;
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    if(root==NULL)
        cout<<"LinkedList did not create successfully"<<endl;
    printList();
    reverseList();
    printList();
    root =  reverseRecursion(root);
    printList();
    return 0;
}
