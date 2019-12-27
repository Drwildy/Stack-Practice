#include <iostream>
#include<stack>
using namespace std;

//Node Structure
struct Node {
	int data;
	Node* link;
};

//Global Variables 
#define MAX_SIZE 10
int a[MAX_SIZE];
int top = -1;

struct Node* topL = NULL;



//Stacks using Arrays
//Problem that overflow can happen is array is not initialized to be large enough
//Push could check if the array is exhausted and throw an error in case of overflow
//Ideally we use dynamic array and double size if there is an overflow. This is O(n) worst case but still O(1) average and Best case
void ArrayPush(int x);
void ArrayPop();
int ArrayTop();
bool ArrayisEmpty();


void ArrayPush(int x) {
	if (top == MAX_SIZE-1) {
		cout << "OVERFLOW ERROR" << endl;
		return;
	}
	top++;
	a[top] = x;
}

void ArrayPop() {
	if (ArrayisEmpty() == true) return; //if array is empty
	top--;
}

int ArrayTop() {
	return a[top];
}

bool ArrayisEmpty() {
	if (top == -1) return true;
	else return false;
}


//Stack Using Linked List
//Can insert at Tail O(N) or Head O(1)
void ListPush(int x);
void ListPop();
int ListTop();
bool ListisEmpty();


void ListPush(int x) {
	Node* temp = new Node();
	temp->data = x;
	temp->link = topL;
	topL = temp;
}

void ListPop() {
	Node* temp;
	if (topL == NULL) return; // if list is empty
	temp = topL;
	topL = topL->link;
	delete temp;
}

int ListTop() {
	return topL->data;
}

bool ListisEmpty() {
	if (topL == NULL) return true;
	else return false;
	return false;
}

void ReverseLL() {
	
	stack<Node*> S;
	Node* temp = topL;
	while (temp != NULL) {
		S.push(temp);
		temp = temp->link;
	}
	temp = S.top();
	topL = temp;
	S.pop();
	while (!S.empty()) {
		temp->link = S.top();
		S.pop();
		temp = temp->link;
	}
	temp->link = NULL;

}

//C++ Stack from STL
void Reverse(char c[], int n) {
	stack<char> S;

	for (int i = 0; i < n; i++) {
		S.push(c[i]);
	}

	for (int i = 0; i < n; i++) {
		c[i] = S.top();
		S.pop();
	}
}

//Check balanced Parenthesis [()()] Balanced [([)()[] Not Balanced
bool CheckBalancedParenthesis(char P[], int n) {
	stack<char> S;

	for (int i = 0; i < n-1; i++) {
		if (P[i] == '(' || P[i] == '{' || P[i] == '[') { //If Opener
			S.push(P[i]);
		}
		else if (P[i] == ')' || P[i] == '}' || P[i] == ']') { //If Closer
			if (S.empty()) return false; //If Empty it must be unbalanced
			else if (P[i] == ')' && S.top() != '(') return false; //Check if matching if true then exit
			else if (P[i] == '}' && S.top() != '{') return false;
			else if (P[i] == ']' && S.top() != '[') return false;
			else {
				cout << S.top() << " -- " << P[i] << endl;
				S.pop();
			}
		}
	}
	if (S.empty()) return true;
	else return false;
}

int main() {
	ArrayPop();
	ArrayPush(100);
	ArrayPush(-100);
	cout << ArrayTop() << endl;
	ArrayPop();
	cout << ArrayTop() << endl;

	ListPop();
	ListPush(100);
	ListPush(-100);
	cout << ListTop() << endl;
	ListPop();
	cout << ListTop() << endl;
	ListPush(-700);
	ListPush(-800);
	ListPush(900);
	cout << ListTop() << endl;

	char C[50] = { 'h','e','l','l','o' };
	cout << C << endl;
	Reverse(C, strlen(C));
	cout << C << endl;

	ReverseLL();
	cout << ListTop() << endl;

	char P[50] = { '[', ']', '/0'};
	if (CheckBalancedParenthesis(P, strlen(P))) {
		cout << "Balanced" << endl;
	}
	else cout << "Unbalanced" << endl;

	char D[50] = { '[', '(', ')', '}', '/0' };
	if (CheckBalancedParenthesis(D, strlen(D))){
		cout << "Balanced" << endl;
	}
	else cout << "Unbalanced" << endl;
}