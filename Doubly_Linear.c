#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;



void Insert_First(PPNODE,int);
void Insert_Last(PPNODE,int);
int Count(PNODE);
void Insert_Pos(PPNODE,int,int);
void Delete_First(PPNODE);
void Delete_Last(PPNODE);
void Delete_Pos(PPNODE,int);
void Display(PNODE);




int main()
{
	
	PNODE Head=NULL;
	int choise;
	int No;
	int position;
	
	do
	{
		printf("\n1.Insert First\n");
		printf("2.Insert Last\n");
		printf("3.Insert Position\n");
		printf("4.Delete First\n");
		printf("5.Delete Last\n");
		printf("6.Delete Position\n");
		
		printf("7.Exit\n");
		printf("Enter the choise: ");
		scanf("%d",&choise);
	
		switch(choise)
		{
			case 1:
				
				printf("Enter the Node Value: ");
				scanf("%d",&No);
				Insert_First(&Head,No);
				Display(Head);
				break;
	
			case 2:
	
				printf("Enter the Node Value: ");
				scanf("%d",&No);
				Insert_Last(&Head,No);
				Display(Head);
				break;
	
			case 3:
			
				printf("Enter the Node Value : ");
				scanf("%d",&No);
				printf("Enter the position : ");
				scanf("%d",&position);
				Insert_Pos(&Head,position,No);
				Display(Head);
				break;
			
			case 4 :
				Delete_First(&Head);
				printf("After Delete First Node\n");
				Display(Head);
				break;
			case 5:
				Delete_Last(&Head);
				printf("After Delete Last Node\n");
				Display(Head);
				break;
			case 6:
				
				printf("Enter the position : ");
				scanf("%d",&position);
				Delete_Pos(&Head,position);
				Display(Head);
				break;
			
	
		}
			
	}while(choise!=7);			
}
	



void Insert_First(PPNODE First,int No)
{
	PNODE NewNode=NULL;
	NewNode=(PNODE)malloc(sizeof(NODE));
	NewNode->data=No;

	NewNode->next=*First;
	NewNode->prev=NULL;
	*First=NewNode;
}


void Insert_Last(PPNODE First,int No)
{
	PNODE temp=*First;
	PNODE NewNode=NULL;
	NewNode=(PNODE)malloc(sizeof(NODE));
	NewNode->data=No;

	int i=0;
	while(temp->next!=NULL)
	{
		temp=temp->next;	

	}
	temp->next=NewNode;
	NewNode->prev=temp;
	NewNode->next=NULL;
}


void Insert_Pos(PPNODE First,int pos,int No)
{
		
		PNODE temp=*First;
		int cnt=Count(temp);
		printf("count %d\t",cnt);

		if(pos>cnt+1)
		{
			printf(" In pos  Invalid Position\n");
			exit(0);
		}
		if(pos==1)
		{
			Insert_First(First,No);
		}

		
		else if(pos==cnt+1)
		{
			Insert_Last(First,No);
		}
		else
		{
			int i=1;
			PNODE temp=*First;
			PNODE NewNode=NULL;
			NewNode=(PNODE)malloc(sizeof(NODE));
			NewNode->data=No;
			while(i<pos-1)
			{
				temp=temp->next;
				i++;
			}
			NewNode->next=temp->next;
			temp->next=NewNode;
			NewNode->prev=temp;
		}
}

void Delete_First(PPNODE First)
{
	if(*First==NULL)
	{
		printf("Linked list is empty\n");
		exit(0);
	}
	if((*First)->next==NULL)
	{	
		free(*First);
		*First=NULL;
	}
	else	
	{
		PNODE temp=*First;
		PNODE temp1=NULL;
		*First=temp->next;
		(*First)->prev=NULL;
		free(temp);
	}
}

void Delete_Last(PPNODE First)
{
	PNODE  temp=*First;
	PNODE temp1=NULL;
	
	while(temp->next->next!=NULL)
	{
		temp=temp->next;

	}
	temp1=temp->next;
	temp1->prev=NULL;
	temp->next=NULL;
	free(temp1);
}

void Delete_Pos(PPNODE First,int Pos)
{

	PNODE temp=*First;
	PNODE temp1=NULL;
	int cnt=Count(temp);
	if(Pos>cnt)
	{
		printf(" In pos  Invalid Position\n");
		exit(0);
	}
	if(Pos==1)
	{
		Delete_First(First);
	}

	else if(Pos==cnt)
	{
		Delete_Last(First);
	}
	else
	{
		int i=1;
		
		
		while(i<Pos-1)
		{
			temp=temp->next;
			i++;
		}
		temp1=temp->next;
		temp->next=temp1->next;
		temp1->next->prev=temp;
	}



}



int Count(PNODE Head)
{
	if(Head==NULL)
	{
		return 0;
	}
	int count=0;
	
	while(Head!=NULL)
	{	
		
		count++;
		Head=Head->next;
	}
	return count;
		
}


	

void Display(PNODE Head)
{
		if(Head==NULL)
	{
		printf("List is Empty");
		exit(0);
	}
	
	
	while(Head!=NULL)
	{
		printf("%d\t",Head->data);
		Head=Head->next;
	}
}



