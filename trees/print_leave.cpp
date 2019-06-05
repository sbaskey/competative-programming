#include <iostream>
using namespace std;

class node
{
    public:
    int key;
    struct node *left;
    struct node *right;
};

node *root=NULL;

node * creat_node(int key)
{
    node *temp=new node();
    temp->left=temp->right=NULL;
    temp->key=key;

    return temp;
}
node* insert_node(node * n ,int key)
{
    if(n==NULL)
    return creat_node(key);

    if(n->key>key)
    {
        n->left=insert_node(n->left,key);

    }
    else if(key>n->key)
    {
        n->right=insert_node(n->right,key);
    }
    
    return n;
    
}

void inorder(node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        cout<<r->key<<" ";
        inorder(r->right);
    }
}

void post_order(node* r)
{
    if(r!=NULL)
    inorder(r->left);
    inorder(r->right);
    cout<<r->key<<" ";
}


//function to print all the left boundary nodes of the binary search tree
void print_leaf(node *r)
{
    if(r){
        print_leaf(r->left);
        if(r->left==NULL && r->right==NULL)
            cout<<r->key<<" ";

    print_leaf(r->right);
    }
}

//function to print all the left boundary of a binary tree

void print_left_boundary(node *r)
{
    if(r->left)
        {
            cout<<r->key<<" ";
            print_left_boundary(r->left);
        }

    else if(r->right)
    {
        cout<<r->key<<" ";
        print_left_boundary(r->right);
    }
    
}

//function to print all the left boundary of a binary tree

void print_right_boundary(node *r)
{
    if(r->right)
        {
            cout<<r->key<<" ";
            print_left_boundary(r->right);
        }

    else if(r->left)
    {
        cout<<r->key<<" ";
        print_left_boundary(r->left);
    }
    
}

// A function to do boundary traversal of a given binary tree 
void printBoundary(node *r) 
{ 
    if (r) { 
        cout<<r->key<<" "; 
  
        // Print the left boundary in top-down manner. 
        print_left_boundary(r->left);
  
        // Print all leaf nodes 
        print_leaf(r->left); 
        print_leaf(r->right);
  
        // Print the right boundary in bottom-up manner 
        print_right_boundary(r->right);
    } 
} 

int main()
{
    root=insert_node(root,50);
    insert_node(root,60);
    insert_node(root,70);
    insert_node(root,65);
    insert_node(root,55);
    insert_node(root,40);
    insert_node(root,45);
    insert_node(root,30);

    inorder(root);
    cout<<endl;
    post_order(root);

    cout<<endl;

    print_leaf(root);
    cout<<endl;

    print_left_boundary(root);
    cout<<endl;

    print_right_boundary(root);
    cout<<endl;

    printBoundary(root);
    cout<<endl;
    return 0;


}