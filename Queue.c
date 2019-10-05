#include<stdio.h>
#include<stdlib.h>
struct QueueNode{
	int value;
	struct QueueNode *next;
};
struct QueueNode *Front = NULL;
struct QueueNode *Rear = NULL;
void Enqueue(int val);
int Dequeue();
void Print();
int main(){
	Enqueue(5);
	Enqueue(10);
	Enqueue(15);
	Enqueue(20);
	Print();
	Dequeue();
	Dequeue();
	Print();
}

void Enqueue(int val){
	struct QueueNode *ptr;
	ptr = (struct QueueNode*) malloc (sizeof(struct QueueNode));
	ptr->next = NULL;
	ptr->value = val;
	
	if(Front == NULL){
		Rear = ptr;
		Front = ptr;
	}else{
//		struct QueueNode *curr = Rear;
//		while(curr->next != NULL){
//			curr = curr->next;
//		}
//		curr->next = ptr;
//		Rear = ptr;

		while(Rear->next!=NULL){
			Rear = Rear->next;
		}
		Rear->next = ptr;
		Rear = ptr;
	}
}

int Dequeue(){
	if(Front == NULL){
		printf("***Queue is Empty***\n");
	}else{
		struct QueueNode *curr = Front;
		printf("Deleted: %d\n",curr->value);
		Front = Front->next;
		free(curr);
	}
}

void Print(){
//	printf("Front = %d\n",Front->value);
//	printf("Rear = %d\n",Rear->value);
	printf("Elements in Queue are: \n");
	if(Front == NULL){
		printf("***Queue is Empty***\n");
	}else{
		struct QueueNode *curr = Front;
		while(curr != NULL){
			printf("%d -> ",curr->value);
			curr = curr->next;
		}
		printf("NULL\n");
	}
	printf("\n");
}
