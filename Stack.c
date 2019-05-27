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



void Push(PPNODE,int);
void Pop(PPNODE);
void Display(PNODE);
void Pick(PPNODE);

int main()
{

	PNODE Head=NULL;
	int choise;
	int No;
	int position;
	
	do
	{
		printf("\n1.Push\n");
		printf("2.Pop\n");
		printf("3.Pick\n");		
		printf("4.Exit\n");
		printf("Enter the choise: ");
		scanf("%d",&choise);
	
		switch(choise)
		{
			case 1:
				
				printf("Enter the Node Value: ");
				scanf("%d",&No);
				Push(&Head,No);
				Display(Head);
				break;
	
			case 2:
				Pop(&Head);
				Display(Head);
				break;
	
			
			case 3 :
				Pick(&Head);
				Display(Head);
				break;
			
		}
			
	}while(choise!=4);			
}
	

void Push(PPNODE First,int No)
{
	
	PNODE NewNode=NULL;
	NewNode=(PNODE)malloc(sizeof(NODE));
	if(*First==NULL)
	{
		*First=NewNode;
		NewNode->data=No;
		NewNode->next=NULL;
	}
	else
	{
		NewNode->next=*First;
		NewNode->data=No;
		*First=NewNode;
	}




}

void Pop(PPNODE First)
{
	if(*First==NULL)
	{
		printf("Stack is empty");
		exit(0);
	}
	else
	{
		PNODE temp=*First;
		*First=temp->next;
		free(temp);
	}

}



void Pick(PPNODE First)
{

	if(*First==NULL)
	{
		printf("Stack is empty");
		exit(0);
	}
	else
	{
		printf("Picked element: %d\n",(*First)->data);
	
	}
}
void Display(PNODE Head)
{

	while(Head!=NULL)
	{
		printf("%d\t",Head->data);
		Head=Head->next;
	}
}

