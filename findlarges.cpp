#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node ( int value1,Node * next1){
        data=value1;
        next=next1;
    }
    Node(int value2){
        data=value2;
        next=nullptr;
    }
};
Node * implement(vector <int> v1){
    Node * head=new Node(v1[0]);
    Node * temp=head;
    for(int i=1;i<v1.size();i++){
        Node * newNode=new Node(v1[i]);
        temp->next=newNode;
        temp=newNode;
        
    }
    return head;
    
}
Node * largest(Node * head){
    
    Node * temp=head;
    Node * maxi=temp;
    while(temp!=NULL){
        if(temp->data>maxi->data){
            maxi=temp;
        }
    temp=temp->next;
    }
    return maxi;
}
int main(){
    vector <int> v1={2,3,4,5,6};
    Node * head=implement(v1);
    Node * maxdata=largest(head);
    cout<<"the largest elemtnis "<<maxdata->data;
    return 0;
}