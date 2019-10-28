#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main ()
{
    int decimal;
    cout << "Type in a number to convert to binary"<< endl;
    cin >> decimal;

    //if decimal is of log base 2, then just print 1 first and product of (log2 of decimal) - 1 0's 
    if (ceil(log2(decimal)) == floor(log2(decimal))) 
    {
        int x = log2(decimal);

        cout << "1";
        for (int j=x-1; j>=0; j--)
        {
            cout << "0";
        }

    }
    else 
    {
        vector <int> binary; //can't be sure of the amount of binary digits the decimal will have, so we store them in a vector
        int i=decimal; //will be decreminting decimal by a factor of 2 and testing those values to see whether or not they are divisible by 2
        while (i != 1)
        {
            if (i%2 == 0) //the if the current value is divisible by 2, then push 0 to the vector
            {
                binary.push_back(0);
            }
            else if (i%2 != 0) //if not, then push 1 to the vector
            {
                binary.push_back(1);
            }
            i/=2; //decrement the decimal by a factor of 2
        } 
        binary.push_back(1); //1 is the final value left in the decimal, so it's binary digit is just 1 
        for (int j=0; j < binary.size(); j++)
        {
            cout << binary[j];
        }
    }
    cout << endl;

    return 0;
}