#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
struct node *root=NULL;
struct node *create_node(int);
void insert(int);
struct node *delete(struct node*,int);
int search(int);
void printtree(struct node*,int);
void inorder(struct node*);
void postorder(struct node*);
void preorder(struct node*);
struct node *smallest_node(struct node *);
struct node *largest_node(struct node*);
int get_data();
int main()
{
	int userChoice;
	int userActive='Y';
	int data;
	struct node *result=NULL;
	clrscr();
	while(userActive=='y'|| userActive=='Y')
	{
		printf("\n------Operations of Binary Search Tree-----\n");
		printf("\n1.Insertion");
		printf("\n2.Deletion");
		printf("\n3.Searching");
		printf("\n4.Get Largest Data");
		printf("\n5.Get Smallest Data");
		printf("\n6.Printing Tree");
		printf("\n--Traversal--");
		printf("\n7.Preorder");
		printf("\n8.Inorder");
		printf("\n9.Postorder");
		printf("\n10.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&userChoice);
		printf("\n");
		switch(userChoice)
		{
			case 1: data=get_data();
				insert(data);
				break;
			case 2: data=get_data();
				root=delete(root,data);
				printf("\n%d deleted",data);
				break;
			case 3: data=get_data();
				if(search(data)==1)
				{
					printf("\nData was found!\n");
				}
				else
				{
					printf("\nData not found!\n");
				}
				break;
			case 4: result=largest_node(root);
				if(result!=NULL)
				{
					printf("\nLargest data:%d\n",result->data);
				}
				break;
			case 5:result=smallest_node(root);
				if(result!=NULL)
				{
					printf("\nSmallest Data:%d",result->data);
				}
				break;
			case 6: printf("\nBinary Search Tree\n");
				printtree(root,1);
				break;
			case 7: printf("\nPreorder Traversal\n");
				preorder(root);
				break;
			case 8: printf("\nInoder Traversal\n");
				inorder(root);
				break;
			case 9: printf("\nPostorder Traversal\n");
				postorder(root);
				break;
			case 10: exit(0);
			default: printf("\nInvalid Choice\n");
				break;
		}
		printf("\n__\nDo you want to continue?(y/n)");
		fflush(stdin);
		scanf("%c",&userActive);
	}
	getch();
	return 0;
}
struct node *create_node(int data)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	if(new_node == NULL)
	{
		printf("\nMemeory for new node can't be allocated");
		return NULL;
	}
	new_node->data=data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}
void insert(int data)
{
	struct node *temp,*prev;
	struct node *newnode=create_node(data);
	if(newnode!=NULL)
	{
		if(root==NULL)
		{

			root=newnode;
			printf("\nData %d was inserted in Node\n",data);
			return;
		}
		temp=root;
		prev=NULL;
		while(temp!=NULL)
		{
			prev=temp;
			if(data>temp->data)
			{
				temp=temp->right;
			}
			else
			{
				temp=temp->left;
			}
		}
		if(data>prev->data)
		{
			prev->right=newnode;
		}
		else
		{
			prev->left=newnode;
		}
		printf("\nData %d was inserted in Node\n",data);
	}
}
struct node *delete(struct node *root,int key)
{
	struct node *temp;
	if(root==NULL)
	{
		return root;
	}
	if(key<root->data)
	{
		root->left=delete(root->left,key);
	}
	else if(key>root->data)
	{
		root->right=delete(root->right,key);
	}
	else
	{
		if(root->left==NULL)
		{
			struct node*temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node*temp=root->left;
			free(root);
			return temp;
		}
		temp=smallest_node(root->right);
		root->data=temp->data;
		root->right=delete(root->right,temp->data);
	}
	return root;
}
int search(int key)
{
	struct node *temp=root;
	while(temp!=NULL)
	{
		if(key==temp->data)
		{
			return 1;
		}
		else if(key>temp->data)
		{
			temp=temp->right;
		}
		else
		{
			temp=temp->left;
		}
	}
	return 0;
}
struct node *smallest_node(struct node*root)
{
	struct node *curr=root;
	while(curr!=NULL && curr->left!=NULL)
	{
		curr=curr->left;
	}
	return curr;
}
struct node *largest_node(struct node *root)
{
	struct node *curr=root;
	while(curr!=NULL && curr->right!=NULL)
	{
		curr=curr->right;
	}
	return curr;
}
void printtree(struct node *t,int level)
{
	int i;
	if(t!=NULL)
	{
		printtree(t->right,level+1);
		for(i=0;i<level;i++)
		{
			printf(" ");
		}
		printf("%d\n",t->data);
		printtree(t->left,level+1);
	}
}
void inorder(struct node*root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void preorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}
int get_data()
{
	int data;
	printf("\nEnter Data:");
	scanf("%d",&data);
	return data;
}