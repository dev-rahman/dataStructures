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


void deleteNode(Node* root, int key){
  if(root == NULL) return;

  if(root->data == key){
    delete(root);
    return;
  }

  Node* parentOfCurr = NULL;
  Node* curr = root;

  while(curr != NULL && curr->data != key){
    parentOfCurr = curr;
    curr = (key > curr->data)? curr->right: curr->left;
  }

  //key not found in tree
  if(curr == NULL) return;

  //Case1: node has no children(leaf node).
  if(curr->left == NULL && curr->right == NULL){
    if(parentOfCurr != NULL){
      if(parentOfCurr->left == curr){
        parentOfCurr->left = NULL;
      }
      else{
        parentOfCurr->right = NULL;
      }
    }
    delete(curr);
    return;
  }
  
  //Case2: node has only One children
  else if(curr->left == NULL || curr->right == NULL){
    //if  left child doesnt exist
    Node* newCurr = (curr->left == NULL)? curr->right: curr->left;
    
    // check if the node to be deleted is parentOfCurr's left or right
    // then replace this with newCurr.
    if(parentOfCurr->left == curr){
      parentOfCurr->left =newCurr;
    }
    else if(parentOfCurr->right == curr){
      parentOfCurr->right = newCurr;
    }
    delete(curr);
  }

  //Case3: Node has 2 children
  else if(curr->left != NULL && curr->right != NULL){
    Node* parentOftemp = NULL;
    Node* temp;

    temp = curr->right;
    while(temp->left != NULL){
      parentOfCurr = temp;
      temp = temp->left;
    }

    if(parentOftemp != NULL){
      parentOftemp->left = temp->right;
    }
    else{
      curr->right = temp->right;
    }

    curr->data = temp->data;
    delete(temp);
  }

};

main(){
  insert(7);
  insert(4);
  insert(9);
  insert(1);
  insert(6);
  insert(8);
  insert(10);
  insert(0);


  inOrder(root);

  cout << "\nHeight is: " << height(root);

  cout << "\nminimum value: " << findMin(root);

  cout << "\nmaximum value: " << findMax(root) << endl;
  
  deleteNode(root, 4);


  inOrder(root);

  deleteNode(root, 9);

  inOrder(root);
}
