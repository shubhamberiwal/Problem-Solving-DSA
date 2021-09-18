

#include<bits/stdc++.h>
using namespace std;

struct listnode{
    int val;
    listnode *next;
    listnode() : val(0), next(nullptr){}
    listnode(int x) : val(x), next(nullptr){}
    listnode(int x, listnode*a) : val(x), next(a){}
};

void push(int x, listnode**a){
    listnode* newnode = new listnode(x);
    newnode->next = *a;
    *a = newnode;
    // (*a)->next = newnode;
    // a=a->next;
}
class linked{
    public:
    void printlist(listnode *node){

        while(node!=NULL){
            cout<<node->val<<" ";
        }
        cout<<endl;
    }

    // 7 - Intersection point of 2 linked list [better, part 1]
    // find the intersection using a hashmap where
    // first you store the address of all the first linked list nodes
    // next you traverse through the 2nd one and when the match is 
    // found you return the pointer to that node
    // time complexity = O(length1 + length2);
    listnode* intersect(listnode* l1, listnode* l2){
        // INTERESTING TOPIC: how to store the address in a hashmap
        set<listnode *> hashmap;
        cout<<l1;
        while(l1!=NULL){
            hashmap.insert(l1);
            l1=l1->next;
        }
        set<listnode*>:: iterator it;
        while(l2!=NULL){
            it = hashmap.find(l2);
            if(it!=hashmap.end())
                break;
            l2=l2->next;
        }
        listnode *temp = *it;
        return temp;
    }
    // 7 - interesection point of 2 linked list [Optimal - part 2]
    // traverse through both whoever reaches the end first is pointed
    // back to the head of the other list in that way the difference
    // between the 2 nodes is recovered and if no intersection is there
    // they will meet at the end. Time complex: O(2M) space: O(1). M is len(longer lst)
    listnode* intersectionpoint(listnode* l1, listnode* l2)
    {
        if(l1==NULL || l2==NULL) return NULL;
        listnode *dummy1 = l1, *dummy2 = l2;
        while( dummy1!=dummy2){
            dummy1 = dummy1==NULL?l2: dummy1->next;
            dummy2 = dummy2==NULL?l1: dummy2->next;
        }
        return dummy1;
    }
    // 8 - Detect a cycle in a linked list [good part 1]
    // create a hashmap and store the address of the node 
    // as you traverse, if there is a cycle then it will
    // be present in the hashmap, simply return that pointer 
    // or else return Null at the end. Time complexity: 
    // O(n), space comp: O(n)
    listnode* detectcycle(listnode * head){
        set<listnode *> hashmap;
        set<listnode *> :: iterator it;
        while( head!=NULL){
            if( hashmap.find(head)!=hashmap.end()){
                it = hashmap.find(head);
                return *it;
            }
            else{
                hashmap.insert(head);
            }
            head=head->next;
        }
        return NULL;
    }
    // 8 - Detect a cycle [Optimal part 2]
    // 
    bool detectcycleoptimal(listnode* head){
        if(head==NULL || head->next==NULL) return false;
        listnode *slow = head, *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                return true;
        }
        return false;
    }
    // 9 - Check for a Palindromic linked list
    bool palindromelist(listnode* head)
    {
        if(head==NULL || head->next==NULL) return true;
        int mid=0;
        listnode*slow = head, *fast = head;
        while( fast->next!=NULL && fast->next->next!=NULL ){
            mid++;
            fast= fast->next->next;
            slow=slow->next;
        }
        listnode* reverse = slow->next;
        listnode * newhead = NULL;
        while( reverse!=NULL ){
            listnode* temp = reverse->next;
            reverse->next = newhead;
            newhead = reverse;
            reverse = temp;
        }
        slow->next = newhead;
        slow= (*slow).next;
        while(slow!=NULL){
            if(head->val!=slow->val) return false;
            slow=slow->next;
            head=head->next;
        }
        return false;
    }

};

struct listnod{
    int val;
    listnod* next;
    listnod* bottom;
    listnod() : val(0), next(nullptr), bottom(nullptr){}
    listnod(int x) : val(x), next(nullptr), bottom(nullptr){}
    listnod(int x, listnod * next) : val(x), next(next), bottom(nullptr){}
};


int main()
{
    listnode* res=NULL;
    listnode* a=NULL;
    listnode* b=NULL;
    //Created lists, a: 7->4->5, b: 9->2->0
    push(5,&a);
    push(4,&a);
    push(7,&a);
    push(0,&b);
    push(2,&b);
    push(9,&b);
    // b->next->next->next = a->next; // b becomes: 9->2->0->4->5, this is for intersection problem
    linked ob;
    listnode* temp = ob.intersect(a,b);
    ob.printlist(temp);
    
    return 0;
}