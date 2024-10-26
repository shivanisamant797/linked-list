#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data2)
    {
        data = data2;
        next = nullptr;
    }
};

Node * Create(vector <int> &arr){
    Node * head=new Node(arr[0]);
    Node * mover=head;
    for(int i=1;i<arr.size();i++){
        Node * temp=new Node (arr[i]);
        mover->next=temp;
        mover=temp;


    }
    return head;
}
void traversal(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void checkpalindrome(Node * head){
    Node * temp= head;
    stack <int> st;
    while(temp!= nullptr){
        st.push(temp->data);
        temp=temp->next;

    }
    temp=head;
    while(temp!=nullptr){
        if(temp->data!=st.top()){
            cout<<"it is not palindromic ";
            return;

        }
        st.pop();
        temp=temp->next;
       
        
    }
     cout<<"it is palindrom";
}

int main()
{
    vector<int> v1 = {1, 1, 2, 2, 1, 1};
    Node *head = Create(v1);
    traversal(head);
    checkpalindrome(head);

    return 0;
}