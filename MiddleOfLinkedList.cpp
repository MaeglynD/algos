#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node* next; 
	int data; 
};

int getMiddle(Node* head) {
	Node* slow = head;
	Node* fast = head;

	while (fast->next) {
		slow = slow->next;

		if (!fast->next->next) {
			break;
		}

		fast = fast->next->next;
	}
	
	return slow->data;
}

int main(){
	//
	return 0;
}