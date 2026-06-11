//DILLON GANPAT 
//816044402 
//COMP 1603 
//ASSIGNMENT 2





#include <iostream>


#include <fstream>


using namespace std;

struct Node {
	
    int data;
    
    Node* next;
};

Node* NUM_ARR[100];


int count = 0;


Node* createNode(int n) {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}







int findLargest(int listnum) {
    Node* top = NUM_ARR[listnum];
    if (top == NULL) {
        cout << "List is empty." << endl;
        
        return 0;
        
    }
	
	    Node* curr = top;
	    int largestInt = curr->data;
	
	    while (curr != NULL) {
	        if (curr->data > largestInt) {
	            largestInt = curr->data;
	        }
	        curr = curr->next;
	  
	  
   }

    return largestInt;
}

void deleteList(int listnum) {
	
    Node* top = NUM_ARR[listnum];
    Node* curr =   top;

    while (curr != NULL) {
    	
        Node* nextNode = curr->next;
        	
			delete curr;
        curr = nextNode;
    }

    NUM_ARR[listnum] = NULL;
}






Node* getLast(Node* top) {
    Node* curr = top;
    Node* last = NULL;



    while (curr != NULL) {
    	
        last = curr;
        curr = curr->next;
    }


    return last;
    
}




Node* insertAtTail(Node* top, int x) {
    Node* newNode = createNode(x);
    Node* lastNode = getLast(top);

    if (lastNode == NULL) {
        top = newNode;
    } else {
        lastNode->next = newNode;
    }


    return top;
}

bool deleteNode(Node*& top, int key) {
    Node* curr = top;
    Node* pred = NULL;

    if (top == NULL) {
        return false; // if list emty
    }

    while (curr != NULL) {
        if (curr->data == key) {
            if (pred == NULL) {
                top = top->next; 
            } else {
                pred->next = curr->next; 
            }
            delete curr;
            return true; //if deletion successful 
        }
        pred = curr;
        curr = curr->next;
    }

    return false; // if key wasnt found
}


void printList(Node* top) {
					    Node* curr = top;
					
					    if (top == NULL) {
					        cout << "List empty." << endl;
					        return;
					    }
					
					    while (curr != NULL) {
					        cout << curr->data << "\t";
					        
					        
					        curr = curr->next;
					    }
					
					    cout << endl;
					}
					
					
					
					
					

Node* insertAtHead(Node* top, int x) {
	
    Node* newNode = createNode(x);
    newNode->next = top;
    top = newNode;
    return top;
}



void mergeLists(int listA, int listB, int listC) {
    Node* currA = NUM_ARR[listA];
    Node* currB = NUM_ARR[listB];
    Node* currC = NUM_ARR[listC]; 
    
    
    Node* newList = NULL;

    while (currA != NULL) {
        newList = insertAtTail(newList, currA->data);
        currA = currA->next;
    }

    while (currB != NULL) {
        newList = insertAtTail(newList, currB->data);
        currB = currB->next;
    }

    while (currC != NULL) {
        newList = insertAtTail(newList, currC->data);
        currC = currC->next;
    }




    NUM_ARR[listC] = newList;
}






void sumMultiplesOfFive() {
    int sum = 0;

    for (int i = 1; i <= NUM_ARR[0]->data; i= i +1) {
        Node* curr = NUM_ARR[i];
        while (curr != NULL) {
            if (curr->data % 5 == 0) {
                sum += curr->data;
            }
            curr = curr->next;
        }
    }

    cout << "The sum of all multiples of 5 in all the lists is: " << sum << endl;
    cout << endl;
}





void findIntersection(int listX, int listY, int listZ) {
	
    Node* currX = NUM_ARR[listX];
    Node* currY;
    NUM_ARR[listZ] = NULL;



    while (currX != NULL) {
    	
        currY = NUM_ARR[listY];
        
        while (currY != NULL) {	
            if (currX->data == currY->data) {
	            	
	                NUM_ARR[listZ] = insertAtTail(NUM_ARR[listZ], currX->data);
	                break;
	            }
            
            
            currY = currY->next;
        }
        
        currX = currX->next;
    }

    if (listZ > NUM_ARR[0]->data) {
        NUM_ARR[0]->data = listZ;
    }
}






void sumList(Node* NUM_ARR[], int listNum) {
    Node* curr = NUM_ARR[listNum];
    int sum = 0;

    while (curr != NULL) {
        sum = sum + curr->data;
        curr = curr->next;
    }

    NUM_ARR[listNum] = insertAtTail(NUM_ARR[listNum], sum);
    
    cout << "Insertion of list sum at the end of the list successful." << endl;
    cout << endl;
}






void printAllLists() {
    if (NUM_ARR[0] == NULL) return;
    cout << "Number of lists: " << NUM_ARR[0]->data << endl;
    cout << endl;

    cout << "Printing all lists ..." << endl;
    for (int i = 1; i <= NUM_ARR[0]->data; i++) {
        cout << "Printing list " << i << " ..." << endl;
        printList(NUM_ARR[i]);
        cout << endl;
    }
}




void processCommands(ifstream& file) {
    char command;
    
    int param1, param2, param3;
    
    while (file >> command) {
    	
        if (command == '$') {
        	
            cout << "Commands file read successfully." << endl;
            return;
            
            
        }
        

        cout << "Processing Command: " << command;
        if (command == 'G' || command == 'X' || command == 'P' || command == 'S') {
            file >> param1;
            cout << " " << param1;
            
            
        } 
        
		else if (command == 'A' || command == 'H' || command == 'D') {
            file >> param1 >> param2;
            cout << " " << param1 << " " << param2;
            
        }
		 else if (command == 'M' || command == 'I') {
            file >> param1 >> param2 >> param3;
            cout << " " << param1 << " " << param2 << " " << param3;
        }
        
        
        cout << endl;

        if (command == 'G') {
            cout << "The largest integer in list " << param1 << " is " << findLargest(param1) << "." << endl;
            cout << endl;
            
            
            
            
        } 
		else if (command == 'X') {
            deleteList(param1);
            cout << "Deleting list " << param1 << "..." << endl;
            
            cout << "List " << param1 << " deleted." << endl;
            cout << endl;
            
            
            
        } 
		else if (command == 'A') {
            NUM_ARR[param1] = insertAtTail(NUM_ARR[param1], param2);
            cout << "Inserting " << param2 << " at the end of list " << param1 << "..." << endl;
            cout << "Insertion of " << param2 << " successful." << endl;
            cout << endl;
            
            
            
        } 
		else if (command == 'D') {
            cout << "Attempting deletion of " << param2 << " in list " << param1 << "..." << endl;
            bool deleted = deleteNode(NUM_ARR[param1], param2);
            if (deleted) {
                cout << "Deletion of " << param2 << " successful." << endl;
            } 
			else {
                cout << "The key " << param2 << " was not found. Nothing to delete ..." << endl;
          
		    }
            cout << endl;
        } 
		
		
		
		
		
		else if (command == 'P') {
            cout << "Printing list " << param1 << " ..." << endl;
            printList(NUM_ARR[param1]);
            cout << endl;
        } 
		
		else if (command == 'Q') {
            printAllLists();
        } 
		
		
		else if (command == 'H') {
            NUM_ARR[param1] = insertAtHead(NUM_ARR[param1], param2);
            cout << "Inserting " << param2 << " at the head of list " << param1 << "..." << endl;
            cout << "Insertion of " << param2 << " successful." << endl;
            cout << endl;
        } 
		
		
		
		
		else if (command == 'M') {
            mergeLists(param1, param2, param3);
            cout << "Merging list " << param1 << ", list " << param2 << " and list " << param3 << " ..." << endl;
            cout << "Merging lists successful." << endl;
            cout << endl;
        }
		
		
		
		
		
		 else if (command == 'V') {
            sumMultiplesOfFive();
        } 
		
		
		
		
		
		else if (command == 'I') {
            findIntersection(param1, param2, param3);
            cout << "Insertion of intersection of lists " << param1 << " and " << param2 << " at location " << param3 << " successful." << endl;
            cout << endl;
        }
		
		
		 else if (command == 'S') {
            sumList(NUM_ARR, param1);
            cout << "Insertion of list sum at the end of the list successful." << endl;
            cout << endl;
        } 
		
		
		else {
            cout << "Unknown command: " << command << endl;
        }
    }
		}	
		
		
int main() {
    ifstream inputFile("asg2.txt");
    
    if (!inputFile) {
    	
        cout << "Error opening file. aborting...";
        return 1;
    }

    cout << "Reading in lists ..." << endl;
    int listNum, data;
    int maxListNum = 0;
    

    while (inputFile >> listNum && listNum != -999) {
        if (listNum > maxListNum) {
        	
            maxListNum = listNum; 
        }
        while (inputFile >> data && data != -1) {
            NUM_ARR[listNum] = insertAtTail(NUM_ARR[listNum], data);
        }
        count= count +1; 
    }

    NUM_ARR[0] = new Node();
    NUM_ARR[0]->data = maxListNum; 
    

    cout << "Reading in lists successful." << endl;
    cout << endl;

    cout << "Processing commands ..." << endl;
    cout << endl;

    processCommands(inputFile);

    inputFile.close();

    
    for (int i = 0; i < sizeof(NUM_ARR) / sizeof(NUM_ARR[0]); i++) {
        deleteList(i);
    }

    delete NUM_ARR[0];
    return 0;
}

