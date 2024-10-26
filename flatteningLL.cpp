#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node * next ;
    Node * child;

    Node(int data1,Node * next1,Node * child1){
        data=data1;
        next=next1;
        child=child1;

    }
    Node(int data2){
        data=data2;
        next=nullptr;
        child=nullptr;

    }

};
Node * convert(vector <int> v1){
    int size=v1.size();
    if(v1.size()==0)return NULL;
    Node * head=new Node(v1[0]);

}
 

Node * flatening(Node * head){
    vector <int> v1;
    Node * temp=head;
    while(temp!=NULL){
        Node * t1= temp;
        while(t1!=NULL){
            v1.push_back(t1->data);
            t1=t1->child;


        }
        temp=temp->next;
    }
    sort(v1.begin(),v1.end());
    convert(v1);

}




int main(){
    

    Node * head=new Node(5);
    head->child=new Node(14);

    head->next= new Node(10);
    head->next->child= new Node(4); 

    head->next->next=new Node(12);
    head->next->next->child=new Node(20);
    head->next->next->child->child=new Node(13);

    head->next->next->next=new Node(7);
    head->next->next->next->child=new Node(17);
    
    Node* newhead












    return 0;
}