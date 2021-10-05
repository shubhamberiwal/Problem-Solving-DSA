


#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;

// 8 - Target sum
void targetsum(int index, vector<int> &nums, int target, vector<int>&ds){
    
    if( target==0 ){
        for(auto x: ds){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }

    if( nums[index]<=target ){
        ds.push_back(nums[index]);
        targetsum(index+1, nums, target-nums[index], ds);
        ds.pop_back();
    }
    targetsum(index+1, nums, target, ds);
}

// 7 - Print Encodings
// assume all numbers from 1 to 26 represent the english alphabets from a to z
// now an input number n is given you have to print
// eg: given 123 print abc, aw, lc
// this is because 1a2bc3, 1a23w, 12l3c
// 909 is considered invalid input as 09 can't be moved forward
void encodings(string ques, string ans){

    if(ques.size()==0){
        cout<<ans<<endl;
        return;
    }

    if(ques[0]=='0')
        return;
    if(ques.size()>=1){
        int num = ques[0]-'0';
        string rest = ques.substr(1);
        char nowchar = (char)('a'+num-1);
        encodings(rest, ans+nowchar);
    }
    if(ques.size()>=2){
        string subb = ques.substr(0,2);
        string rest = ques.substr(2);
        int num = stoi(subb);
        if(num<=26){
            char nowchar = (char)('a'+num-1);
            encodings(rest, ans+nowchar);
        }
    }
}



void printencodings(string nums, string ans){

    if( nums.size()==0 ){
        cout<<ans<<endl;
        return;
    }
    else if( nums.size()==1){
        if(nums[0]=='0')
            return;
        else{
            int temp = nums[0] - '0';
            char ch = (char)('a'+temp-1);
            cout<<(ans+ch)<<endl;
            return;
        }
    }
    else{
        char ch = nums[0];
        string rest = nums.substr(1);
        if(ch=='0')
            return;
        else{
            int temp = nums[0] - '0';
            char ch = (char)('a'+temp-1);
            printencodings(rest,ans+ch);
        }
        string ch12 = nums.substr(0,2);
        rest = nums.substr(2);

        int ch1 = stoi(ch12);
        if(ch1<=26){
            char code = (char)('a'+ch1-1);
            printencodings(rest, ans+code);
        }
    }
}



// 6.1 - Print all permutations of a string
// tc: O(n!*n) - most optimal solution both in tc and in sc
// one more solution is there where instead of swapping
// you carry with yourself an visited array and at each step
// for every unmarked element call the function again recursively
void allpermutation(int index, string s){
    if(index==s.size()){
        cout<<s<<endl;
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        allpermutation( index+1, s);
        swap(s[index], s[i]);
    }
}

// 6.2 - Print all permutation of a string
// this is a slighty inefficient solution because the substr function used in the soln below
// (in c++) uses a tc of O(N) and hence it increases our time complexity
// here tc becomes: O(n!*n*n) , here that extra n is because of substr function
// compare with above swap soln. 
void allpermutation2( string input, string output){

    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    // gayab kardo uss character ko jisko tum ekbaar select kar rahe ho
    for (int i = 0; i < input.size(); i++)
    {
        char ch = input[i];
        string temp = input.substr(0, i)+input.substr(i+1);
        allpermutation2( temp, output+ch);
    }
}


int main()
{
    // printsubsequenceofastring( "abc", "");
    // generatekeypadcombinations("573", "");
    // skipstairs(5, "");
    // maze1(0,0,3,3,"");
    // printmaze2jumps(0, 0, 3, 3, "");
    // allpermutation(0,"abc");
    // allpermutation2("abc", "");
    encodings("013","");
    return 0;
}


