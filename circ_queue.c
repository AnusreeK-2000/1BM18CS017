#include<stdio.h>
#define S 5
void insert(int item,int *r,int *f,int q[]);
int delete(int q[],int *f,int *r);
void display(int q[],int r,int f);

void insert(int item,int *r,int *f,int q[])
{
	if((*f==*r+1)||(*f==0 && *r==S-1))
	{
		printf("queue overflow\n");
		return;
	}
	if(*f==-1)
		*f=0;
	*r=(*r+1)%S;
	q[*r]=item;
}

int delete(int q[],int *f,int *r)
{
	int item;
	if(*f==-1)
	{
		printf("queue underflow\n");
		return -99;
	}
	item=q[*f];
	if(*f==*r)
	{
		*f=-1;
		*r==-1;
		
	}
	else
		*f=(*f+1)%S;
	return item;
}
void display(int q[],int r,int f)
{
	int i;
	if(f==-1)
	{
		printf("queue is empty\n");
		return;
	}
	printf("contents of queue are :\n");
	for(i=f;i!=r;i=(i+1)%S)
		printf(" %d",q[i]);
	printf(" %d",q[i]);
	printf("\n");
}
int main()
{
	int fr,re,it,x,ch,n,nd,qu[S],i;
	fr=-1;
	re=-1;
	printf("\n enter 1 to insert\n2 to delete\n3 to display\n-1 to exit \n");
	scanf("%d",&ch);
	while(ch!=-1)
	{
		switch(ch)
		{
			case 1: printf("enter the no.of elements to be inserted \n");
				scanf("%d",&n);
				printf("enter the elements to be inserted\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&it);
					insert(it,&re,&fr,qu);
				}
				break;
			case 2: printf("enter the no.of elements to be deleted\n");
				scanf("%d",&nd);
				printf("the deleted elements are\n");
				for(i=0;i<nd;i++)
					printf("%d\n",delete(qu,&fr,&re));
				break;
			case 3: display(qu,re,fr);
				break;
			default: printf("invalid input\n");
		}
		printf("enter next choice or -1 to exit\n");
		scanf("%d",&ch);
	}
	return 0;
}
					


