#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node * NODE;
NODE getnode()
{
	NODE p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
}
NODE insert(NODE head,int item)
{
	NODE newn,p;
	newn=getnode();
	newn->data=item;
	
	if(head==NULL)
	{
		newn->next=newn;
		head=newn;
		return head;
	}
	else
	{
		newn->next=head->next;
		head->next=newn;
		head=newn;
		return head;
	}
}
NODE reverse(NODE head)
{
	NODE prev,curr,nextn,q;
	if(head==NULL || head->next==head)
	{
		return head;
	}
	
	curr=head;
	prev=NULL;
	nextn=NULL;
	do
	{
		nextn=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextn;
	}while(curr!=head);
	head->next=prev;
	q=head->next;
	while(q->next!=head)
		q=q->next;
	head=q;
	return head;
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("empty");
		exit(0);
	}
	p=head->next;
	do{
		printf("%d\n",p->data);
		p=p->next;
	}while(p!=head->next);
}
int main()
{
	NODE head=NULL;
	int item,i;
	printf("enter 5 nodes");
	for(i=0;i<5;i++)
	{
		scanf("%d",&item);
		head=insert(head,item);
	}
	display(head);
	head=reverse(head);
	display(head);
	return 0;
}
	
		




