#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* next;
};


	typedef struct node NODE;
	typedef struct node* PNODE;
	typedef struct node** PPNODE;


	void Insert_First(PPNODE,PPNODE,int);
	void Insert_Last(PPNODE,PPNODE,int);
	void Insert_Pos(PPNODE,PPNODE,int,int);
	void Delete_First(PPNODE,PPNODE);
	void Delete_Last(PPNODE,PPNODE);
	void Delete_Pos(PPNODE,PPNODE,int);
	int Count(PNODE,PNODE);
	void Display(PNODE,PNODE);

int main()
{
	PNODE Head=NULL;
	PNODE Tail=NULL;

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
				Insert_First(&Head,&Tail,No);
				Display(Head,Tail);
				break;
	
			case 2:
	
				printf("Enter the Node Value: ");
				scanf("%d",&No);
				Insert_Last(&Head,&Tail,No);
				Display(Head,Tail);
				break;
	
			case 3:
			
				printf("Enter the Node Value : ");
				scanf("%d",&No);
				printf("Enter the position : ");
				scanf("%d",&position);
				Insert_Pos(&Head,&Tail,No,position);
				Display(Head,Tail);
				break;
			
			case 4 :
				Delete_First(&Head,&Tail);
				printf("After Delete First Node\n");
				Display(Head,Tail);
				break;
			case 5:
				Delete_Last(&Head,&Tail);
				printf("After Delete Last Node\n");
				Display(Head,Tail);
				break;
			case 6:
				
				printf("Enter the position : ");
				scanf("%d",&position);
				Delete_Pos(&Head,&Tail,position);
				Display(Head,Tail);
				break;
			
	
		}
			
	}while(choise!=7);			
}




	/*
	Insert_First(&Head,&Tail,10);
	Insert_First(&Head,&Tail,20);
	Insert_First(&Head,&Tail,30);
	Insert_First(&Head,&Tail,40);
	 Insert_Last(&Head,&Tail,5);
	int cnt=Count(Head,Tail);
	printf("%d\t",cnt);
	Display(Head,Tail);*/


void  Insert_First(PPNODE First,PPNODE Last,int No)
{
	PNODE NewNode =NULL;

	NewNode =(PNODE)malloc(sizeof(NODE));
	NewNode->data=No;
	NewNode->next=NULL;

	if(*First==NULL && *Last==NULL)
	{
		
		
				
		*First=NewNode;
		*Last=NewNode;
		//NewNode->next=*First;
		(*Last)->next=*First;
		
	}
	else
	{
		NewNode->next=*First;
		*First=NewNode;
		(*Last)->next=*First;
		
		
	}
		
}


void Insert_Last(PPNODE First,PPNODE Last,int No)
{
	
	if(*First==NULL&& *Last==NULL)
	{
		Insert_First(First,Last,No);
	
	}
	else
	{
		PNODE NewNode =NULL;
	
		NewNode =(PNODE)malloc(sizeof(NODE));
		NewNode->data=No;
		NewNode->next=NULL;


	
		NewNode->next=*First;
		(*Last)->next=NewNode;
		*Last=NewNode;
	}
		

}
void Insert_Pos(PPNODE First,PPNODE Last,int No,int pos)
{
	PNODE temp=*First;
	PNODE temp1=*Last;
		int cnt=Count(temp,temp1);
		printf(" count %d\t",cnt);
		if(pos>cnt+1)
		{
			printf("Invalid Position\n");
			exit(0);
		}
		if(pos==1)
		{
			Insert_First(First,Last,No);
		}

		
		else if(pos==cnt+1)
		{
			Insert_Last(First,Last,No);
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

void Delete_First(PPNODE First,PPNODE Last)
{
	if(*First==NULL && *Last==NULL)
	{
		printf("List is Empty\n");
		exit(0);
	}
	PNODE temp=*First;
	*Last=(*First)->next;	
	*First=(*First)->next;
	free(temp);


}


void Delete_Last(PPNODE First,PPNODE Last)
{
	if(*First==NULL && *Last==NULL)
	{
		printf("List is Empty\n");
		exit(0);
	}
	PNODE temp=*First;
	PNODE temp1=*Last;
	
	while(temp->next!=*Last)
	{
		temp=temp->next;
	}
	*Last=temp;
	temp->next=*First;
	free(temp1);
}


void Delete_Pos(PPNODE First,PPNODE Last,int pos)
{
	if(*First==NULL && *Last==NULL )
	{
		printf("List is Empty\n");
		exit(0);
	}
	PNODE temp=*First;
	PNODE temp2=*Last;
	PNODE temp1=NULL;
	int cnt=Count(temp,temp2);
	

	if(pos>cnt)
	{
		printf("Invalid Position\n");
		exit(0);
	}
	if(pos==1)
	{
		Delete_First(First,Last);
	}

	else if(pos==cnt)
	{
		Delete_Last(First,Last);
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








int Count(PNODE Head,PNODE Tail)
{
	int count=0;
	PNODE temp=Head;
	
	do
	{

		count++;
		Head=Head->next;
	}
	while(Head!=(Tail->next));
	
	return count;
		
}




void Display(PNODE Head,PNODE Tail)
{
	PNODE temp=Head;

	do
	{
		printf("%d\t",Head->data);
		Head=Head->next;
		


	}while(Head!=(Tail->next));

		
} 



