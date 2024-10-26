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
Node * middle(Node* head){
    int count=0;
    Node * temp=head;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    temp=head;
    int midnode=(count/2)+1;
   while(temp!=nullptr){
    midnode=midnode-1;
    if(midnode==0){
        break;
    }
    temp=temp->next;
   }
   return temp;
}
//optimal appraoch
//turtoise and hare approach;
Node * Middle(Node * head){
    Node * slow=head;
    Node * fast=head;
   
    while(fast!=NULL && fast->next!=NULL ){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

}
//delete the middle node of linkedlist
 
Node * Middledel(Node * head){
    Node * temp=head;
    Node * slow=head;
    Node * fast=head;
    Node * prev=NULL;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=slow->next;
    return head;

    
}


int main(){
    vector <int> v1={1,2,3,5,6};
    Node * head=convert2ll(v1);
    Node * newhead=Middledel(head);
    traversal(newhead);
    return 0;

};
