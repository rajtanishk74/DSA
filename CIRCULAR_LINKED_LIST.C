#include<stdio.h>
#include<stdlib.h>
//node structure
struct Node{
	int data;
	struct Node*next;
};
//function to create a new node
struct Node* createNode(int data){
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}
//function to insert a node at the end of the circulaar linked list
void insertAtEnd(struct Node**head,int data){
	struct Node*newNode=createNode(data);
	if(*head==NULL){
		*head=newNode;
		newNode->next=*head;
		return;
	}
	struct Node*temp=*head;
	while(temp->next!=*head){
		temp=temp->next;
	}
	temp->next=newNode;
	newNode->next=*head;
}
//function to delete a node from the circular linked list
void deleteNode(struct Node**head,int key){
	if(*head==NULL){
		printf("list is empty.\n");
		return;
	}
	struct Node*temp=*head,*prev;
	if(temp->data==key && temp->next==*head){
		free(temp);
		*head=NULL;
		return;
	}
	// if head needs to be removed
	if(temp->data==key){
		while(temp->next!=*head){
			temp=temp->next;
		}
		temp->next=(*head)->next;
		free(*head);
		*head=temp->next;
		return;
	}
	// find the key to be deleted
	while(temp->next!=*head && temp->data!=key){
		prev=temp;
		temp=temp->next;
	}
	// if node not found
	if(temp->data!=key){
		printf("Node not found.\n");
		return;
	}
	prev->next=temp->next;
	free(temp);
}
//function to display the circular linked list
void display(struct Node*head){
	if(head==NULL){
		printf("list is empty.\n");
		return;
	}
	struct Node*temp=head;
	do{
		printf("%d",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");
}
//main function
int main()
{
	struct Node*head=NULL;
	insertAtEnd(&head,10);
	insertAtEnd(&head,20);
	insertAtEnd(&head,30);
	insertAtEnd(&head,40);
	
	printf("circular Linked list: ");
	display(head);
	printf("Deleting 20...\n");
	deleteNode(&head,20);
	printf("updated circular linked list: ");
	display(head);

    printf("Deleting 10...\n");
	deleteNode(&head,10);
	printf("updated circular linked list: ");
	display(head); 	
	
	return 0;
}







