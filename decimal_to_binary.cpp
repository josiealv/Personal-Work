#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main ()
{
    int decimal;
    cout << "Type in a number to convert to binary"<< endl;
    cin >> decimal;

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
        vector <int> binary;
        int i=decimal;
        while (i != 1)
        {
            if (i%2 == 0)
            {
                binary.push_back(0);
            }
            else if (i%2 != 0)
            {
                binary.push_back(1);
            }
            i/=2;
        } 
        binary.push_back(1);
        for (int j=0; j < binary.size(); j++)
        {
            cout << binary[j];
        }
    }
    cout << endl;

    return 0;
}