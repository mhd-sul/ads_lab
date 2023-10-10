#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
int data;
struct node *link;
};
typedef struct node node;
node *getnode();
void main()
{
node *first;
int choice,item,pos,n;
clrscr();
InitializeLlist(&first);
printf("\n creating a linked list \n");
printf("\n enter the number of nodes you want to create:");
scanf("%d",&n);
LListcreate(&first,n);
while(1)
{
printf("\n\n\t implementation of a singly linked list \n");
printf("\n\n\t 1.insertion as a first node");
printf("\n\n\t 2.insertion as a last node");
printf("\n\n\t 3.insertion of a node at any specific location");
printf("\n\n\t 4.deletion of a first node");
printf("\n\n\t 5.deletion of a last node");
printf("\n\n\t 6.deletion of any node");
printf("\n\n\t 7.display all nodes");
printf("\n\n\t 8.exit");
printf("\n\n\t enter(1/2/3/4/5/6/7/8)");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("\n enter the item:");
       scanf("%d",&item);
       InsertLListfirst(&first,item);
       break;
case 2:printf("\n enter the item:");
       scanf("%d",&item);
       InsertLListLast(&first,item);
       break;
case 3:printf("\n enter the item:");
       scanf("%d",&item);
       printf("\n enter the node number where you want to insert the item:");
       scanf("%d",&pos);
       InsertLListatany(&first,item,pos);
       break;
case 4:DeleteLListfirst(&first);
       break;
case 5:DeleteLListfirst(&first);
       break;
case 6:printf("\n enter the node number you want to delete:");
       scanf("%d",&pos);
       DeleteLListany(&first,pos);
       break;
case 7:TraverseLList(&first);
       break;
case 8:exit(0);
default:printf("please enter valid choice\n");
}
}
}
InitializeLList(node**first)
{
(*first)=NULL;
return;
}
LListcreate(node**f,int n)
{
node*temp,*current;
int i,item;
for(i=1;i<=n;i++)
{
printf("enter data field of node%d:");
scanf("%d",&item);
temp=getnode();
temp->data=item;
temp->link=NULL;
if(*f==NULL)
*f=temp;
else
current->link=temp;
current=temp;
}
return;
}
TraverseLList(node*first)
{
printf("\n start->");
while(first!=NULL)
{
printf("%d->",first->data);
first=first->link;
}
printf("end\n");
return;
}
InsertLListfirst(node**first,int item)
{
node*temp;
temp=getnode();
if(temp==NULL)
{
printf("\n unable to create a new node-overflow");
return;
}
temp->data=item;
temp->link=(*first);
(*first)=temp;
return;
}
InsertLList(node**first,int item)
{
node*temp,*current;
temp=getnode();
if(temp==NULL)
{
printf("\n unable to create a new node-overflow");
return;
}
temp->data=item;
temp->link=NULL;
if(*first==NULL)
(*first)=temp;
else
{
current=(*first);
while(current->link!=NULL)
current=current->link;
current->link=temp;
}
return;
}
InsertLListatany(node**first,int item,int pos)
{
node*current,*previous,*temp;
int i;
temp=getnode();
if(temp==NULL)
{
printf("\n unable to create a new node-overflow");
return;
}
if((*first==NULL)||(pos==1))
{
temp->data=item;
temp->link=(*first);
(*first)=temp;
return;
}
current=(*first)->link;
previous=(*first);
i=1;
while(current!=NULL)
{
if((i+1)==pos)
break;
else
{
previous=current;
current=current->link;
i++;
}
}
temp->data=item;
temp->link=current;
previous->link=temp;
return;
}
DeleteLListfirst(node**first)
{
node*current;
int item;
if(*first==NULL)
{
printf("\n link is empty-underflow");
return;
}
current=(*first);
item=current->data;
(*first)=(*first)->link;
freenode(current);
printf("\n Deleted item=%d",item);
return;
}
DeleteLListLast(node**first)
{
node*current,*previous;
int item;
if(*first==NULL)
{
printf("\n list is empty-underflow");
return;
}
current=(*first);
previous=NULL;
if((*first)->link==NULL)
(*first)=(*first)->link;
else
{
while(current->link!=NULL)
{
previous=current;
current=current->link;
}
previous->link=current->link;
}
item=current->data;
freenode(current);
printf("\n deleted item =%d",item);
return;
}
DeleteLListany(node**first,int pos)
{
node*current,*previous;
int item,i;
if(*first==NULL)
{
printf("\n List is empty-underflow");
return;
}
if(pos==1)
{
current=(*first);
item=current->data;
(*first)=(*first)->link;
freenode(current);
printf("\n Deleted item=%d",item);
return;
}
current=(*first)->link;
previous=(*first);
i=2;
while(current!=NULL)
{
if(i==pos)
{
previous->link=current->link;
item=current->data;
freenode(current);
printf("\n Deleted item=%d",item);
}
else
{
previous=current;
current=current->link;
}
i++;
}
return;
}
node*getnode()
{
node*p;
p=(node*)malloc(sizeof(node));
return(p);
}
freenode(node*p)
{
free(p);
return;
}