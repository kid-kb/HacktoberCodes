#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
};

void insert_cll(Node** head_ref,int x){

   Node* last = (*head_ref)->prev ;
   Node* new_node = new Node();
   new_node->data = x;
   new_node->next = *head_ref;
   new_node->prev = last;
   last->next = new_node;
   (*head_ref)->prev = new_node;
   last = new_node; 


}
int dist(Node** st, int end){

    int cl =0;
    int ccl =0;
    Node* last = (*st)->prev;
    Node* st2 = (*st);
    Node* st1 = (*st);
    while(st2->next != *st){
        if(st2->data != end){
            cl++;
            st2 = st2->next;
        }
        else break;
    }
     while(st1->prev != *st){
        if(st1->data != end){
            ccl++;
            st1 = st1->prev;
        }
        else break;
    }
    *st = st1;

    return min(cl,ccl);

}

int main(){
   string s;
   cin>>s;
   Node* head_ref = new Node();
   head_ref->data = 97;
   head_ref->next = head_ref->prev = head_ref;

   for(int i=1;i<26;i++)
   {
       insert_cll(&head_ref,(97 + i));
       //cout<<"val to insert:"<<(97+i)<<endl;
   }
   Node* st = new Node();
   st = head_ref;
   //Node* end = new Node();
   int end;
   int rotation =0;
   for(int i=0;i<s.length();i++){
      end = int(s[i]);
      rotation += dist(&st,end);
    // cout<<"rot val after each i: "<<rotation<<endl;
   }

    cout<<rotation;

    return 0;
}