#include <iostream>
#include <vector>
using namespace std;

vector<int>duplicate (vector<int>& a, vector<int>& b)
{
    vector <int> ab;
    if (a.size()==b.size()|| a.size()>b.size()) //if same size or size a > size b, loop goes through a
    {
        for (int i=0; i<(int)a.size(); i++)
        {
            vector<int>::iterator it = find(b.begin(), b.end(), a[i]); //try to find element a[i] in b
            if(it!=b.end()) //if iterator isn't at the end, then a[i] was found in b, so push to new vector
            {
                ab.push_back(a[i]);
            }
        }
    }
    else if (a.size()<b.size()) //same as above but for when size b > size a
    {
        for (int i=0; i<(int)b.size(); i++)
        {
            vector<int>::iterator it = find(a.begin(), a.end(), b[i]);
            if(it!=a.end())
            {
                ab.push_back(b[i]);
            }
        }
    }
    return ab;
}
int main()
{
    vector <int> x = { 0, 1, 2, 3 }; //sample vectors
    vector <int> y = { 0, 2, 3, 4, 6, 1 };

    vector <int> xy = duplicate(x, y); //vector to store the duplicates

     cout <<"Duplicares are: "<<endl; //print out the duplicates
    for (int i=0; i < (int)xy.size(); i++)
    {
        if (i!=xy.size()-1)
        {
            cout << xy[i]<< ", ";
        }
    }
    cout << xy[xy.size()-1] << endl;
    return 0;
}