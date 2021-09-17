
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
 
    // 4 - remove nth node from end O(2n) time solution [part 1]
    listnode* removenthnodefromback(listnode* head, int n)
    {
        listnode* dummy = head; int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        int todel = count-n;
        if( todel == 0){
            listnode* temp = head;
            head = head->next;
            free(temp);
            return head;
        }
        head = dummy;
        for (int i = 1; i <= n; i++)
            head = head->next;
        listnode* temp = head->next;
        head->next = head->next->next;
        free(temp);
    }
    // 4 - remove nth node from end O(n) soln [part 2 - optimal]
    // take 2 pointer, first only move fast pointer by n iteration
    // and once nth node is reached then you only have to start
    // moving slow till fast reaches NULL
    listnode* removenthnodefromlast(listnode*head, int n){

        listnode*dummy = new listnode();
        dummy->next = head;
        listnode*slow = dummy, *fast=dummy;
        for (int i = 1; i <= n; i++)
        {
            fast= fast->next;
        }
        while(fast->next!=NULL){
            slow = slow->next;
            fast=fast->next;
        }
        listnode* temp = slow->next;
        slow->next = slow->next->next;
        free(temp);
        return dummy->next;
    }
    // 5 - delete a node where instead of head pointer u're given 
    // pointer to the exact node to be deleted.
    void deletenode(listnode* somenode)
    {
        // condition for the last node to be deleted
        if(somenode->next==NULL){
            somenode = NULL;
            return;
        }
        listnode * temp = somenode->next;
        somenode->val = temp->val;
        somenode->next = temp->next;
        free(temp);
    }
    // 6 - add two numbers
    // digits are stored in reverse order in the two linked lists
    // add two numbers and return sum as a linked list
    // eg: 2->4->3 and 5->6->7->9, hence numbers are 342 + 9765 = 10107
    // return the list as: 7->0->1->0->1->NULL
    listnode* addtwonum(listnode* l1, listnode* l2){
        listnode* dummy; dummy->val=0;
        listnode* temp = dummy;
        int sum , carry=0;
        while(1){

            sum=carry;
            if(l1!=NULL) { sum+=l1->val; l1 = l1->next;}
            if(l2!=NULL) { sum+=l2->val; l2 = l2->next;}
            if( l1==NULL && l2==NULL && sum==0) break;//else you can write this expression in the while check too
            carry = sum/10;
            listnode* newnode = new listnode(sum%10);
            newnode->next = NULL;
            temp->next = newnode;
            temp = temp->next;
        }
        return dummy->next;
    }
};

int main()
{
    listnode* res = NULL;
    listnode* a = NULL;
    listnode* b = NULL;
    //Created lists, a: 5->1->5, b: 2->3->0
    push(&a, 5);
    push(&a, 1);
    push(&a, 5);
    push(&b, 0);
    push(&b, 3);
    push(&b, 2);
    linked ob;
    res = ob.addtwonum(a,b);
    ob.printList(res);
    return 0;
}