
#include<bits/stdc++.h>
using namespace std;

struct listnode{
    int val;
    listnode * next;
    listnode() : val(0), next(nullptr){}
    listnode(int x) : val(x), next(nullptr){}
    listnode(int x, listnode*a) : val(x), next(a){}
};

listnode* reverse(listnode * head){
    listnode* newhead= NULL;
    while(head!=NULL){
        listnode * temp = head->next;
        head->next = newhead;
        newhead = head;
        head = temp;
    }
    return newhead;
}
// 1 - Rearrange a liked list in place
// such that l0->l1->l2->....l(n-1)-> ln becomes
// L0->Ln->L2->L(n-1)->L3->....
// so to solve this first find middle then reverse the second half of the ll
// now insert one node in middle of 2 nodes from start
// the node that will be inserted will be from the middle -> next onwards
// iterate till middle->next becomes null
void rearrangeinplace(listnode*head){
    if(head==NULL || head->next ==NULL) return;
    listnode*slow = head; 
    listnode*fast = head;
    // step 1 is to find the middle of the linked list
    while( (fast->next!=NULL) || (fast->next->next=NULL) ){
        fast=fast->next->next;
        slow=slow->next;
    }
    // step 2 is to reverse the linked list when head is given to you
    slow->next = reverse(slow->next);
    listnode* start = head;
    listnode* middle = slow;
    // step 3 is to merge the code
    while( middle->next!=NULL || middle){
        listnode*temp1 = start->next;
        listnode*temp2 = middle->next->next;
        start->next = middle->next;
        start->next->next = temp1;
        middle->next = temp2;
        start = start->next->next;
    }
}

