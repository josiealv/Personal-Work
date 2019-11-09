#include <iostream>
using namespace std;
struct Node
{
    Node (int v, Node* n) {value=v; next=n;}
    Node* next;
    int value;
};
Node* Merge(Node* u, Node* v)
{
    if (u==NULL && v==NULL) //base case (at the end of both lists)
    {
        return NULL;
    }
    else if (u==NULL) //if u is at the end but not v, append the rest of v to the list 
    {
        v->next=Merge(u, v->next);
        return v;
    }
    else if (v==NULL) //same as above, but for v
    {
        u->next=Merge(u->next, v);
        return u;
    }
    else
    {
        u->next=Merge(v, u->next); //recursively merge u with v
        return u;
    }

}
void print_ll(Node* ll) //regular print function for linked lists
{
    Node* traverse = ll;
    while (traverse!=NULL)
    {
        cout << traverse->value << endl;
        traverse=traverse->next;
    }
}


int main()
{
    Node* u = new Node (1, new Node(2, new Node (3, NULL))); //linked lists examples
    Node* v = new Node (2, new Node(4, new Node (6, NULL)));

    Node* uv = Merge (u, v); //merge the two lists into 2
    print_ll(uv);

    return 0;
}