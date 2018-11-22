#include<bits/stdc++.h>
using namespace std;
int degree;
struct node
{
	int *key;
	node **child;
};
void display_tree(node* cur)
{
	if(cur==NULL) 
		return;
	int i;
	for(i=0;i<2*degree;i++)
	{
		display_tree(cur->child[i]);
		if(cur->key[i]!=-1)
		cout<<cur->key[i]<<" ";
	}
    display_tree(cur->child[2*degree]);
	cout<<endl;
}
bool node_leaf(node* nd)
{
	int is_leaf=0;
	for(int i=0;i<2*degree+1;i++)//check if child exists for node
	{
		if(nd->child[i]!=NULL)
		{
			is_leaf=1;
			break;
		}
	}
	if(!is_leaf)
			return 1;
		else
			return 0;
}
void insert_in_node(node* prev_node,node* &new_node,int k,int pos)
{
	int i;
	for(i=0;i<2*degree && prev_node->key[i]!=-1;i++);
	int j;
	for(j=i-1;j>=pos && prev_node->key[j]>k;j--)
	{
		prev_node->key[j+1]=prev_node->key[j];
		prev_node->child[j+2]=prev_node->child[j+1];
	}
	prev_node->key[pos]=k;
	prev_node->child[pos+1]=new_node;
}
void make_new_node(node* &temp)
{
	temp=new node;
	temp->key=new int[2*degree];
	temp->child=new node*[2*degree+1];
	for(int i=0;i<2*degree;i++)
	{ 
		temp->key[i]=-1;
		temp->child[i]=NULL;
	}
	temp->child[2*degree]=NULL;
}
void split_node(node* prev_node,node* &new_node,int &k,int pos)
{
	node* temp=NULL;
	make_new_node(temp);
	if(pos<=degree)
	{
		for(int i=degree;i<2*degree;i++)
		{
			temp->key[i-degree]=prev_node->key[i];
			temp->child[i-degree+1]=prev_node->child[i+1];
			prev_node->key[i]=-1;
			prev_node->child[i+1]=NULL;
		}
		temp->child[0]=prev_node->child[degree];
		insert_in_node(prev_node,new_node,k,pos);
	}
	else
	{
		for(int i=degree+1;i<2*degree;i++)
		{
			temp->key[i-(degree+1)]=prev_node->key[i];
			temp->child[i-degree]=prev_node->child[i+1];
			prev_node->key[i]=-1;
			prev_node->child[i+1]=NULL;
		}
		temp->child[0]=prev_node->child[degree+1];
        prev_node->child[degree+1]=NULL;
		insert_in_node(temp,new_node,k,pos-(degree+1));
	}
	k=prev_node->key[degree];
	prev_node->key[degree]=-1;
	new_node=temp;
}
int insert_helper(node* temp,int &k,node* &new_node)
{
	if(temp==NULL)
	{
		return 1;
	}
	int pos;
	for(pos=0;pos<2*degree && temp->key[pos]!=-1;pos++)
	{
		if(k<temp->key[pos]) 
			break;
	}
	if(node_leaf(temp))
	{
		if(temp->key[2*degree-1]==-1)//overflow check
		{
			insert_in_node(temp,new_node,k,pos);//not full node
			return 0;
		}
		else
		{
			split_node(temp,new_node,k,pos);//full node
			return 1;
		}
	}
	else
	{
		int flag=insert_helper(temp->child[pos],k,new_node);
		if(flag==1)
		{
			if(temp->key[2*degree-1]==-1)
			{
				insert_in_node(temp,new_node,k,pos);
				return 0;
			}
		    else
		    {
			    split_node(temp,new_node,k,pos);
			    return 1;
		    }
		}
	}
}
node* make_root(node* temp,node* new_node,int k)
{
	node* root=NULL;
	make_new_node(root);
	root->key[0]=k;
	root->child[0]=temp;
	root->child[1]=new_node;
	return root;
}
void insert(node* &temp,int k,node* new_node)
{
	node* root=NULL;
	int new_node_create=insert_helper(temp,k,new_node);
	if(new_node_create)
	{ 
		temp=make_root(temp,new_node,k);
	}
}
int main()
{
	int e,n;
	node *root=NULL;
	cin>>degree>>n;
	while(n--)
	{
		cin>>e;
		node *new_node=NULL;
		insert(root,e,new_node);
	}
	display_tree(root);
	return 0;
}
