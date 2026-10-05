#include <iostream>

class Solution {
public:
    void sayHello() {
        std::cout << "Hello, World!" << std::endl;
    }
};

int main() {
    Solution solution;
    solution.sayHello();
    return 0;
}