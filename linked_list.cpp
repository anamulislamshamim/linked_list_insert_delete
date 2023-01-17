#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
public:
    Node* head;
    int sz;
    Node* tail;
    LinkedList(){
        head=NULL;
        sz=0;
    };
    Node* CreateNewNode(int value)
    {
        Node* newNode= new Node();
        newNode->data=value;
        newNode->next=NULL;
        return newNode;
    };
    void InsertAtHead(int value){
        Node* myNode = CreateNewNode(value);
        // update the tail node
        if(sz==0)
            tail=myNode;
        // increse the size;
        sz++;
        if(head==NULL){
            head=myNode;
            return;
        };
        myNode->next=head;
        head=myNode;
    };
    void InsertAtTail(int value){
        if(sz==0){
            InsertAtHead(value);
            return;
        };
        // increse the size
        sz++;
        Node* tailNode = CreateNewNode(value);
        // Node* tailTmp = head;
        // update the tail node
        tail->next=tailNode;
        tail=tailNode;
    };
    void InsertAnyIndex(int idx, int value)
    {
      // check if the idx is 0 then just call the InsertAtHead()
      if(idx==0){
        InsertAtHead(value);
        return;
      };
      // increasing the size
      sz++;
      Node* tempHead;
      tempHead=head;
      int c_idx=0;
      while(c_idx != idx-1){
        cout << "Hello World " << tempHead->data << "\n";
        tempHead=tempHead->next;
        c_idx++;
      };
      Node* newNode = CreateNewNode(value);
      cout << "new node value: " << newNode->data << "\n";
      cout << "temp head next value: " << tempHead->next->data << "\n";
      newNode->next=tempHead->next;
      tempHead->next=newNode;
    };
    void Traverse(){
        Node* tmp = head;
        while(tmp!=NULL){
            cout << tmp->data << " ";
            tmp=tmp->next;
        }
    };
    void GetSize()
    {
      cout << sz << "\n";
    };
    void DeleteAtHead()
    {
      // check if the list size is zero
      if(head==NULL){
        return;
      };
      Node* a=head;
      head=a->next;
      delete a;
    };
    void DeleteAnyIndex(int index)
    {
        if(index==0){
            DeleteAtHead();
            return;
        };
        // decreasing list length
        sz--;
        Node* a;
        a=head;
        int c_idx=0;
        while(c_idx!=index-1){
            a=a->next;
            c_idx++;
        };
        Node* b = a->next;
        a->next=b->next;
        delete b;
    };
};

int main()
{
    LinkedList l;
    l.GetSize();
    l.InsertAtHead(10);
    l.GetSize();
    l.InsertAtHead(20);
    l.GetSize();
    l.InsertAtHead(30);
    l.GetSize();
    l.InsertAtHead(40);
    l.GetSize();
    l.Traverse();
    l.InsertAtTail(100);
    cout <<"\n";
    l.GetSize();
    l.Traverse();
    //
    cout << "\n" << "insert a node in the middle of the linked list" << "\n";
    l.InsertAnyIndex(2 ,117);
    l.Traverse();
    cout << "after delete one element from the head" << "\n";
    l.DeleteAtHead();
    l.DeleteAnyIndex(1);
    l.Traverse();
    return 0;
}
