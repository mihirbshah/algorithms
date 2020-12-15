/*
https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int minPartitions(string n) 
  {
      return *max_element(n.begin(), n.end()) - '0';
  }
};

int main()
{
    return 0;
}