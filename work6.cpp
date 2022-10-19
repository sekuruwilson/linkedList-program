#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct Node {
  int data;
  Node * next;
};
class LinkedList {
  // Head pointer
  Node * head;
  // TAIL pointer
  Node * tail;
  void updateTail() {
    if (head == NULL) {
      tail = NULL;
      return;
    }
    Node * temp = head;
    //  Else traverse till the last node
    while (temp -> next != NULL) {
      temp = temp -> next;
    }
    //  Assign the last node to tail
    tail = temp;
    return;
  }
  void printTail() {
    if (tail == NULL) cout << tail;
    cout << tail -> data;
  }
  public:
    // default constructor. Initializing head pointer
    LinkedList() {
      head = NULL;
      tail = NULL;
    }
  LinkedList(int size) {
    // Seed srand with random numbers
    srand(time(0));
    for (int i = 0; i < size; i++)
      // Add random numbers into our linked list
      insertAtBeginning(rand());
  }
  // Copy constructor
  LinkedList(const LinkedList & l1) {
    head = l1.head;
    tail = l1.tail;
  }
  // Desctructor
  ~LinkedList() {
    Node * current = head;
    while (current != 0) {
      Node * next = current -> next;
      delete current;
      current = next;
    }
    head = NULL;
  } 
  //overloading the operator
  void operator = (const LinkedList & l) {
    head = l.head;
    tail = l.tail;
  }
  Node * getHead() {
    return head;
  }// method for searching
  int search()
{
    int value,pos=0;
    bool flag=false;
    if(head==NULL)
    {
        cout<<"List is Empty";
        return 0;
    }
    cout<<"Enter the Value to be Searched:";
    cin>>value;
    Node *temp;
    temp=head;
    while(temp!=NULL)
    {
        pos++;
        if(temp->data==value)
        {
            flag=true;
            cout<<"Element"<<value<<"is Found at "<<pos<<" Position";
            return 0;
        }
        temp=temp->next;
    }
    if(!flag)
    {
        cout<<"Element "<<value<<" not Found in the List";
    }
}
  // function for deleting
  delet()
{
    Node *prev=NULL,*cur=head;
    int count=1,pos,ch;
    cout<<"\nDELETE\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        if(head!=NULL)
        {
            cout<<"\nDeleted Element is "<<head->data;
            head=head->next;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    case 2:
        while(cur!=tail)
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==tail)
        {
            cout<<"\nDeleted Element is: "<<cur->data;
            prev->next=NULL;
            tail=prev;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    case 3:
        cout<<"\nEnter the Position of Deletion:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            cout<<"\nDeleted Element is: "<<cur->data;
            prev->next=cur->next;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    }
}
  // function for inserting
 insert()
{
    Node *prev,*cur;
    prev=NULL;
    cur=head;
    int count=1,pos,ch,n;
    Node *temp=new Node;
    cout<<"\nEnter an Element:";
    cin>>n;
    temp->data=n;
    temp->next=NULL;
    cout<<"\nINSERT AS\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    	//inserting at the beginning
    case 1:
        temp->next=head;
        head=temp;
        break;
        //inserting at the end
    case 2:
    	tail->next=temp;
        tail=temp; 
    break;
    //    inserting inbetween the list  
    case 3:
        cout<<"\nEnter the Position to Insert:";
        cin>>pos;
        // we make a loop until we reach the position to insert
        //while the count is not equal to the position we continue moving  until we reach the position
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        // if we reach the position 
        if(count==pos)
        {
            prev->next=temp;
            temp->next=cur;
        }
        else
            cout<<"\nNot Able to Insert";
        break;
 
    }
}
  // inserting elements (At start of the list)
  void insertAtBeginning(int element) {
    // make a new node
    Node * new_node = new Node;
    new_node -> data = element;
    new_node -> next = NULL;

    // If list is empty, make the new node, the head
    if (head == NULL) head = new_node;

    // else, make the new_node the head and its next, the previous
    // head
    else {
      new_node -> next = head;
      head = new_node;
    }
    this -> updateTail();
    //    this->printTail();
  }
  // loop over the list. return true if element found
  bool search(int element) {
    Node * temp = head;
    while (temp != NULL) { 
      if (temp -> data == element) return true;
      temp = temp -> next;
    }
    return false;
  }
  void display() {
    Node * temp = head;
    while (temp != NULL) {
      cout << temp -> data << " ";
      temp = temp -> next;
    }
    cout << endl;
  }
/* Function to reverse the nodes in a linked list. */
  void reverse() {
    if (head == NULL) return;

    Node * prev = NULL, * current = NULL, * next = NULL;
    current = head;
    while (current != NULL) {
      next = current -> next;
      current -> next = prev;
      prev = current;
      current = next;
    }
    // now let the head point at the last node (prev)
    head = prev;
  }
  // Function 
  void removeDuplicate() {
   
    // temp pointing to head
    Node * temp = head;
    while (temp -> next != NULL && temp != NULL) {
      // Duplicate Found
      if (temp -> data == temp -> next -> data) {
        // DUplicate Removed
        temp -> next = temp -> next -> next;
      } else {
        // No Duplicate Present
        temp = temp -> next;
      }}}};
int main() {
  LinkedList l(3);
  LinkedList l2 = l;
  int ch;
    while(1)
    {
        cout<<"\n**** WELCOME TO OUR C++ PROGRAM ****";
        cout<<"\t\n1:DISPLAY\n2:INSERT\n3:DELETE\n4:SEARCH\n5:REVERSE\n6:REMOVE DUPLICATES\n7:EXIT";
        cout<<"\t\nEnter Your Choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            l.display();
            break;
        case 2:
            l.insert();
            break;
        case 3:
            l.delet();
            break;
        case 4:
            l.search();
            break;
        case 5:
            l.reverse();
            break;
        case 6:
        	l.removeDuplicate();
        	break;
		    
        case 7:
            return 0;
        }}}
