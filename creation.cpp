#include <bits/stdc++.h>
using namespace std;
class Node
{   public:
    int data;
    Node * next;
    public:
    Node(int data1, Node * next1){
        data=data1;
        next=next1;
    }
};
int main(){
    vector <int> v1={1,2,3,4};
    Node * y=new Node(v1[0],nullptr);
    cout<<y->data<<endl;
    cout<<y->next<<endl;
    cout<<&*y<<endl;
    return 0;
}