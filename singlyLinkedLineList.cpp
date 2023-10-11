#include <iostream>
#include <ctime>

using namespace std;

struct Node {
	int data;
	Node *next;
};

Node *createNode(int data);
void pushForward(Node *&head, int data);
void pushBack(Node *&tail, int data);
void deleteForward(Node *&head);
void deleteBack(Node *head, Node *&tail);
void outputList(Node *head);

int main() {
	srand(time(NULL));

	Node *head, *tail;
	head = tail = nullptr;
	
	head = tail = createNode(rand() % 90);

	for (int i = 0; i < 10; i++) {
		pushBack(tail, rand() % 90);
	}
    outputList(head);
	cout << endl;

	pushForward(head, rand() % 90);
	outputList(head);
	cout << endl;

	deleteBack(head, tail);
	deleteBack(head, tail);
	deleteBack(head, tail);
	outputList(head);
	cout << endl;

	deleteForward(head);
	outputList(head);
	cout << endl;
}

Node *createNode(int data) {
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;
	return newNode;
}

void pushForward(Node *&head, int data) {
	Node *newNode = createNode(data);

	if (head == nullptr) {
		head = newNode;
		return;
	}

	newNode->next = head;
	head = newNode;
}

void pushBack(Node *&tail, int data) {
	Node* newNode = createNode(data);

	if (tail == nullptr) {
		tail = newNode;
		return;
	}

	tail->next = newNode;
	tail = newNode;
}

void deleteForward(Node *&head) {
	if (head == nullptr) {
		return;
	}

	Node *nextEl = new Node;
	nextEl = head->next;
	delete head;
	head = nextEl;
}

void deleteBack(Node *head, Node*& tail) {
	if ((head == nullptr) || (tail == nullptr)) {
		return;
	}

	Node *current = new Node;
	current = head;
	while (current->next != tail) {
		current = current->next;
	}

	current->next = nullptr;
	delete tail;
	tail = current;
}

void outputList(Node *head) {
	Node *currentNode = head;

	while (currentNode != nullptr) {
		cout << currentNode->data << "\t";
		currentNode = currentNode->next;
	}
	cout << endl;
}