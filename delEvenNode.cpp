#include <bits/stdc++.h>
using namespace std;
 
 class Node{
     public:
     int data;
     Node * next;
     Node (int data1,Node * next1){
         data=data1;
         next=next1;
     }
     Node (int data1){
         data=data1;
         next=nullptr;
     }
     
     
 };
Node * implement(vector <int> v1){
    Node * head=new Node(v1[0]);
    Node * mover=head;
    for(int i=1;i<v1.size();i++){
        Node * temp=new Node(v1[i]);
        mover->next=temp;
        mover=temp;
        
        
    }
    return head;
}
Node * delNode(Node * head){
    
    while(head && head->data%2==0){
        Node * temp=head;
        head=head->next;
        delete temp;
    }
    
    Node * curr=head;
    while(curr && curr->next){
        if(curr->next->data%2==0){
            Node * temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
    
}
void print(Node * head){
    Node * temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
    vector <int> v1={3,2,4,1,7,8,9};
    Node * head=implement(v1);
    Node * temp=delNode(head);
    print(temp);
    return 0;
}