#include <bits/stdc++.h>
using namespace std;



struct node{
	node* prev;
	int text;
	node* next;
};

node* start = NULL;
void insert(int text){
	node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->text = text;
	newNode->next = start;
	newNode->prev = NULL;
	if(start != NULL){
		start->prev = newNode;
	};
	start = newNode;
}

void printFoward(){
	node* ptr = start;
	cout << "PRINT FOWARD=====\n";
	while(ptr != NULL){
		cout << ptr->text << endl;
		ptr = ptr->next;
	}
}

void printBackward(){
	node* ptr = start;
	cout << "PRINT BACKWARD=====\n";
	while(ptr != NULL){
		node* temp = ptr;
		ptr = ptr->next;
		if(ptr == NULL){
			while(temp != NULL){
				cout << temp->text << endl;
				temp = temp->prev;
			}
		}
	}
}

void insertAtEnd(int text){
	node* ptr = start;
	node* newNode = (struct node*) malloc(sizeof(struct node));
	cout << "INSERT AT END=====\n";
	while(ptr != NULL){
		node* temp = ptr;
		ptr = ptr->next;
		if(ptr == NULL){
			newNode->text = text;
			newNode->prev = temp;
			newNode->next = NULL;
			temp->next = newNode;
		}
	}
}

void deleteAt(int text){
	node* ptr = start;
	while(ptr != NULL){
		if(ptr->text == text){
			node* temp = ptr;
			node* prevOf = temp->prev;
			node* nextOf = temp->next;
			prevOf->next = nextOf;
			nextOf->prev = prevOf;
			ptr = nextOf;
			delete temp;
		}
		ptr = ptr->next;
	}
}

void insertAt(int text,int newText){
	node* ptr = start;
	node* newNode = (struct node*) malloc(sizeof(struct node));
	while(ptr != NULL){
		if(ptr->text == text){
			node* nextOf = ptr->next;
			newNode->text = newText;
			newNode->prev = ptr;
			newNode->next = nextOf;
			nextOf->prev = newNode;
			ptr->next = newNode;
			ptr = newNode;
		}
		ptr = ptr->next;
	}
}

int main(){
	int text;
	int isCont =  1;

	while(isCont != 0){
		cin >> text;
		cout << "Exit? [YES: 1, NO: 0]\n";
		insert(text);
		cin >> isCont;
	}
	printFoward();
	printBackward();
	cout << "Enter number to insert at the end: \n";
	cin >> text;
	insertAtEnd(text);
	printFoward();
	printBackward();
	cout << "Enter number that you want to delete: \n";
	cin >> text;
	deleteAt(text);
	printFoward();
	printBackward();
	cout << "Enter number at which you want to insert ? \n";
	cin >> text;
	int newNum;
	cout << "Enter new number : \n";
	cin >> newNum;
	insertAt(text,newNum);
	printFoward();
	printBackward();
	return 0;
}