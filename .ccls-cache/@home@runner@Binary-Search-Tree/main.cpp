/*
Name: Jyoti Gurung
Period: 1
Project: Binary Search Tree; Add, Remove and look up numbers
*/

#include <iostream>

using namespace std;

struct node { 
	int data; 
	node * left; 
	node * right; 
};

node * add(node* & root, int & data);
void peak(node *root, int data, bool & found);
void print();

int main(){
  
  node * root;
  root = NULL;
  int count = 0; // Amount of actual numbers in storage
  char action;

  while (true) {
    
    cout << "Type A to Add, B to Peak, and C to Print" << endl;
    cin >> action;

    switch (action) {

      //ADD
      case 'A':

        cout << "Enter #: ";
        int input;
        cin >> input;

        if (input > 999 || input == 0) {
          cout << "INVALID: Enter a # between 1-999!" << endl << endl;
          break;
        }
        if (count > 100) {
          cout << "100 #s Max" << endl << endl;            break;
        }

        cout << endl;
        count++;
        add(root, input);
        break;

      //PEAK
      case 'B':
        cout << "Enter # if it's in the tree: ";
        int input2;
        cin >> input2;
        peak(root, input2, booled);
        
        break;
      
      //PRINT
      case 'C':
        
        break;
      
    }
  
  }  
  
}

//ADD
node * add(node* & root, int & data) {
  //when it's the first time, aka when root node is empty you create a new node and add data it it, & create left & right nodes
  if(root == NULL) {
    root = new node;
    root->data = data;
    root->right = NULL;
    root->left = NULL;
  }
  else if(root->data < data) {
    root->right = add(root->right,data);
  }
  else {
    root->left = add(root->left,data);
  }
  return root; 
}

//PEAK
void peak(node *root, int data, bool & found)
{
    if (root == NULL || found == true)
        return;
    peak(root->right, data, found);
    if(root->data == data, data, found) {
      found = true;
    }
    peak(root->left, data, found);
     if(root->data == data) {
      found = true;
    }

}

//PRINT

/*
Sources:

*/