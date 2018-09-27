#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
struct node
{
    int key;
    int node_count;
    struct node *left;
    struct node *right;
    int height;
};
class AVL
{
    public:
        struct node* insert_element(struct node* node, int key);
        int get_height(struct node *);
        void search(struct node *,int);
        void inorder(struct node *);
        int kth_smallest(struct node *,int);
        int count(struct node *);
        struct node *RRrotation(struct node*);
        struct node *LLrotation(struct node*);
        int get_difference(struct node *N);
        struct node *get_min(struct node*);
        struct node *delete_element(struct node*,int);
};
int AVL::get_height(struct node *N)
{
    if (N==NULL)
        return 0;
    return N->height;
}
int AVL::count(struct node *r)
{
    if(r==NULL) 
        return 0;
   return r->node_count;
}
struct node *AVL::RRrotation(struct node *p)
{
    struct node *tmp=p->left;
    struct node *tmp1=tmp->right;
    tmp->right=p;
    p->left=tmp1;
    p->height=max(get_height(p->left),get_height(p->right))+1;
    p->node_count=count(p->left)+count(p->right)+1;
    tmp->height=max(get_height(tmp->left),get_height(tmp->right))+1;
    tmp->node_count=count(tmp->left)+count(tmp->right)+1;
    return tmp;
}
struct node *AVL::LLrotation(struct node *p)
{
    struct node *tmp=p->right;
    struct node *tmp1=tmp->left;
    tmp->left=p;
    p->right=tmp1;
    p->height=max(get_height(p->left),get_height(p->right))+1;
    p->node_count=count(p->left)+count(p->right)+1;
    tmp->height=max(get_height(tmp->left),get_height(tmp->right))+1;
    tmp->node_count=count(tmp->left)+count(tmp->right)+1;
    return tmp;
}
int AVL::get_difference(struct node *p)
{
    if (p==NULL)
        return 0;
    return get_height(p->left)-get_height(p->right);
}
void AVL::search(struct node *r,int k)
{
    if(r==NULL)
    {
        cout<<"0"<<endl;
    }
    else
    {
        if(r->key>k)
        {
            search(r->left,k);
        }
        else
        {
            if (r->key<k)
            {
                search(r->right,k);
            }
            else
            {
                cout<<"1"<<endl;
            }
        }
    }
}

struct node* AVL::insert_element(struct node* r,int key)
{
    if(r==NULL)
    {
        struct node* node=(struct node*)malloc(sizeof(struct node));
        node->key= key;
        node->left=NULL;
        node->right=NULL;
        node->height=1; 
        node->node_count=1;
        return(node);
    }
    if(r->key>key)
    {
        r->left=insert_element(r->left,key);
    }
    else if ((r->key)<key)
    {
        r->right=insert_element(r->right,key);
    }
    else 
    {
        return r;
    }
    r->height=max(get_height(r->left),get_height(r->right))+1;
    r->node_count=count(r->left)+count(r->right)+1;
    int diff=get_difference(r);

    if(diff>1 && (key<r->left->key))
        return RRrotation(r);
    
    if(diff<-1 && key > r->right->key)
        return LLrotation(r);
    
    if(diff>1 && key > (r->left->key))
    {
        r->left=LLrotation(r->left);
        return RRrotation(r);
    }
    if(diff<-1 && key < (r->right->key))
    {
        r->right =RRrotation(r->right);
        return LLrotation(r);
    }
    return r;
}
struct node *AVL::get_min(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node *AVL::delete_element(struct node* root, int key)
{
    if (root==NULL)
        return root;
    if (root->key>key)
        root->left = delete_element(root->left, key);
    else if(root->key<key)
        root->right=delete_element(root->right, key);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *temp;
            
            if(root->left==NULL)
                temp=root->right;
            else
                temp=root->left;
 
            // No child case
            if (temp==NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root=*temp; 
                           
            free(temp);
        }
        else
        {
            struct node *temp=get_min(root->right);
            root->key=temp->key;
            root->right=delete_element(root->right, temp->key);
        }
    }
    if (root == NULL)
        return root;
    root->height=1+max(get_height(root->left),get_height(root->right));
    root->node_count=count(root->left)+count(root->right)+1;

    int dif=get_difference(root);

    if(dif>1 && get_difference(root->left) >= 0)
        return RRrotation(root);

    if(dif> 1 && get_difference(root->left)< 0)
    {
        root->left = LLrotation(root->left);
        return RRrotation(root);
    }

    if(dif < -1 && get_difference(root->right)<=0)
        return LLrotation(root);

    if(dif<-1 && get_difference(root->right)>0)
    {
        root->right = RRrotation(root->right);
        return LLrotation(root);
    }
    return root;
}
void AVL::inorder(struct node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        cout<<r->key<<endl;
        cout<<"nodes"<<r->node_count<<endl;
        inorder(r->right);
    }
}
int AVL::kth_smallest(struct node *r, int k) 
{
        if(r==NULL || k<1)
             return -1;
        int cnt=count(r->left);
       // cout<<"count"<<cnt<<endl;
        //cout<<"k value:"<<k<<endl;
        if(k<=cnt)
        {
            return kth_smallest(r->left,k);
        } 
        else if(k>(cnt+1))
        {
            return kth_smallest(r->right,k-cnt-1);
        }
        return r->key;
}
int main()
{
    struct node *root=NULL;   
    AVL avl;
    int n,m,qn,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        root=avl.insert_element(root,x);
    }
   // avl.inorder(root);
    while(m--)
    {
        cin>>qn>>x;
        if(qn==1)
        {
            root=avl.insert_element(root,x);
        }
        else if(qn==2)
        {
            avl.search(root,x);
        }
        else if(qn==3)
        {
            int k=avl.kth_smallest(root,x);
            cout<<k<<endl;
            root=avl.delete_element(root,k);
        }
    }


    return 0;
}
