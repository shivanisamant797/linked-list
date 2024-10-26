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
//Brute force solution
Node* merge2sorted(Node * head1,Node *head2){
    Node * temp=head1;
    vector <int> v;
    while(temp!=nullptr){
        v.push_back(temp->data);
        temp=temp->next;
    }
    temp=head2;
    while(temp!=nullptr){
        v.push_back(temp->data);
        temp=temp->next;

    }
    sort(v.begin(),v.end());
    Node * newhead=convert2ll(v);
    return newhead;
    
}
//optimal solution
Node * merege2LL(Node * head1,Node * head2){
    Node * t1=head1;
    Node * t2=head2;
    Node * dummynode= new Node(-1);
    Node * temp=dummynode;
    while(t1!=NULL && t2!=NULL){
        if(t1->data <t2->data){
            temp->next=t1;
            temp=t1;
            t1=t1->next;


        }
        else{
            temp->next=t2;
            temp=t2;
            t2=t2->next;

        }

    }
    if(t1){
        temp->next=t1;
    }
    else{
        temp->next=t2;
    }
    return dummynode->next;
    





}





int main(){
    vector <int> v1={1,2,4};
    vector<int> v2={1,3,4};

    Node * head1=convert2ll(v1);
    Node * head2=convert2ll(v2);

    Node * newhead=merege2LL(head1,head2);
    traversal(newhead);


   
    return 0;

};
