#include <bits/stdc++.h>
using namespace std;
/*1> Insert the element into the head
2>Insert into the tail
3> Insert before kth count
4>Insert element before element
*/

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1,
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node *convert2DLL(vector<int> v1)
{
    Node *head = new Node(v1[0]);
    Node *prev = head;

    for (int i = 1; i < v1.size(); i++)
    {
        Node *temp = new Node(v1[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void traversal(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
Node *InsertatHead(Node *head, int val)
{
    Node *newHead = new Node(val, head, nullptr);
    head->back = newHead;

    return newHead;
}
Node *InsertatTail(Node *head, int ele)
{
    if (head->next == NULL)
    {
        return InsertatHead(head, ele);
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *previous = tail->back;
    Node *temp = new Node(ele, tail, previous);
    previous->next = temp;
    tail->back = temp;

    return head;
}
Node *insertkth(Node *head, int n, int ele)
{
    if (n == 1)
    {
        return InsertatHead(head, ele);
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == n)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;
    Node *newNode = new Node(ele, front, prev);
    prev->next = newNode;
    front->back = newNode;
    delete (temp);
    return head;
}
void insertBele(Node * head, int ele){
    Node * prev=head->back;
    Node * newhead=new Node(ele,head,prev);
    prev->next=newhead;
    head->back=newhead;



}
int main()
{
    vector<int> v1 = {1, 3, 4, 5, 6};
    Node *head = convert2DLL(v1);
    insertBele(head->next,8453);
    traversal(head);
    
 // Node * newHead=InsertatHead(head,67);
    // traversal(newHead);
    //  Node * newhead=InsertatTail(head,89);
    //  traversal(newhead);
        // Node *newhead = insertkth(head, 3, 45);
    // traversal(newhead);
   


    return 0;
}

















