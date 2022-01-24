#include <iostream>
using namespace std;

template <class T>
class LinkedList {

public:
  LinkedList() : head(NULL) {}
  ~LinkedList()
  {
    ListNode* rmptr;
    while(head != NULL)
    {
      rmptr = head;
      head = head->next;
      delete rmptr;
    }
  }
  void push_front(const T data)
  {
     ListNode *tmp = new ListNode(data); 
     tmp->next = head; 
     head = tmp;
  }
  void pop_front()
  {
    ListNode* prev = NULL;
    if(head == NULL)
    {
      cout<< "Empty\n";
    }
    else
    {
      ListNode *tmp = head;
      head = head->next;
      delete tmp;
    }
  }
  void reverse()
  {
    ListNode* cursor = head;
    if(cursor == NULL)
    {
        cout<<"Empty\n";
    }
    else
    {
       ListNode *current = head; 
        ListNode *prev = NULL, *link = NULL; 
  
  
        while (current != NULL) 
        {  
            link = current->next; 
            current->next = prev;  
            prev = current; 
            current = link; 
        } 
        head = prev; 
    }
  }
  void print() const
  {
    if(head == NULL)
    {
      cout<< "Empty\n";
    }
    else
    {
      ListNode* temp = head; 
        while (temp != NULL) 
        { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
    }
  }

private:
  struct ListNode {
    ListNode(const T data) : data(data), next(NULL) {}

    T data;
    ListNode* next;
    ListNode* prev;
  };

  ListNode* head;
};

char menu()
{
    char choice;
    cout<<"Choose from the following options:\n";
    cout<<"i : Add the integer i to the front of the list.\n";
    cout<<"d : Delete the first element of the list.\n";
    cout<<"r : Reverse the list.\n";
    cout<<"p : Print the data value of each node in the list.\n";
    cout<<"q : Quit the program\n";
    cin>>choice;

    return choice;
}
