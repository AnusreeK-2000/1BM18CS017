#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node * NODE;
NODE getnode();
NODE removedup(NODE head);
NODE insert_front(NODE head,int item);

void display(NODE head);
NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
	{
		printf("memory could not be allocated\n");
		exit(0);
	}
}
NODE insert_front(NODE head,int item)
{
	NODE newn;
	newn=getnode();
	newn->data=item;
	newn->prev=NULL;
	if(head==NULL)
	{
		newn->next=NULL;
		head=newn;
	}
	else
	{
		newn->next=head;
		head->prev=newn;
		head=newn;
	}
	return head;
}

NODE removedup(NODE head)
{
	NODE p,q,r;
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	
	for(p=head;p->next!=NULL;p=p->next)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(p->data==q->data)
			{
				r=q->next;
				free(q);
				p->next=r;
				r->prev=p;
				q=r;
			}
			else
				q=q->next;
		}
	}
	return head;
}
NODE reverse(NODE head)
{
	NODE curr,prev,nextn;
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	curr=head;
	prev=NULL;
	nextn=NULL;
	while(curr!=NULL)
	{
		nextn=curr->next;
		curr->next=prev;
		curr->prev=nextn;
		prev=curr;
		curr=nextn;
	}
	head=prev;
	return head;
}
NODE concat(NODE h1,NODE h2)
{
	NODE p;
	if(h1==NULL)
		return h2;
	if(h2==NULL)
		return h1;
	p=h1;
	while(p->next!=NULL)
		p=p->next;
	p->next=h2;
	h2->prev=h1;
	return h1;
}
int max(NODE head)
{
	int m=-1;
	while(head!=NULL)
	{
		if(head->data>m)
		 	m=head->data;
		head=head->next;
	}
	return m;
}
int min(NODE head)
{
	int mi=9887;
	while(head!=NULL)
	{
		if(head->data<mi)
		 	mi=head->data;
		head=head->next;
	}
	return mi;
}

NODE exch(NODE head)
{
	NODE p=head;
	int l,s,t;
	l=max(head);
	s=min(head);
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	while(p!=NULL)
	{
		if(p->data==s)
			p->data=l;
		else if(p->data==l)
			p->data=s;
		p=p->next;
	}
	
	return head;
}
	


void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("list is empty\n");
		exit(0);
	}
	p=head;
	while(p!=NULL)
	{
		printf("%d\n", p->data);
		p=p->next;
	}
}
int main()
{
	NODE head=NULL;
	NODE head1=NULL;
	int it,i;
	printf("enter 6 node items");
	for(i=0;i<6;i++)
	{
		scanf("%d",&it);
		head=insert_front(head,it);
	}
	printf("enter 3 node items");
	for(i=0;i<3;i++)
	{
		scanf("%d",&it);
		head1=insert_front(head1,it);
	}
	
	head=removedup(head);
	display(head);
	head=reverse(head);
	display(head);
	head=concat(head,head1);
	display(head);
	head=exch(head);
	display(head);
}

