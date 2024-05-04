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
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers allowed\033[0m" << endl;
            return;
        }
        // if the list is empty, make the new node the START
        newNode->next = START; // step 3: make the new node point to the first node
        if (START != NULL)
        {
            START->prev = newNode; // step 4: maek the first node point to the new node

        }
        newNode->prev = NULL; // step 5: make the new node point to NULL
        START = newNode; // step 6: make the new node the first node
    }
    else
    {
        // insert the new node in the middle or at the end
        Node* current = START; //step 1.a: start from the first node
        Node* previous = NULL; // step 1.b: previous node is NULL initially
        while (current != NULL && current->noMhs < newNode->noMhs)
        {                       // step 1.c: traverse the list to find the correct position
            previous = current; // step 1.d: move the previous to the current node
            current = current->next; // step 1.e: move the current to the next node

        }

        newNode->next = current; // step 4: make tthe nest field of the new node point to current
        newNode->prev = previous; // step 5: make the previous field of the new node point to previous'

        if (current != NULL)
        {
            current->prev = newNode; // step 6: make the previous field of the current node point to the new nod

        }

        if (previous != NULL)
        {
            previous->next = newNode; // step 7: make the next field of the previous node point to the new node

        }
        else
        {
            // if previous is still NULL, it means newNode is now the first node
            START = newNode;

        }
    }
}

bool search(int rollNo, Node** previous, Node** current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;

    }
    return (*current != NULL);
}

void deleteNode()
{
    Node* previous, * current;
    int rollno;

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollno;

    if (START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    current = START;
    previous = NULL;

    while (current != NULL && current->noMhs != rollno)
    {
        previous = current;
        current = current->next;
    }

    if (current == START)
    {
        START = START->next;
        if (START != NULL)
        {
            START->prev = NULL;
        }

    }
    else
    {
        previous->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = previous;
        }
    }

    delete current;
    cout << "\x1b[32mRecord with roll number" << rollno << "deleted\x1b[0m" << endl;



}

bool listEmpty()
{
    return (START == NULL);
}

void traverse()
{
    if (listEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecords in ascending order of roll number are:" << endl;
        Node* currentNode = START; // Step 1
        while (currentNode != NULL) // step 2
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl; //step 3
            currentNode = currentNode->next;                                //step 4

        }
    }

}