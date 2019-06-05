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


int height_tree(node * r)
{
    if(r==NULL)
        return 0;
    else{
        int ldepth=height_tree(r->left);
        int rdepth=height_tree(r->right);

        if(ldepth>rdepth)
            return(ldepth + 1);
        else
        return(rdepth + 1);
    }

}

int main()
{
    root=insert_node(root,100);
    insert_node(root,110);
    insert_node(root,90);
    insert_node(root,97);

    inorder(root);
    cout<<endl;
    post_order(root);

    cout<<endl;

    cout<<"heigth of the tree is "<<height_tree(root)<<endl;

    return 0;


}