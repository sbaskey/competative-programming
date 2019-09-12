#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int val;
    struct node *next;
}node;

node *head=NULL;

void insert_node(int val)
{
    node *temp=new node();
    temp->val=val;
    if(head==NULL)
        head=temp;
    else
    {
        node *current=head;
        while(current->next!=NULL)
            current=current->next;
        current->next=temp;
    }
    
    
}

void print_leaf()
{
    node * temp=head;
    while(temp->next!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

int main()
{
    insert_node(1);
    insert_node(2);
    insert_node(3);
    insert_node(4);
    print_leaf();
    return 0;
}


