
/*1) Creation of linked list
2) convert Array to linked list
3)Traversal of linked list 
4)search the element in the linked list
5)Deletion of linked list




*/
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
int lengthofLL(Node * head){
    int count=0;
    Node *temp=head;
    while(temp!=nullptr){
        
        count++;
        temp=temp->next;
    }
    return count;

}
int search(Node *head,int ele){
     Node *temp=head;
    while(temp!=nullptr){
        if(temp->data==ele){
            return 1;
        }
        
        temp=temp->next;
    }
    return 0;
}
int main(){
    vector <int> v1={5,8,9,1};
    Node * head=convert2L(v1);
    
    //traversal
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
  
    int n=lengthofLL(head);
    cout<<"the lenght of linked list is "<<n<<endl;
    int y=search(head,67);
    if(y==0){
        cout<<"Not found";
    }
    else{
        cout<<"found";
    }

    return 0;
}