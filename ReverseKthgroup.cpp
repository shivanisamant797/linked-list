#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int data1,Node * next1){
        data=data1;
        next=next1;
    }
    Node(int data2){
        data=data2;
        next=nullptr;


    }


};
Node * convert2LL(vector <int> v1){
    Node * head= new Node(v1[0]);
    Node * mover=head;
    for(int i=1;i<v1.size();i++){
        Node * temp=new Node(v1[i]);
        mover->next=temp;
        mover=temp;
        
    }
    return head;

}
void traversal(Node * head){
    Node * temp =head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }

}
Node * findkthnode(Node * temp,int k){
     k=k-1;
    while(temp!=NULL && k>0){
        temp=temp->next;
        k--;
        
    }

    return temp;
}
Node * reverse(Node * head){
    Node * temp=head;
    Node * prev=NULL;
    Node * front;

    while(temp!=NULL){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
        
    }
    return prev;
}
Node * reversekth(Node * head,int k){
    Node * prev=NULL;
    Node * temp=head;
    Node * next1;

    while(temp!=NULL){
        Node * kth=findkthnode(temp,k);
        if(kth==NULL){
            if(prev)prev->next=temp;
            break;
        }
       next1=kth->next;
       kth->next=NULL;
       Node * reverseNode=reverse(temp);
       if(temp==head){
        head=kth;

       }
       else{
        prev->next=kth;

       }
       prev=temp;
       temp=next1;
        
    }
    return head;

}

int main(){
    vector <int> v1={1,2,3,4,5,6,7,8,9,10};
    Node * head= convert2LL(v1);
    //Node * newhead=reverse(head);
    //traversal(newhead);
    Node * Newhead=  reversekth(head,3);
    traversal(Newhead);


    
}
