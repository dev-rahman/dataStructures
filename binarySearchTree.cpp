#include<iostream>
#include<conio.h>
//#include<bits/stdc++.h> //for iterative inOrder method as I used Built-in Stack in line106;

using namespace std;

struct Node{
  int data;
  Node* left; 
  Node* right;
  Node(int value){
    data = value;
    right = NULL;
    left = NULL;
  }
};
 
Node* root;

//iterative
void insert(int value){
  Node* newNode = new Node(value);

  if(root == NULL){
    root = newNode;
    return;
  }
  else{
    Node* curr = root; //start with root node

    while(curr != NULL){

      if(value < curr->data){

        if(curr->left == NULL){
          curr->left = newNode;
          return;
        }
        curr = curr->left;
      }
      else{

        if(curr->right == NULL){
          curr->right = newNode;
          return;
        }
        curr = curr->right;
      }
    }
  }
};

//iterative
bool find(int value){
  Node* curr = root;
  while(curr != NULL){
    if(value < curr->data){
      curr = curr->left;
    }
    else if(value > curr->data){
      curr = curr->right;
    }
    else{
      return true;
    }
  }
  return false;
};

//depthFirst Methods

//recursive
void preOrder(Node* root){
  if(root == NULL)
    return;
  else{
    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
  }
};

//recursive
void inOrder(Node* root){
  if(root == NULL)
    return;
  else{
    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
  }
};

//recursive
void postOrder(Node* root){
  if(root == NULL)
    return;
  else{
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
  }
};

/*Iterative Approach:
void inOrder(Node* root){
  stack<Node *> s;

  Node* curr = root;

  while(!s.empty() || curr != NULL){
    while(curr != NULL){
      s.push(curr);
      curr = curr->left;
    }
    curr = s.top();
    s.pop();

    cout << curr->data << " ";
    curr = curr->right;
  }
 }
*/

int height(Node* root){
  if(root == NULL){
    return -1;
  }
  else{
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
  }
};

/*
//iterative
int findMin(Node* root){
  Node* curr = root;
  while(curr->left != NULL){
    curr = curr->left;
  }
  return curr->data;
};
*/

//recursive
int findMin(Node* root){
  if(root->left == NULL){
    return root->data;
  }
  findMin(root->left);
};

//recursive
int findMax(Node* root){
  if(root->right == NULL){
    return root->data;
  }
  findMax(root->right);
};

main(){
  int choice, enteredvalue, valueToSearch;
  cout << "\n1: To Enter The Value in BST.";
  cout << "\n2: Pre-Order Traversal.";
  cout << "\n3: In-Order Traversal.";
  cout << "\n4: Post-Order Traversal.";
  cout << "\n5: To search an Element.";
  cout << "\n6: To check height of tree.";
  cout << "\n7: To Find Minimum value: ";
  cout << "\n8: To Find Maximum value: ";

  while(true){
    cout << "\n\nEnter Choice: ";
    cin >> choice;

    switch(choice){
      case 1:
        cout << "Enter Value: ";
        cin >> enteredvalue;
        insert(enteredvalue);
        break;
      case 2:
        cout << "Pre-Order Traversal is: ";
        preOrder(root);
        getch();
        break;
      case 3:
        cout << "In-Order Traversal is: ";
        inOrder(root);
        getch();
        break;
      case 4:
        cout << "Post-Order Traversal is: ";
        postOrder(root);
        getch();
        break;
      case 5:
        cout << "Enter Value to search: ";
        cin >> valueToSearch;
        if(find(valueToSearch)){
          cout << "Value Found!";
        }
        else{
          cout << "Value Not Found!";
        }
        break;
      case 6:
        cout << "Height of tree is " << height(root);
        break;
      case 7:
        cout << "Minimum Value is: " << findMin(root);
        break;
      case 8:
        cout << "Maximum Value is: " << findMax(root);
        break;
    }
  }

}