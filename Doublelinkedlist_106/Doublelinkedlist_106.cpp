#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int roollNo, Node** previous, Node** current);
	bool deleteNode(int roollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node();	//step 1
	newNode->noMhs = nim;	//step 2
	newNode->name = nm;	//step 2

	/*Insert a node in the beginning of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; //step 3
		if (START != NULL)
			START->prev = newNode;	//step 4
		newNode->prev = NULL;	//step 5
		START = newNode;	//step 6
		return;
	}

	/*inserting a node Between Two Nodes in the List*/
	Node* current = START;	//step 1.a
	Node* previous = NULL;	//step 1.b
	while (current->next != NULL && current->next->noMhs < nim)	//step 1.c
	{
		previous = current;	//step 1.d
		current = current->next;	//1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers no allowed" << endl;
		return;
	}

	newNode->next = current->next;	//step 4
	newNode->prev = current;	//step 5
	if (current->next != NULL)
		current->next->prev = newNode;	//step 6
	current->next = newNode;	//step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = START;	//step 1.a
	*current = START;	//step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) {	//step 1.c
		*previous = *current;	//step 1.d
		*current = (*current)->next;	//step 1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;	//step 2
	if (previous != NULL)
		previous->next = current->next;	//step 3
	else
		START = current->next;

	delete current;	//step 4
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nList is Eempty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}
		
	else {
		cout << "\Records in descending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else 
		cout << "Record with roll number " << rollNo << " deleted " << endl;
}
void DoubleLinkedList::searchData() {
	if (listEmpty() == true) {
		cout << "\nList is Empty" << endl;
	
	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search: ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll Number: " << curr->noMhs << endl;
		cout << "\nName: " << curr->name << endl;
	}
}

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "\n1. Add a record to the list" << endl;
			cout << "\n2. Delete a record from the list" << endl;
			cout << "\n3. View all records in the ascending order of roll numbers" << endl;
			cout << "\n4. View all records in the descending order of roll numbers" << endl;
			cout << "\n5. Search for a record in the list" << endl;
			cout << "\n6. Exit" << endl;
			cout << "\nEnter your choice (1-6): ";
			char ch;
			cin >> ch;
