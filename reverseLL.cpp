
#include <bits/stdc++.h>


using namespace std;
class Node{
    public:
    int data;
    Node * next;
    public:
    Node(int data1,Node * next1){
        data=data1;
        next=next1;
    }
    Node(int data2){
        data=data2;
        next=nullptr;
    }
};
Node* convert2L(vector <int> &arr){
    Node* head=new Node(arr[0]);
    Node * mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;

    }
    return head;
}
void traversal(Node * head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }

}
//brute force method
Node * reverse(Node * head){
    stack <int> st;
    Node * temp=head;
    while(temp!= nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;

    while(!st.empty()){
        
        temp->data=st.top();
        st.pop();
        temp=temp->next;
        
    }
    return head;

}
Node * Reverse(Node  * head){
    Node * temp=head; Node * prev=NULL;
    Node * front;
    while(temp!=NULL){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
        
    }
    return prev;

}
//iterative method 

int main(){
    vector <int> v1={2,3,4,5,7};
    Node * head =convert2L(v1);
    Node *newhead=Reverse(head);
    traversal(newhead);




    return 0;
}