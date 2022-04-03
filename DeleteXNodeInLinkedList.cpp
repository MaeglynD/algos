#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node* next;
};

Node* deleteNode(Node *head, int x) {
  if (!head) return head;
  if (x == 1) return head->next;   

  Node *prev, *cur = head;
  
  for (int i = 1; i < x; ++i) {
    prev = cur;
    cur = cur->next;

    if (!cur) {
      return head;
    }
  }

  prev->next = cur->next;
}

int main() {
  // 
  return 0;
}
