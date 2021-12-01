

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;


struct stk{
    int data;
    struct stk*next;
};
void initstk(stk*s) {
    s = NULL;
}
int top(stk*s) {
    return s->data;
}
bool isEmpty(stk*s) {
    if(s==NULL)
        return false;
    return true;
}
int pop(stk*s) {
    if(!isEmpty(s)) {
        int temp = s->data;
        stk *t = s;
        s = s->next;
        free(t);
        return temp;
    }
}
int push(stk*s, int x) {
    stk *p = (stk *)malloc(sizeof(*p));
    p->data = x;
    p->next = s;
    s = p;
}
void sort_insert(stk*s, int x) {
    if( isEmpty(s) || x>top(s)) {
        push(s,x);
        return;
    }
    int temp = pop(s);
    sort_insert(s,x);
    push(s,temp);
}
void sort_stack(stk*s){
    if(!isEmpty(s)) {
        int x = pop(s);
        sort_stack(s);
        sort_insert(s, x);
    }
}
void printStack(stk*s) {
    stk *traverse = s;
    while(traverse!=NULL) {
        cout<<s->data<<" ";
        s=s->next;
    }
    cout<<endl;
}

int main()
{
    //int n; cin>>n;
    
    
    return 0;
}







