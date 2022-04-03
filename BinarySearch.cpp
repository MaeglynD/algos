#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
  int l = 0, r = nums.size()-1;

  while(l <= r) {
    int m = ((r-l)/2)+l;

    if (nums[m] == target) {
      return m;
    }

    if (nums[m] < target) {
      l = m+1;
    } else {
      r = m-1;
    }
  }

  return -1;
}

int main() {
  vector<int> test = {10, 20};

  cout << binarySearch(test, 20) << endl;
  cout << binarySearch(test, 40) << endl;

  return 0;
}