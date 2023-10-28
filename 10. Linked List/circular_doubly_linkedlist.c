//circular doubly linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node*prev;
	int info;
	struct node*next;

}node;
//get node
node *getnode()
{
	node *p;
	p=(node*)malloc(sizeof(node));
	return p;
}
//insertbeg
void insertbeg(node**cdlist,int x)
{
	node *p,*q;
	p=getnode();
	p->info=x;
	if(*cdlist==NULL)
	{
		p->prev=p->next=p;
		*cdlist=p;
	}
	else
	{
		q=(*cdlist)->prev;
		p->next=*cdlist;
		(*cdlist)->prev=p;
		p->prev=q;
		q->next=p;
		*cdlist=p;
	}
}
//insertend
void insertend(node**cdlist,int x)
{
	node *p,*q;
	p=getnode();
	p->info=x;
	if(*cdlist==NULL)
	{
		p->prev=p->next=p;
		*cdlist=p;
	}
	else
	{
		q=(*cdlist)->prev;
		p->next=*cdlist;
		(*cdlist)->prev=p;
		p->prev=q;
		q->next=p;
	}
}
//search function
void search(node** cdlist ,int x)
{
	node *p,*q;
	p=*cdlist;
	q=p->prev;
	while(p!=q&&p->info!=x)
	     p=p->next;
	if(p->info==x)
	    printf(" element found");
    else
	    printf(" element not found");		     
}
//deletnode function
void deletenode(node**cdlist,int x)
{
	node *p,*q;
	p=*cdlist;
	q=p->prev;
	while(p!=q&&p->info!=x)
	     p=p->next;
	if(p->info!=x)
	     printf(" node not present");
	else
	 {
	 	if(p->next==p)
	 	   *cdlist=NULL;
	 	else
		 {
		 	if(p==*cdlist)
		 	   *cdlist=p->next;
		 	(p->prev)->next=p->next;
			 (p->next)->prev=p->prev;   
		}  
		free(p); 
	}     	
} 
//display
void display(node*cdlist)
{
	node*p,*q;
	p=cdlist;
	q=cdlist->prev;
	printf("\n list elements are :\n");
	while(p!=q)
	{
		printf("%d<=>",p->info);
		p=p->next;
	}
	printf("%d<=>",p->info);
	printf("NULL");
 } 
void main()
 {
 	node *cdlist;
 	int ch ,x;
 	cdlist=NULL;
 	printf("circular doubly linked list is :");
 	do 
 	{
 		printf(" \n 1.insertbeg 2.insertend 3.search 4. deletenode 5 .exit");
 		printf("\n enter your choice");
 		scanf("%d",&ch);
		 switch(ch)
		 {
		 	 case 1: printf("\n enter element to add in the beginning :");
		 	         scanf("%d",&x);
		 	 		 insertbeg(&cdlist,x);
		 	  	     display(cdlist);
		 	  		 break;
		 	 case 2: printf("\n enter element to add in the end :");
		 	         scanf("%d",&x);
		 	 		 insertend(&cdlist,x);
		 	  	     display(cdlist);
		 	  		 break;
			 case 3 :printf(" enter the element to be searched");
			         scanf("%d",&x);
					 search(&cdlist,x);
					 display(cdlist);
					 break;
					 
			 case 4 : printf(" element to delete");
			          scanf("%d",&x);
			          deletenode(&cdlist,x);
			          display(cdlist);
					  break;
			 case 5 : printf(" thank you ");
			          break;
			 default : printf(" invalid choice ");
			           break;		   		  		  					 			 		
			  }	
	 }
	 while(ch>=1&&ch<=4);
 }


