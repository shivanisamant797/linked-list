#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int data1,Node * next1){
        data =data1;
        next=next1;

    }
    Node (int data1){
        data=data1;
        next=nullptr;
    }



};
Node * convert2ll(vector <int> v1){
    Node * head=new Node(v1[0]);
    Node * mover=head;
    for(int i=1;i<v1.size();i++){
       
        Node * temp=new Node(v1[i]);
         mover->next=temp;
         mover=temp;
    }
    return head;


}
void traversal(Node * head){
    Node * temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
//brute force approach
Node * oddeven(Node * head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *temp=head;
    vector <int> v1;
    while(temp!=nullptr && temp->next!=nullptr){
        v1.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp){
        v1.push_back(temp->data);
    }
    temp=head->next;
    while(temp!=nullptr && temp->next!=nullptr){
        v1.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp){
        v1.push_back(temp->data);
    }
    temp=head;
    int i=0;
    while(temp!=NULL){
        temp->data=v1[i];
        i++;
        temp=temp->next;
    }
    return head;
}



//optimal approach

Node * oddEven(Node * head){
    Node * odd=head;
    Node * even=head->next;
    Node * evenhead=head->next;
    if(head==NULL || head->next==NULL){
        return head;

    }
    while(even!=nullptr  && even->next!=nullptr){

        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
    return head;
}

int main(){
    vector <int> v1={1,2,3,4,5,6};
    Node * head=convert2ll(v1);
    //traversal(head);
    //Node * newhead=oddeven(head);
    //
    //traversal(newhead);
    Node * newhead=oddEven(head);
    traversal(newhead);






}
