#include <bits/stdc++.h>
using namespace std;
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
// brute force approach
Node *reversedll(Node *head)
{
    Node *temp = head;
    stack<int> st;
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (!st.empty())
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
// optimal approach
Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *current = head;
    while (current != NULL)
    {
        prev = current->back;
        current->back = current->next;
        current->next = prev;
        current = current->back;
    }
    return prev->back;
}
int main()
{
    vector<int> v1 = {1, 3, 4, 5, 6};
    Node *head = convert2DLL(v1);
    // traversal(head);
    // Node * newhead= reversedll(head);
    // traversal(newhead);
    Node *newhead = reverseDLL(head);
    traversal(newhead);

    return 0;
}
