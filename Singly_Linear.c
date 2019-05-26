#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;



void Insert_First(PPNODE,int);
void Display(PNODE);
void Insert_Last(PPNODE,int);
void Insert_Pos(PPNODE,int,int);
void Delete_First(PPNODE);
void Delete_Last(PPNODE);
void Delete_Pos(PPNODE,int);
int main()
{

	PNODE Head=NULL;
	int choise;
	int No;
	int position;
	
	do
	{
		printf("\n\n1.Insert First\n");
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
				Insert_Pos(&Head,No,position);
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

	/*PNODE Head=NULL;

	Insert_First(&Head,11);
	Insert_First(&Head,21);
	Insert_First(&Head,31);
	Insert_Last(&Head,10);	
	Display(Head);
	printf("\n");
	Insert_Pos(&Head,45,1);
	Display(Head);
	Delete_First(&Head);
	printf("\n After Delete\t");
	Display(Head);
	Delete_Last(&Head);
	printf("\n After Delete LAST\t");
	Display(Head);

	Insert_Last(&Head,100);
	Delete_Pos(&Head,2);
	printf("\n After Delete POS\t");
	Display(Head);*/



void Insert_First(PPNODE First,int No)
{
	

	PNODE NewNode=NULL;
	NewNode=(PNODE)malloc(sizeof(NODE));
	NewNode->data=No;
	NewNode->next=NULL;

	
	NewNode->next=*First;
	*First=NewNode;

	

} 


void Insert_Last(PPNODE First,int No)
{
		
	PNODE NewNode=NULL;
	NewNode=(PNODE)malloc(sizeof(NODE));
	NewNode->data=No;
	NewNode->next=NULL;

	PNODE temp=NULL;
	temp= *First;
	while((temp->next)!=NULL)
	{
		temp=temp->next;
	}
	temp->next=NewNode;
		
	

}

void Display(PNODE Head)
{

	while(Head!=NULL)
	{
		printf("%d\t",Head->data);
		Head=Head->next;
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

void Insert_Pos(PPNODE First,int No,int pos)
{
		
		PNODE temp=*First;
		int cnt=Count(temp);
	
		if(pos>cnt+1)
		{
			printf("Invalid Position\n");
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
		PNODE NewNode=NULL;
		NewNode=(PNODE)malloc(sizeof(NODE));
		NewNode->data=No;
		NewNode->next=NULL;
	
		PNODE temp=*First;
		int i=1;
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		NewNode->next=temp->next;	
		temp->next=NewNode;	
	}
}


void Delete_First(PPNODE First)
{

	if(*First==NULL)
	{
		printf("List is Empty\n");
		exit(0);
	}
	
	PNODE temp1=*First;
	
	*First=(*First)->next;
	
	free(temp1);
}


void Delete_Last(PPNODE First)
{
	if(*First==NULL)
	{
		printf("List is Empty\n");
		exit(0);
	}
	PNODE temp=*First;
	while((temp->next->next)!=NULL)
	{
		temp=temp->next;
	}
	PNODE temp1=temp->next;
	free(temp1);
	temp->next=NULL;
}

void Delete_Pos(PPNODE First,int pos)
{
	
	PNODE temp=*First;
	PNODE temp1=NULL;
	int cnt=Count(temp);
	if(*First==NULL)
	{
		printf("List is Empty\n");
		exit(0);
	}

	if(pos>cnt)
	{
		printf("Invalid Position\n");
		exit(0);
	}
	if(pos==1)
	{
		Delete_First(First);
	}

	else if(pos==cnt)
	{
		Delete_Last(First);
	}
	else
	{
	
		int i=1;
		while(i<pos-1)
		{
			temp=temp->next;
		}
	
		PNODE temp1=temp->next;
		temp->next=temp->next->next;
		free(temp1);
	}
}	

