#include "stack.h"
#include <iostream>
#include <stdexcept>

int main()
{
    stack<int>test = stack<int>();
    test.push(1);
    test.push(2);
    std::cout << test.top()  << " size is "<< test.size()<< '\n';
    test.pop();
    std::cout << test.top()  << " size is "<< test.size()<< '\n';
    return 0;
}
