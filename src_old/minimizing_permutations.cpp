#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_set>
#include <sstream>

// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
vector<int> reverse(const vector<int>& v, int s, int e)
{
  vector<int> res(v);
  while (s < e) 
  {
      swap(res[s], res[e]);
      ++s; --e;
  }
  return res;
}

bool isSorted(const vector<int> v)
{
  const int n = v.size();
  for (int i = 0; i < n - 1; ++i)
  {
    if (v[i] != v[i+1] - 1) return false;
  }
  return true;
}

string tostr(const vector<int>& v)
{
  stringstream ss;  
  for (const auto& i : v)
  {
    ss << i << "-";
  }
  return ss.str();
}

int minOperations(vector <int> arr) {
  // Write your code here
  queue<pair<vector<int>, int>> q;
  unordered_set<string> visited;
  const int n = arr.size();
  
  q.push({arr, 0});
  
  while (!q.empty())
  {
    auto p = q.front();
    q.pop();
    string s = tostr(p.first);
    cout << "s: " << s << "\n";
    if (visited.count(s)) continue;
    visited.insert(s);
    
    for (int i = 0; i < n; ++i)
    {
      for (int j = i + 1; j < n; ++j)
      {
        auto v = reverse(p.first, i, j);
        if (isSorted(v)) return p.second + 1;
        q.push({v, p.second + 1});
      }
    }
  }
  
  return -1;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!
void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected); 
    cout << " Your output: ";
    printInteger(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  /*int n_1 = 5;
  vector <int> arr_1{1, 2, 5, 4, 3};
  int expected_1 = 1;
  int output_1 = minOperations(arr_1);
  check(expected_1, output_1);*/

  int n_2 = 3;
  vector <int> arr_2{3, 1, 2};
  int expected_2 = 2;
  int output_2 = minOperations(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}