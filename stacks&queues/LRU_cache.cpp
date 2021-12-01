#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

class LRUCache {
    public:
        class node {
            public:
                int key;
                int val;
                node* next;
                node* prev;
                node(int _key, int _val) {
                    key = _key;
                    val = _val;
                }
        };

        node* head = new node(-1,-1);
        node* tail = new node(-1,-1);

        int cap;
        unordered_map<int,node*> mpp;

        LRUCache(int capacity) {
            cap = capacity;
            head->next = tail;
            tail->prev = head;
            head->prev = NULL;
            tail->next = NULL;
        }
        void addnode(node *newnode) {
            node* temp = head->next;
            newnode->next = temp;
            newnode->prev = head;
            head->next = newnode;
            temp->prev = newnode;
        }
        void deletenode(node *delnode) {
            node *nprev = delnode->prev;
            node *nnext = delnode->next;
            nprev->next = nnext;
            nnext->prev = nprev;
        }
        int get(int key_) {
            if( mpp.find(key_)!=mpp.end() ) {
                node* resnode = mpp[key_];
                int res = resnode->val;
                mpp.erase(key_);
                deletenode(resnode);
                addnode(resnode);
                mpp[key_] = head->next;
                return res;
            }
            return -1;
        }
        void put(int key_, int value) {
            if(mpp.find(key_)!=mpp.end()) {
                node* exist = mpp[key_];
                mpp.erase(key_);
                deletenode(exist);
            }
            else if(mpp.size()==cap) {
                mpp.erase(tail->prev->key);
                deletenode(tail->prev);
            }
            addnode(new node(key_,value));
            mpp[key_] = head->next;
        }

};

int main()
{
    //int n; cin>>n;
    
    
    return 0;
}



