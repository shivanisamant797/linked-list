#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node * back;
    Node(int data1,Node * next1,Node * back1){
        data=data1;
        next=next1;
        back=back1;

    }
    Node(int data2){
        data=data2;
        next=nullptr;
        back=nullptr;
    }
};
void traversal(Node* head){
    while(head!= NULL){
        cout<<head->data<<" ";
        head=head->next;

    }

}
Node* convert2DLL(vector<int> v1){
    Node * head=new Node(v1[0]);
    Node * prev=head;

    for(int i=1;i<v1.size();i++){
        Node * temp=new Node(v1[i],nullptr,prev);
        prev->next=temp;
        prev=temp;

    }
    return head;

}

int main(){
    vector <int> v1={1,2,4,5};
    Node * head=convert2DLL(v1);
    traversal(head);

    return 0;
}