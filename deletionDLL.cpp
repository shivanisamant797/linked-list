#include <bits/stdc++.h>
using namespace std;
/* 1> delete the head
2> delete the tail
3> delete kth element
4> delete the element



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
        next = next1;
        back = back1;
    }
    Node(int data2)
    {
        data = data2;
        next = nullptr;
        back = nullptr;
    }
};
void traversal(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
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
Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete (prev);
    return head;
}
Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *previous = tail->back;
    previous->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}
Node *deleteKth(Node *head, int n)
{
    if (head == NULL)
        return NULL;
    int count = 0;
    Node *post = head;
    while (post != NULL)
    {
        count++;
        if (count == n)
        {
            break;
        }
        post = post->next;
    }
    Node *prev = post->back;
    Node *front = post->next;
    if (prev == NULL && front == NULL)
    {
        delete post;
        return nullptr;
    }
    else if (prev == NULL)
    {
        deleteHead(head);
    }
    else if (front == NULL)
    {
        deleteTail(head);
    }
    else
    {
        prev->next = front;
        front->back = prev;
        post->next = nullptr;
        post->back = nullptr;
        delete (post);
    }
    return head;
}
Node * deleteEle(Node * temp){
    Node * prev=temp->back;
    Node * front=temp->next;
    if(front== NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        delete(temp);
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    free(temp);
}
int main()
{
    vector<int> v1 = {1, 2, 4, 5};
    Node *head = convert2DLL(v1);
    // traversal(head);
    // Node * newhad=deleteHead(head);
    //  traversal(newhad);
    // Node * newhead=deleteTail(head);
    //Node *newhead = deleteKth(head, 3);
    //traversal(newhead);
   deleteEle(head->next);
    traversal(head);
    return 0;
}