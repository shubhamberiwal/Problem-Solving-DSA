

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

struct stk {
    int data;
    struct stk *next;
};

void initStack(struct stk** s) {*s = NULL;}

int isEmpty(struct stk *s) {
    if( s==NULL )
        return 1;
    return 0;
}
void push(struct stk **s, int x) {
    struct stk*p = (struct stk*)malloc(sizeof(*p));
    p->data = x;
    p->next = *s;
    *s = p;
}
int pop(struct stk**s) {
    int x; 
    struct stk*temp;
    x = (*s)->data;
    temp = *s;
    *s = (*s)->next;
    free(temp);
    return x;
}
int top(struct stk*s) {
    return s->data;
}
void sortinsert(struct stk**s, int x) {
    if( !isEmpty(*s) && x>top(*s))
        push(s,x);
        return;
    int temp = pop(s);
    sortinsert(s,x);
    push(s,temp);
}
void sortstack(struct stk**s) {
    if(!isEmpty(*s))
    {
        int x = pop(s);
        sortstack(s);
        sortinsert(s,x);
    }
}
int main()
{
    //int n; cin>>n;
    
    
    return 0;
}



