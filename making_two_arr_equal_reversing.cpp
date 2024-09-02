#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
      vector<int> cnt1(1001);
      vector<int> cnt2(1001);
      for(int& v:target)
      {
        ++cnt1[v];
      }
      for(int& v :arr)
      {
        ++cnt2[v];
      }
       return cnt1 == cnt2;
    }
};
int main() {
    Solution solution;
    vector<int> target = {1, 2, 3, 4};
    vector<int> arr = {2, 4, 1, 3};

    // Output: true
    bool result = solution.canBeEqual(target, arr);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
