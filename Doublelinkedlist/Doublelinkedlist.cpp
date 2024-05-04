#include <iostream>
using namespace std;

struct Node
{
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

Node* START = NULL;

void addNode()
{
    Node* newNode = new Node(); // step 1: create a new node
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs; // Assign value to the data field of the new node
    cout << "\nEnter the name of the student : ";
    cin >> newNode->name; // Assign velue to the data field of the new node

    // Insert the new node in the List
    if (START == NULL || newNode->noMhs <= START->noMhs)
    { // ste 2: insert the new node at the beginning
        
    }
    
}