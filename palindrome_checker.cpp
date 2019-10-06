#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool pali(const string& word, vector<char>& p, int index)
{
    //if the character from our backwards stored word doesn't match the
    //character of the original word at the specified index, then 
    //we don't have a palindrome
    if (p[index] != word[index])
    {
        return false;
    }
    else if (index == word.size()-1) //if we reach the end, then we do have a palindrome
    {
        return true;
    }
    return (pali(word, p, ++index)); //recursive call to keep parsing thru the word and vector

}

int main()
{
    string word;
    cin >> word;

    vector <char> palindrome;

    //store the word backwords in a char vector
    for (int i=0; i < word.size(); i++)
    {
        palindrome.push_back(word[word.size()-1-i]);
    }
    
    //stores a boolean result that tells if the word is a plaindrome with pali function
    bool a_palindrome = pali(word, palindrome, 0);

    //print the result we got from pali function
    cout << word << "is a palindrome: "<< boolalpha << a_palindrome << endl;
    
    return 0;
}