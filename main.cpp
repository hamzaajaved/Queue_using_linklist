#include <iostream>
#include <stdlib.h>
using namespace std;


struct Node{
  int value;
  struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int val);
void dequeue();
void print();
int main(int argc, char const *argv[])
{
  /* code */
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  print();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  print();
  system("pause");
  return 0;
}


void enqueue(int val){
  struct Node *ptr;
  ptr = (struct Node*) malloc (sizeof(struct Node));
  ptr->next = NULL;
  ptr->value = val;

  if(front == NULL){
    front = ptr;
    rear = ptr;
  }else{
    rear->next = ptr;
    rear = rear->next;
  }
}

void dequeue(){
  if(front == NULL){
    cout << "Queue is Empty" << endl;
  }else{
    struct Node *curr = front;
    cout << "Deleted : " << curr->value << endl;
    front = front->next;
    free(curr);
  }
}


void print(){
  if(front == NULL){
    cout << "Queue is Empty " << endl;
  }else{
    struct Node *curr = front;
    while(curr != NULL){
      cout << curr->value << endl;
      curr = curr->next;
    }
  }
}