#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int data1, Node * next1){
        data=data1;
        next=next1;

    }
    Node(int data2){
        data=data2;
        next=nullptr;
    }

};
//Brute force approach
Node * Intersection(Node * head1,Node * head2){
    map <Node * , int> mpp;
    Node * temp=head1;
    while(temp!=NULL){
        mpp[temp]=1;
        temp=temp->next;
    }
    Node * num=head2;
    while(num!=NULL){
        if(mpp.find(num)!=mpp.end()){
            return num;
        }
        num=num->next;
    }
    return NULL;
}
Node * collision(Node * t1,Node * t2,int k){
    while(k){
        k--;
        t1=t1->next;
    }
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
    }
    return t1;

}
//Better approach
Node * intersection(Node * head1,Node * head2){
    Node * temp=head1;
    Node * temp2=head2;
    int l1=0;
    int l2=0;
    while(temp!=NULL){
        l1++;
        temp=temp->next;
    }
    while(temp2!=NULL){
        l2++;
        temp2=temp2->next;
    }
    if(l1<l2){
        return collision(head2,head1,l2-l1);
    
    
    }
    else{
        return collision(head1,head2,l1-l2);
    }

}
//optimal aapraoch
Node * intersecTion(Node * head1,Node * head2){
    Node * temp1=head1;
    Node * temp2=head2;
    while(temp1!= temp2){
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==temp2)return temp1;
        if(temp1==NULL)temp1=head2;
        if(temp2==NULL)temp2=head1;
    }
    return NULL;

}
int main(){
    Node *head1=new Node(3);
    Node *second1=new Node(1);
    Node * third1= new Node (4);
    Node * fourth1=new Node(6);
    Node * fifth= new Node(2);
    head1->next=second1;
    second1->next=third1;
    third1->next=fourth1;
    fourth1->next=fifth;
    Node * head2=new Node(1);
    Node * second=new Node(2);
    Node * third=new Node(4);
    Node * fourth=new Node(5);
    head2->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=third1;
    Node * data1=intersection(head1,head2);
    cout<<data1->data;
    return 0;

}