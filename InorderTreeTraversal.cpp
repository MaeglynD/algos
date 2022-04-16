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
    void dfs(Node* n, vector<int>& ans) {
      if (n == nullptr) {
        return;
      }

      dfs(n->left, ans);
      ans.push_back(n->data);
      dfs(n->right, ans);
    }

    vector<int> inOrderTraversal(Node* root) {
      vector<int> ans;

      dfs(root, ans);

      return ans;
    }
};

int main() {

  return 0;
}