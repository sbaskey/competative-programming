#include <iostream>
#include <set>
#include<unordered_set>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node * head=NULL;

void insert_values(int data)
{
    struct node* temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    head=temp;
}

//insert val1 after val2
void insert_after(int val1,int val2)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val1;
    struct node *current=head;
    //cout<<head->data;
    while(current->data!=val2)
        current=current->next;

    //cout<<current->data;
    temp->next=current->next;
    current->next=temp;
}

void insert_end(int val)
{
    struct  node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    struct node *current=head;
    while (current->next!=NULL)
        current=current->next;
    current->next=temp;

}

void del_node(int val)
{
    struct node*temp=head;
    if(temp->data==val)
    {
        head=temp->next;
        free(temp);
    }
    else{
    while(temp->next->data!=val)
        temp=temp->next;

    struct node* n=temp->next;
    struct node* t=n->next;
    temp->next=t;
    free(n);
    }

   
        

}

void detect_cycle()
{
    struct node* slow=head;
    struct node* fast=head;
    while (slow!=NULL && fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)
        {
        cout<<"loop exist"<<endl;
        return;
        }
        
    }
    
}

//detect the cycle using the hashing

void cycle_hashing()
{
    struct node *h=head;
    unordered_set<struct node*>s;
    while(h!=NULL)
    {
        if(s.find(h)!=s.end())
        {
            cout<<"loop exist"<<endl;
            return;
        }
    s.insert(h);
    h=h->next;
    }
return;
}

void print_list()
{
    struct node *temp=head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



int main()
{
    insert_values(1);
    insert_values(2);
    insert_values(3);
    insert_values(10);

    print_list();
   // insert_after(4,10);
   //insert_end(-1);
   //del_node(10);
    

    cout<<endl;
    print_list();
    cout<<endl;
    head->next->next=head;

    detect_cycle();
    // print_list();
    cycle_hashing();
    //cout<<head->data<<endl;

    return 0;
}