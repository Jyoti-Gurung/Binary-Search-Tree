/*
Name: Jyoti Gurung
Period: 1
Project: Binary Search Tree; Add, Remove and look up numbers
*/

#include <iostream>

using namespace std;

// Set up functions up here; fleshed out under main 
void display(int * input, int size, int depth, int control);
void peak(int * input, int size);
void deleted(int * input, int size);

int main(){
  
  int storage[100]; // 100 numbers storage
  int count = 0; // Amount of actual numbers in storage
  char action;

  while (true) {
    
    cout << "a: Add, b: Peak, c: Delete, d: Print" << endl;
    cin >> action;

    switch (action) {

      //Add
      case 'a':

        int input;
        cin >> input;
        if (input > 999 || input == 0) {
          cout << "Enter a value between 1-999!" << endl;
          break;
        }
        if (count > 100) {
          cout << "Max 100 #s in this heap!" << endl;            break;
        }
        
        count++;
        storage[count-1] = input;
        break;

      //Print
      case 'b':
        peak(storage, count);
        break;
      
      //Print
      case 'c':
        deleted(storage, count);
        break;
      
      //Print
      case 'd':
        display(storage, count, 1, 1);
        break;
      
    }
  
  }  
  
}

// Print out the arrays that is already sorted
void display(int * input, int size, int depth, int control) {
  
  for (int i = 0; i < size; i++) {

    if (input[i] != 0) {
      cout << input[i] << " ";
    }
    
    // If the current slot is equal to depth we bring       it down a line
    if (i+1 == depth) {
      // First, Double Control aka each branch has 2          spots for babies
      control = control * 2;
      // Second, add it to depth, which is collecting         the # of slots from previous depths
      depth = depth+control;
      cout << endl;
    }
  }

  cout << endl;
  
}

void peak(int * input, int size) {
  
  cout << "# you would like to find" << endl;
  int peak;
  cin >> peak;
  for (int i = 0; i < size; i++) {
    if (input[i] == peak) {
      cout << peak << " found" << endl;
    }
  }

  cout << endl;
  
}

void deleted(int * input, int size) {
  
  cout << "# you would like to delete" << endl;
  int deleted;
  cin >> deleted;
  for (int i = 0; i < size; i++) {
    if (input[i] == deleted) {
      
      int temp = i+1;
      int temp2 = i;
      while (size > temp) {
        input[temp2] = input[temp];
        input[temp] = 0;
        temp2++;
        temp++;
      }
      cout << deleted << " deleted" << endl;
    }
  }

  cout << endl;
  
}

/*
Sources:
None
*/