#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node(int value){
    data = value;
  }
};

Node* head;
Node* tail;
Node* curr;

//LIFO in stack
//FIFO in Queue

void push(int data){
  Node* newNode = new Node(data);

  if(head == NULL){
    newNode->next = NULL;
    head = newNode;
    tail = newNode;
  }
  else{
    tail->next = newNode;
    tail = newNode;
    tail->next = NULL;
  }
};

void pop(){
  curr = head;

  if(head == NULL){
    cout << "Stack Empty:(";
  }
  else{
    curr = head;
    while(curr != NULL){
      if(curr->next == tail){
        curr->next = NULL;
        tail = curr;
      }
      curr = curr->next;
    }
    cout << "\nElement Popped!\n";
  }
};


int peek(){
  int lastElement;
  curr = head;
  while(curr != NULL){
    if(curr->next == NULL){
      return curr->data;
    }
  	curr = curr->next;
	}
};

main(){
  int a; //for switch statement
  int x; //for data to be entered

  cout << "\n1: To push element in the stack.";
  cout << "\n2: To pop element from the stack.";
  cout << "\n3: To peek element from the stack.";

  while(true){
    cout << "\n\nEnter Your Choice: ";
    cin >> a;

    switch(a){
      case 1:
        cout << "Enter Data: ";
        cin >> x;
        push(x);
        break;
      case 2:
        pop();
        break;
      case 3:
        cout << "Element is: " << peek();
    };
  }
}