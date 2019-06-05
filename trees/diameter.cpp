#include <iostream>
using namespace std;

class node
{
    public:
    int key;
    node *left;
    node *right;
};

node *root;

node *create_node(int k)
{
    node *temp=new node();
    temp->key=k;
    temp->left=temp->right=NULL;
    return temp;
}

node *insert_node(node *r,int k)
{
    if (r==NULL)
     return create_node(k);

    else if (k<r->key)
        r->left=insert_node(r->left,k);

    else if (k>r->key)
        r->right=insert_node(r->right,k);

    return r;
}

void inorder(node *r)
{
    if(r!=NULL){
    inorder(r->left);
    cout<<r->key<<" ";
    inorder(r->right);
    }

}

int get_height(node *r)
{
    if(r==NULL)
        return 0;
    int ldepth=get_height(r->left);
    int rdepth=get_height(r->right);

    return 1 + max(ldepth,rdepth);
}

int get_diameter(node *r)
{
    if(r==NULL)
        return 0;

    int lh=get_height(r->left);
    int rh=get_height(r->right);

    int ld=get_diameter(r->left);
    int rd=get_diameter(r->right);

    return max(max(ld,rd),1 + lh+ rh);
}


int main()
{
    root=insert_node(root,10);
    insert_node(root,7);
    insert_node(root,13);
    insert_node(root,5);
    insert_node(root,15);
    inorder(root);
    cout<<root->key;
    cout<<endl;

    cout<<get_height(root)<<endl;

    return 0;
}