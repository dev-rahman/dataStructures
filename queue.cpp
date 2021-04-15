#include<iostream>
using namespace std;
int count, size;

struct Node{
  int data;
  Node* next;
  Node(int value){
    data = value;
  };
};

Node* head;
Node* tail;
Node* curr;

//LIFO in stack
//FIFO in Queue

//to insert element at last
void enQueue(int data){
  Node* newNode = new Node(data);

  if(head == NULL){
    newNode->next = NULL;
    head = newNode;
    tail = newNode;
    count++;
  }
  else{
    tail->next = newNode;
    tail = newNode;
    tail->next = NULL;
    count++;
  }
};

//To delete first element
int deQueue(){
  if(head == NULL){
    cout << "Queue is already Empty!";
  }
  else{
    curr = head->next;
    delete(head);
    head = curr;
    count--;
    cout << "DeQueued!";
    
  }
};

//show first element without removing it
void peek(){
  if(head == NULL){
    cout << "Queue is Empty :(";
  }
  else{
    cout <<  head->data << "\nPeeked!";
  }
};

void isEmpty(){
  if(head == NULL){
    cout << "Queue is Empty :(";
  }
  else{
    cout << "Queue is Not Empty ;)";
  }
};

void isFull(){
  if(count == size){
    cout << "Queue is Full :(";
  }
  else{
    cout << "Queue is Not Full :)";
  }
};

void display(){
  curr = head;
  while(curr != NULL){
    cout << curr->data;
    curr = curr->next;
  }
}


main(){
  int choice;
  int data;
  cout << "How many Values you wanna insert in the Queue: ";
  cin >> size;
  cout << "1: Enter The Element in Queue. ";
  cout << "\n2: Delete The Element from Queue. ";
  cout << "\n3: To Peek Queue: ";
  cout << "\n4: To Check Queue is Empty Or Not.";
  cout << "\n5: To Check Queue is Full Or Not.";

  while(true){
    cout << "\n\nEnter Choice: ";
    cin >> choice;

    switch(choice){
      case 1:
        if(count < size){
          cout << "Enter The Value: ";
          cin >> data;
          enQueue(data);
          display();
          break;
        }
        else{
          cout << "Queue is Already Full!";
          break;
        }
      case 2:
        deQueue();
        display();
        break;
      case 3:
        peek();
        break;
      case 4:
        isEmpty();
        break;
      case 5:
        isFull();
        break;
      default:
        cout << "\nEnter Appropriate Choice :(";
    }
  }
}
