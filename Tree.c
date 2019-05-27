#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Add(PPNODE,int);
void Preorder(PNODE);
void Inorder(PNODE);
void Postorder(PNODE);
int main()
{

	PNODE Head=NULL;

	int choise,No;
	do
	{
		printf("\n1.Add\n");
		printf("2.Preorder\n");
		printf("3.Inorder\n");		
		printf("4.Postorder\n");
		printf("5.Exit\n");
		printf("Enter the choise: ");
		scanf("%d",&choise);
	
		switch(choise)
		{
			case 1:
				
				printf("Enter the Node Value: ");
				scanf("%d",&No);
				Add(&Head,No);
				break;
	
	
			case 2:
				Preorder(Head);
				break;

			case 3:
				Inorder(Head);
				break;
			case 4:
				Postorder(Head);	
				break;
			
		}
			
	}while(choise!=5);			
}


void Add(PPNODE First,int No)
{
	PNODE temp=*First;
	PNODE NewNode=NULL;
	NewNode=(PNODE)malloc(sizeof(NODE));
	
	

	NewNode->left=NULL;
	NewNode->data=No;
	NewNode->right=NULL;
	while(1)
	{
		if(*First==NULL)
		{	
			*First=NewNode;
			break;
		}
		else
		{
			
			
	
			if(temp->data>NewNode->data)
			
			{	if(temp->left==NULL)
				{
					temp->left=NewNode;
					break;
				}
				temp=temp->left;
				
				
			}
			else if(temp->data<NewNode->data)
			{
				if(temp->right==NULL)
				{
					temp->right=NewNode;
					break;
				}
				temp=temp->right;
			}
			else if(temp->data==NewNode->data)
			{
				free(NewNode);
				break;
			}
			
		}
	}
}



void Inorder(PNODE First)
{
	
	if(First!=NULL)
	{
		Inorder(First->left);
		printf("%d\t",First->data);
		Inorder(First->right);

	}


}


void Preorder(PNODE First)
{
	
	if(First!=NULL)
	{	printf("%d\t",First->data);
		Preorder(First->left);
		Preorder(First->right);
	

	}


}

void Postorder(PNODE First)
{
	
	if(First!=NULL)
	{
		Postorder(First->left);
		Postorder(First->right);
		printf("%d\t",First->data);

	}


}




