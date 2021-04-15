#include<iostream>
using namespace std;

int size = size + 1;

struct Node{
  int data;
  Node *next;
  Node(int value){
    data = value;
  }
};

Node* head;
Node* tail;
Node* curr;

void createList(int data){
  Node* newNode = new Node(data);

  if(head == NULL){
    newNode->next = NULL;
    head = newNode;
    tail = newNode;
  }
};

void insertAtLast(int data){
  Node* newNode = new Node(data);

  if(head == NULL){
    cout << "Create the List First:(\n";
  }
  else{
    tail->next = newNode;
    tail = newNode;
    tail->next = NULL;
    size++;
  }
};

void insertAtFirst(int data){
  Node* newNode = new Node(data);

  if(head == NULL && tail == NULL){
    cout << "Create the List First:(\n";
  }
  else{
    newNode->next = head;
    head = newNode;
    size++;
  }
};

void insertAtPosition(int data, int position){
  if(head ==  NULL){
    cout << "Create the List First:(";
  }
  else{
    int pos = 1;
    Node* newNode = new Node(data);
    curr = head;

    while(curr != NULL){
      if(pos == position){
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
      }
      pos++;
      curr = curr->next;
    }
  }
};

void deleteFirst(){
  if(head == NULL){
    cout << "create List Fisrt: ";
  }
  else{
    curr = head->next;
    delete(head);
    head = curr;
    size--;
  }
};

void deleteLast(){
  curr = head;
  if(head == NULL){
    cout << "Create The List First:( \n";
  }
  else if(head->next == NULL){
    delete(head);
  }
  else{
    curr = head;
    while(curr != NULL){
      if(curr->next == tail){
        curr->next = NULL;
        tail = curr;
        size--;
      }
      curr = curr->next;
    }
  }
};

void deleteSpecific(int position){
  if(head == NULL){
    cout << "\nCreate The List First:(";
  }
  else if(position > size){
  	cout << "Your choice is greater than the Size of List:(";
	}
  else{
    int noOfNode = 1;
    Node* temp1;
    Node* temp2;
    curr = head;

    while(curr != NULL){

      if(position-1 == noOfNode){
        temp1 = curr->next;
        temp2 = temp1->next;
        temp1 = NULL;
        curr->next = temp2;
        size--;
      }
      noOfNode++;
      curr = curr->next;
    }
  }
};

int showSize(){
  return size;
};

void search(int value){
  if(head == NULL){
    cout << "\nCreate the List First:(";
  }
  else{
    int count = 0;
    int index = 1;
    curr = head;
    while(curr != NULL){
      if(curr->data == value){
        count++;
        break;
      }
      curr = curr->next;
      index++;
    }
    if(count != 0){
    cout << "Value found at position: " << index << endl;
    }
    else{
      cout << "Value not Found:(";
    }
  }
};

void searchGreater(int value){
  if(head == NULL){
    cout << "Create the List first:(";
  }
  else{
    int count = 0;
    curr = head;
    while (curr != NULL){
      if(curr->data > value){
        count++;
      }
      curr = curr->next;
    }
    if(count != 0){
      cout << "Element/s greater than " << value << "are: " << count << endl;
    }
    else{
      cout << "Nom of the Element is greater:(";
    }
  }
};

void searchSmaller(int value){
  if(head == NULL){
    cout << "Create the List first:(";
  }
  else{
    int count = 0;
    curr = head;
    while (curr != NULL){
      if(curr->data < value){
        count++;
      }
      curr = curr->next;
    }
    if(count != 0){
      cout << "Element/s Smaller than " << value << "are: " << count << endl;
    }
    else{
      cout << "Non of the Element is Smaller:(";
    }
  }
};

void display(){
  if(head == NULL){
    cout << "List is empty:(";
  }
  else{
    curr = head;
    while(curr != NULL){
      cout << curr->data;
      curr = curr->next;
    }
  }
};

main(){
  int a; //for switch statement
  int x; //for data to be inserted1
  cout << "\n0: To close the program.\n";
  cout << "1: Create a List. \n";
	cout << "2: Insert at Start. \n";
	cout << "3: Insert at End. \n";
	cout << "4: Insert at Specific Position. \n";
  cout << "5: Delete First Element. \n";
  cout << "6: Delete Last Element. \n";
  cout << "7: Delete at Specific Position: \n";
  cout << "8: To See The Size of List. \n";
  cout << "9: To search a value.\n";
  cout << "10: To Check how many elements are Greater than a given value.\n ";
  cout << "11: To Check how many elements are Smaller than a given value.\n ";
  cout<<"\t\t---------------------------------\n"<<endl;
  while(true){
    cout << "\n\nEnter Choice: ";
    cin >> a;
    
    switch(a){
      case 1:
        cout << "\nEnter The Value: ";
        cin >> x;
        createList(x);
        cout << "\nList is: ";
				display();
        break;
      case 2:
      	cout << "\nEnter The Value: ";
        cin >> x;
        insertAtFirst(x);
        cout << "\nList is: ";
				display();
        break;
      case 3:
        cout << "\nEnter The Value: ";
        cin >> x;
        insertAtLast(x);
        cout << "\nList is: ";
				display();
        break;
      case 4:
        int po;
      	cout << "\nEnter The Value: ";
        cin >> x;
        cout << "\nEnter The Position: ";
        cin >> po;
        insertAtPosition(x, po);
        cout << "\nList is: ";
				display();
        break;
      case 5:
        cout << "\nEnter The Value: ";
        cin >> x;
        deleteFirst();
        cout << "\nList is: ";
        display();
        break;
      case 6:
        deleteLast();
        cout << "\nList is: ";
        display();
        break;
      case 7:
        int posToDel;
      	cout << "\nEnter The Position: ";
        cin >> posToDel;
        deleteSpecific(posToDel);
        cout << "\nList is: ";
				display();
        break;
      case 8:
        cout << "\nSize of the List is: " << showSize();
        break;
      case 9:
        int searchVal;
        cout << "\nEnter the value you wanna search: ";
        cin >> searchVal;
        search(searchVal);
        break;
      case 10:
        int greaterVal;
        cout << "\nEnter the Value you wanna check: ";
        cin >> greaterVal;
        searchGreater(greaterVal);
        break;
      case 11:
        int smallerVal;
        cout << "\nEnter the Value you wanna check: ";
        cin >> smallerVal;
        searchSmaller(smallerVal);
        break;
    }
  }
}
