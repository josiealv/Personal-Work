#include <iostream>
using namespace std;


struct Item {
    Item (int v)
    {
        value=v;
    }
    Item *next, *prev;
    int value;
};
//Returns a pointer (in O(n) time) to the smallest item in the Linked List starting at head,
//or NULL if head is NULL.
Item* FindMin(Item *head)
{
    Item* temp;
    Item* min;
    temp = min = head; 
  
    // traverse the whole doubly linked list 
    while (temp != NULL) { 
        if (temp->value < min ->value) 
            {min = temp; }
  
        temp = temp->next; 
    } 
    return min; 
} 
  
//Returns a pointer to the head of the sorted linked list.
Item* LL_Selection_Sort(Item *head) {
    if(!head)
    {
        return NULL;
    }
    Item* actual_head = head;
    while (actual_head->prev) //go to beginning of the linked list
    {
        actual_head=actual_head->prev;
    }
    Item* tail; //will keep track of where we end, so we can traverse back to the head
    while (actual_head)
    {
        Item* min = FindMin(actual_head); //find the min from the current node to the end of the LL
        if(min ==NULL) 
        {
            break;
        }
        int temp = actual_head->value; //just regular swap for the values
        actual_head->value = min->value;
        min->value = temp;
        tail = actual_head;
        actual_head=actual_head->next;
    }
    Item* new_head=tail; //will use to get the new head so we can return it
    while (new_head->prev)
    {
        new_head=new_head->prev;
    }
    return new_head;
} 
int main()
{
    Item* one = new Item(1);
    one->prev=NULL;
    Item* five= new Item(5);
    five->prev=one;
    one->next=five;
    Item* zero = new Item (0);
    zero->next = NULL;
    five->next=zero;
    zero->prev=five;

    Item* in_order= LL_Selection_Sort(five);
    if (in_order)
    {
         Item* traverse = in_order;
        while (traverse!=NULL)
        {
            cout << traverse->value << " ";
            traverse=traverse->next;
        }
        cout << endl;
    }
   
    delete one;
    delete five;
    delete zero;
    return 0;
}
