#include <stdexcept>
template<typename T>
class stack
{
    struct Node
    {
        Node (T v) : value(v){}
        T value;
        Node* prev;
    };
    public:
        stack(); 
        void push (T v);
        void pop();
        const T& top() const; //returns the item at the top of the stack
        int size(); //returns the size of the stack
        ~stack();

    private:
        int count; //keeps track of the size of the stack
        void delete_stack(); //deletes entire stack 
        Node* front;
};
template<typename T>
stack<T>::stack()
{
    front = nullptr;
    count=0;
}
template<typename T>
stack<T>::~stack()
{
    delete_stack();
}
template<typename T>
void stack<T>::push(T val)
{
    count++;
    if (!front)
    {
        front = new Node (val);
        front -> prev = nullptr;
    }
    else
    {
       Node* temp = front;
       Node* n = new Node (val);
       n->prev = temp;
       front = n;
    }
    
}
template<typename T>
const T& stack<T>::top() const
{
    if(count!=0)
        return front->value;

     else
         throw std::out_of_range("Empty stack!");      
}
template<typename T>
void stack<T>::pop()
{
    if(count>0)
    {
        Node* temp = front->prev;
        front = front->prev;
        delete temp;
        count--;
    }
     else
     {
         throw std::out_of_range("Can't pop from empty stack!"); 
     }
}
template<typename T>
int stack<T>::size()
{
    return count;
}
template<typename T>
void stack<T>::delete_stack()
{
    Node* traverse = front->prev;
    while(traverse)
    {
        Node* temp = traverse;
        traverse = traverse->prev;
        delete temp;
    }
    front = nullptr; //make the top nullptr to reuse stack (ie add new items to it)
}