#include <iomanip>
#include <iostream>
using namespace std;
int fib (int n)
{
    if (n==1 || n==0)
    {    
        return n;
    }
    else
    {
        return (fib (n-1) + fib (n-2));
    }
    

}

int main()
{
    int num;
    cout << "Enter which fibonacci number you want to find" << endl;
    cin >> num;

    int fib_n = fib (num);

    cout << "Fibonacci number is: " << fib_n<< endl;
    cout << "The sequence is:" << endl;

    for (int i=0; i<= num; i++)
    {
        cout << fib (i) << endl;
    }
    return 0;
}