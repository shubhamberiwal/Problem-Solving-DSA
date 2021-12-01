

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
typedef vector<int> vi;

int longest_valid(string s) {

    stack<char> stk;
    int n = s.size();

    // 0 based indexing so push index which is just before 1st element
    // for eg: for "()" ans would be 1-(-1) = 2
    stk.push(-1);
    int ans = 0;
    for(int i=0; i<n; i++) {
        
        // if '(' then push index of it in stack
        if(s[i]=='(') {
            stk.push(i);
        }
        else {
            // pop the previous opening bracket's index
            if(!stk.empty()) {
                stk.pop();
            }
            // check if the length of the current formed 
            // sequence is greater than the answer yet
            if(!stk.empty())
                ans = max(ans, i-stk.top());
            // If stack is empty that means we have excess of ')'
            // and you have to push it after the stack becomes empty
            else 
                stk.push(i);
        }
    }
    return ans;
}

int main()
{
    string str = "))))((())()";
	cout << longest_valid(str) << endl;
	
    str = "())(()))))";
	cout << longest_valid(str) << endl;
    
    return 0;
}



