#include <bits/stdc++.h>
using namespace std;
/* In this we are going to do
1)Insert at the head
2)




*/

class Node{
    public:
    int data;
    Node * next;
    public:
    Node(int data1,Node *next1){
        data=data1;
        next=next1;

    }
    Node(int data2){
        data=data2;
        next=nullptr;
    }


};
Node*  creation(vector <int> v1){
    Node * head= new Node(v1[0]);
    Node * mover=head;

    for(int i=1;i<v1.size();i++){
        Node * temp= new Node(v1[i]);
        mover->next=temp;
        mover =temp;
    }
    cout<<"it is created"<<endl;
   return head;


}
void Traversal(Node * head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }

}
Node * insertAThead(Node * head,int n){
   
    Node * temp=new Node(n);
    temp->next=head;
    return temp;
    


}
Node * insertAttail(Node * head,int val){
     if(head==NULL) return new Node(val);
    Node * temp=head;
    Node * num= new Node(val);
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=num;
    return head;

}
Node * insertAtkth(Node * head,int index,int ele){
    if(head==NULL){{}
      
    }




}

int main(){
    vector <int> v1={2,3,4,5,7};
    Node * head =creation(v1);
    //Traversal(head);
    //Node * newhead= insertAThead(head,58 );
   // Traversal(newhead);
    Node * Newhead=insertAttail(head,89);
    Traversal(Newhead);
    




    return 0;
}