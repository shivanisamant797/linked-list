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
Node * findnthnode(Node * head,int k){
    Node * temp=head;
    int i=0;
    while(temp!=NULL){
        if(i==k){
            return temp;
            break;
        }
        i++;
        temp=temp->next;

    }
}
Node * rotatell(Node * head,int k){
    
    int l=1;
    Node * temp=head;
    while(temp->next!=NULL){
        l=l+1;
        temp=temp->next;
    }
     temp->next=head;
    if(k%l==0){
        return head;
    }
    k=k%l;
   
    Node * newnode=findnthnode(head,l-k);
    head=temp->next;
    temp->next=NULL;
    return head;
    

}

int main(){
    vector <int> v1={1,2,3,4,5};
    Node * head=convert2ll(v1);
    
    return 0;

};