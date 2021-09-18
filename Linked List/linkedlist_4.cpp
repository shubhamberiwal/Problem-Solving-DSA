

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

    // 10 - reverse list in groups of k
    // My Solution
    listnode* reverseingroups(listnode *head, int k){

        if(head==NULL||k==1) return head;

        int len=0; listnode*thead = head;
        while(thead!=NULL){
            len++;
            thead=thead->next;
        }
        if(len%k==len) return head;
        listnode*dummy=new listnode(0);
        listnode*nextstart=head;
        for (int i = 0; i < len/k; i++)
        {
            listnode* temphead = nextstart;
            listnode* anothertemphead = temphead;
            listnode *end=temphead;
            for (int j = 0; j < k-1; j++)
            {
                end=end->next;
            }
            nextstart = end->next;
            end->next = NULL;
            listnode* holdhead = reverselist(temphead);
            anothertemphead->next = nextstart;
            if(i==0){
                head=holdhead;
                dummy->next = holdhead;
            }
        } // end of for
        return head;
    }
    listnode* reverselist(listnode* head){ // part of above soln 10
        listnode* newhead=NULL;
        while(head!=NULL){
            listnode* temp = head->next;
            head->next = newhead;
            newhead = head;
            head = head->next;
        }
        return head;
    }
    // 10 - reverse list in group clean approach [part 2]
    // cur is pointing to the first of node of one group
    // nex point to subsequent nodes that will come behind cur in that group
    // pre just points to the node before next group to be reversed
    listnode* reversekgroups(listnode* head, int k){
        if(head==NULL||k==1) return head;

        listnode*dummy = new listnode(0);
        dummy->next = head;
        
        listnode *cur=dummy, *pre = dummy, *nex = dummy;
        int count = 0;
        
        while(cur->next!=NULL){
            cur=cur->next;
            count++;
        }

        while(count>=k){
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; i++)
            {
                cur=nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            count-=k;
        }
        return dummy->next;
    }
    // 11 - find start point of cycle in linked list
    listnode* startofcycle(listnode* head){
        if(head ==NULL || head->next ==NULL) return NULL;
        listnode * fast=head, *slow=head, *entry = head;
        int flag = 0;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
                while(entry!=slow){
                    slow = slow->next;
                    entry = entry->next;
                }
        }
        return NULL;
    }
    // 12 - flattening of a linked list
    // tc: O(summation of total number of nodes), sc: O(1)
    listnod* mergetwolist(listnod *a, listnod *b)
    {
        listnod * dummy = new listnod(0);
        listnod * temp = dummy;
        while( 1 ){
            if(a==NULL) { temp->bottom = b; break; }
            else if(b==NULL) { temp->bottom = a; break; }

            if(a->val<=b->val){
                temp->bottom = a;
                temp = temp->bottom;
                a=a->bottom;
            }
            else{
                temp->bottom = b;
                temp = temp->bottom;
                b=b->bottom;
            }
        }
        return dummy->bottom;
    }
    listnod* flatten(listnod *root){

        if(root==NULL || root->next)
            return root;
        root->next = flatten(root->next);

        root = mergetwolist( flatten(root), flatten(root->next));

        return root;

    }
    // 13 - Rotate a linked list
    // tc: O(n) and sc: O(1)
    listnode* rotatell(listnode*head, int k){
        if(!head || !head->next || k==0 ) return head;
        listnode*thead = head;
        int len=1;
        while(thead->next!=NULL) {
            thead = thead->next;
            len++;
        }
        thead->next = head;
        k=k%len;
        k = len-k;
        if(k==len) return head;
        while(k--)  thead=thead->next;
        head = thead->next;
        thead->next = NULL;
        return head;
    }
    // 14 - Clone a linked list
    // will do sometime later
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
    listnode* temp = ob.startofcycle(a);
    ob.printlist(temp);
    
    return 0;
}