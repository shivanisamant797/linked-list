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
    public:
    Node(int data2){
        data=data2;
        next=nullptr;
    }

};
void Traversal(Node * head){
    Node * temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
Node * Create(vector <int> &arr){
    Node * head=new Node(arr[0]);
    Node * mover=head;
    for(int i=1;i<arr.size();i++){
        Node * temp=new Node (arr[i]);
        mover->next=temp;
        mover=temp;


    }
    return head;
}
Node * deletehead(Node * head){
    if(head==NULL)return head;
    Node * temp=head;
    head=head->next;
     free(temp);
    return (head);

}

Node * deleteTail(Node * head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node * temp=head;

    while(temp->next->next!=nullptr){
        temp=temp->next;
        
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}
Node * deletek(Node * head,int k){
  
    if(head==NULL){
        return head;}
    if(k==1){
        Node *temp=head;
        head=head->next;
        delete(temp);
        return head;}
    int count=0;Node * temp=head;
    Node* prev=nullptr;
    while(temp!=NULL){
        count++;
       
        if(count==k){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
          prev=temp;
          temp=temp->next;
    }
  
    
  return head;
  
}
Node * deleteEle(Node * head,int ele){
  
    if(head==NULL){
        return head;}
    if(head->data==ele){
        Node *temp=head;
        head=head->next;
        delete(temp);
        return head;}
    Node * temp=head;
    Node* prev=nullptr;
    while(temp!=NULL){
      
        if(temp->data==ele){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
          prev=temp;
          temp=temp->next;
    } 
  return head;
}
int main(){
    vector <int> v1={2,3,4,5};
    Node * head=Create(v1);
    //Traversal(head);
    //cout<<"linked list after deletion"<<endl;
    //Node * newhead=deletehead( head);
   // cout<<"linked list after tail deletion"<<endl;
   // Node * newhead=deleteTail(head);
    //Traversal(head);
    //Node *Newhead=deletek(head,3);
    //cout<<"after deleting 3 element"<<endl;
    //Traversal(Newhead);
    Node * Newhead= deleteEle(head,4);
    Traversal(Newhead);
    return 0;
}