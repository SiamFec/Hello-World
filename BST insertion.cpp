#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root;

void insert(int item)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* parentptr;
    struct node* nodeptr;

    temp->data=item;
    temp->left=NULL;
    temp->right=NULL;

    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        parentptr=NULL;
        nodeptr=root;
        while(nodeptr!=NULL)
        {
            parentptr=nodeptr;
            if(item<nodeptr->data)
            {
                nodeptr=nodeptr->left;
            }
            else
            {
                nodeptr=nodeptr->right;
            }
        }
        if(item<parentptr->data)
        {
            parentptr->left=temp;
        }
        else
        {
            parentptr->right=temp;
        }
    }
}

void preorder(struct node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    root=NULL;
    insert(2);
    insert(5);
    insert(1);
    insert(4);
    preorder(root);
    cout<<endl;
    postorder(root);
}
