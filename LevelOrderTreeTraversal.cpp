#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int v) {
    int data = v;
    left = right = nullptr;
  }
};

class Solution {
  public: 
    vector<int> levelOrderTraversal(Node* node) {
      if (!node) return {};

      vector<int> ans;
      queue<Node*> q;

      q.push(node);

      while(!q.empty()) {
        node = q.front();

        if (node) {
          ans.push_back(node->data);
          q.push(node->left);
          q.push(node->right);
        }

        q.pop();
      }

      return ans;
    }
};

int main() {

  return 0;
}