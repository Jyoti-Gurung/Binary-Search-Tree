/*
Name: Jyoti Gurung
Period: 1
Project: Binary Search Tree; Add & look up numbers, print them of course as well
*/

#include <iostream>

using namespace std;

struct node { 
	int data; 
	node *left; 
	node *right; 
};

//Just Initialize Functions up here
node * add(node* & root, int & data);
void peek(node *root, int data, bool & found);
void print(node *root, int space);

int main(){
  
  node * root;
  root = NULL;
  int count = 0; //Max 100 Numbers allowed
  char action;
  bool found = false;

  while (true) {
    
    cout << endl << "Type A to Add, B to Peek, and C to Print" << endl;
    cin >> action;

    switch (action) {

      //ADD
      case 'A':

        cout << "Enter #: ";
        int input;
        cin >> input;

        if (input > 999 || input <= 0) {
          cout << "INVALID: Enter a # between 1-999!" << endl;
          break;
        }
        if (count > 100) {
          cout << "100 #s Max" << endl;            
          break;
        }

        count++;
        add(root, input);
        break;

      //PEEK
      case 'B':
        cout << "Enter # to peek: ";
        int inputPeek;
        cin >> inputPeek;
        peek(root, inputPeek, found);

        if (found == true) {
          cout << inputPeek << " Found!" << endl;
        }

        else {
          cout << inputPeek << " not Found!" << endl;
        }
        
        break;
      
      //PRINT
      case 'C':
        print(root, 0);
        break;
      
    }
  
  }  
  
}

//ADD
node * add(node* & root, int & data) {
  //When it's the first time, or when root node is NULL you create a new node and add data to it, & create left & right nodes
  if(root == NULL) {
    root = new node;
    root->data = data;
    root->right = NULL;
    root->left = NULL;
  }
  //When data is greater than "root" then add to the right branch recursively
  else if(root->data < data) {
    root->right = add(root->right,data);
  }
  //When data is smaller than "root" then add to left branch recursively
  else {
    root->left = add(root->left,data);
  }
  return root; 
}

//PEEK
void peek(node *root, int data, bool & found)
{

  //When root is NULL or found(matching) is true, return and peek at right node
  if (root == NULL || found == true) {
    return;
    peek(root->right, data, found);
  }

  //If "root's" data matches input data then found is true
  if(root->data == data) {
    found = true;
  }

  //Look at if statement just above; once "root" matches then we peek at left of it
  peek(root->left, data, found);
  
  //If "root's" data matches input data then found is true
  if(root->data == data) {
    found = true;
  }

}

//PRINT
void print(node *root, int space) {

    if (root == NULL) {
      return;
    }
 
    //IMPORTLANT FOR VISUALS: Sideways screen height/width - Tab 1 - Keep += # same as Tab 2
    space += 10;
 
    // Process right child FIRST
    print(root->right, space);
 
    // Print current node after SPACE
    cout << endl;
    //IMPORTANT FOR VISUALS: Sideways screen width/height - Tab 2 - Keep i # same as Tab 1
    for (int i = 10; i < space; i++) {
      cout << " ";
    }
    cout << root->data << endl;
 
    // Process left child SECOND
    print(root->left, space);
  
}

/*
Sources:
https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/: code for printing stuff
Aneeq Chowdhury: to smoothen out add & peek
*/