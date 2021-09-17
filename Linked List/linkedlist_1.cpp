
#include<bits/stdc++.h>
using namespace std;


struct listnode{
    int val;
    listnode *next;
    listnode() : val(0), next(nullptr) {}
    listnode(int x) : val(x), next(nullptr) {}
    listnode(int x, listnode *next) : val(x), next(next) {}
};

void push(listnode** head_ref, int new_val)
{
    /* allocate node */
    listnode* new_node = new listnode();

    /* put in the data */
    new_node->val = new_val;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
class linked{
    public:

    void printList(listnode *node)
    {
        while (node!=NULL)
        {
            cout<<node->val<<" ";
            node = node->next;
        }
    }
 

    // 1 - reverse a linked list function
    listnode* reverselist(listnode* head){
        listnode* newhead = NULL;
        while(head!=NULL){
            listnode * temp = head->next;
            head->next = newhead;
            newhead = head;
            head = temp;
        }
        return newhead;
    }
    // 2 - if odd return middle and if even return the 2nd middle element
    // use tortoise and hare method
    listnode* findmiddle(listnode* head){
        listnode* slow=head;
        listnode* fast=head;
        while( fast->next!=NULL || fast!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // 3 - merge two sorted linked list [part 1]
    // this is using extra space following up with in place
    listnode* merge2(listnode* head1, listnode*head2){
        listnode dummy;
        listnode* traverse = &dummy;
        dummy.next = NULL;
        while(1)
        {
            listnode * temp = new listnode; temp->next=NULL;
            if(head1==NULL){
                traverse->next = head2;
                break;
            }
            else if(head2 == NULL){
                traverse->next = head1;
                break;
            }
            if( head1->val <= head2->val){
                temp->val = head1->val;
                head1 = head1->next;
            }
            else{
                temp->val = head2->val;
                head2 = head2->next;
            }
            traverse->next = temp;
            traverse = traverse->next;
        }
        return (dummy.next);
    }
    // 3 - merge 2 sorted linked list [part 2 optimal]
    // without using extra space
    listnode* mergeinspace(listnode *l1, listnode *l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val>l2->val) swap(l1,l2);
        listnode*res = l1;
        while(l1!=NULL && l2!=NULL){
            listnode*temp = NULL;
            while( l1!=NULL && l1->val<= l2->val){
                temp = l1;
                l1=l1->next;
            }
            temp->next = l2;
            swap(l1,l2);
        }
        return res;
    }
};

int main()
{
    listnode* res = NULL;
    listnode* a = NULL;
    listnode* b = NULL;
    //Created lists, a: 5->10->15, b: 2->3->20
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
    linked ob;
    res = ob.mergeinspace(a,b);
    ob.printList(res);
    return 0;
}