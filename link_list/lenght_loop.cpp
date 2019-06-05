#include <iostream>
#include<unordered_set>
using namespace std;

class node{
    public:
    int data;
    struct node *next;
};

struct node *head=NULL;
void insert_val(int val)
{
    struct node *temp=new node();
    temp->data=val;
    temp->next=head;
    head=temp;
    

}
void count_loop(struct node *n)
{
    int l=1;
    struct node *t=n;
    while (t->next!=n)
    {
        t=t->next;
        cout<<"iiii"<<endl;
        l=l+1;
    }

    cout<<l<<endl;
}

void detect_loop()
{
    struct node *slow=head;
    struct node *fast=head;
    while(fast && slow && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
        //cout<<"loop exist"<<endl;
        //return;
       return count_loop(slow);
        }
    }
}

void print_List()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
        
    }
}
int main()
{
    insert_val(1);
    insert_val(2);
    insert_val(4);
    insert_val(5);
    insert_val(6);

    print_List();
    cout<<endl;

    head->next->next->next=head;
    detect_loop();

    return 0;
}
