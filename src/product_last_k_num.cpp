// 1352. Product of the Last K Numbers

#include <iostream>
#include <vector>

using namespace std;

class ProductOfNumbers 
{
public:
    ProductOfNumbers() 
    {
    }
    
    void add(int num) 
    {
        if (num) prefixProduct.push_back(prefixProduct.back() * num);
        else prefixProduct = {1};
    }
    
    int getProduct(int k) 
    {
        const int n = prefixProduct.size();
        return k >= prefixProduct.size() ? 0 : prefixProduct.back() / prefixProduct[n - 1 - k];
    }
    
private:
    vector<int> prefixProduct = {1};
};


int main()
{
    return 0;
}