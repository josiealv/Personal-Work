#include <vector>
#include <string>
#include <iostream>
using namespace std;
bool pali(const string& word, vector<char>& p, int index)
{
    if (p[index] != word[index])
    {
        return false;
    }
    else if (index == word.size()-1)
    {
        return true;
    }
    return (pali(word, p, ++index));

}

int main()
{
    string word;
    cin >> word;

    vector <char> palindrome;

    for (int i=0; i < word.size(); i++)
    {
        palindrome.push_back(word[word.size()-1-i]);
    }
 
    bool a_palindrome = pali(word, palindrome, 0);

    cout << word << "is a palindrome "<< boolalpha << a_palindrome << endl;
    
    return 0;
}