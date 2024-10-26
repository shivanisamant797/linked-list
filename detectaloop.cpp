#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    public:
    Node(int data1,Node * next1){
        data =data1;
        next=next1;

    }
    Node(int data2){
        data=data2;
        next=nullptr;
    }
};

bool check(Node * head){
    Node * temp=head;
    unordered_map <Node *, int> nodemap;
    while(temp!=NULL){
        if(nodemap.find(temp)!=nodemap.end()){
            return true;
        }
        nodemap[temp]=1;
        temp=temp->next;
    }
    return false;
}



int main(){
    Node * head = new Node(1);
    Node * second = new Node(2);
    Node * third= new Node(3);
    Node * fourth= new Node(4);
   Node * fifth=new Node(5);
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=third;
    bool res=check(head);
    cout<<res<<endl;
    cout<<"done hai bhai";
    

    return 0;
}