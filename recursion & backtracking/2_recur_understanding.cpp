

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


// 5.1 - Print Maze Path with jumps: combination of previous 2 questions 3 and 4.
// here you have same maze as in previous prob 4. but here you can move 
// in diagonal direction too. Also as in prob 3 you can make jumps.
// one can make as many jumps as you want if the size of the matrix permits
// for that jump to take place. Your task is to print all the ways you can reach
// the end of the maze
// note: still you can move in either right, down or lower right diagonal direction
void printmaze2jumps(int i, int j, int n, int m, string storepath){

    // here this negative base case is not necessary because you have made 
    // func. calls accordingly that checks that you haven't violated the boundaries of the maze
    // if(i>=n || j>=m)
    //     return;
    if( i==n-1 && j==m-1 ){
        cout<<storepath<<endl;
        return;
    }
    for (int x = i+1; x < n ; x++)
    {
        string temp = "D"+to_string(x-i);
        printmaze2jumps( i+(x-i), j, n, m, storepath+temp );
    }
    for (int x = j+1; x < m ; x++)
    {
        string temp = "R"+to_string(x-j);
        printmaze2jumps( i, j+(x-j), n, m, storepath+temp );
    }
    // check for diagonal paths. T for Tedha/Tircha or diagonal
    int count=1;
    int i2=i, j2=j;
    while( i2+1<n && j2+1<m ){
        string temp = "T"+to_string(count);
        printmaze2jumps( i+count, j+count, n, m, storepath+temp);
        count++;
        i2++;j2++;
    }
}

// 5.2 - Same problem as above but this time you have to store it in a array and return 
vector<string> getjumpmazepaths(int i, int j, int n, int m, string storepath){

    if(i==n-1 && j==m-1){
        vector<string> res = {""};
        return res;
    }   

    vector<string> ans;
    for(int k=1; k<n-i; k++){
        vector<string> down = getjumpmazepaths( i+k, j, n, m, storepath);
        for(auto x: down){
            ans.push_back("D"+to_string(k)+storepath);
        }
    }
    for(int k=1; k<m-j; k++){
        vector<string> right = getjumpmazepaths( i, j+k, n, m, storepath);
        for(auto x: right){
            ans.push_back("R"+to_string(k)+storepath);
        }
    }
    for (int k = 1; k <= n-i && k<=m-j; k++)
    {
        vector<string> diagonal = getjumpmazepaths( i+k, j+k, n, m, storepath);
        for(auto x: diagonal){
            ans.push_back("T"+to_string(k)+storepath);
        }
    }
    return ans;

}


// 4 - Print Maze Path: given an n*m maze. You start from (0,0) and you have to reach the final
// destination that is (n-1,m-1). At one point you can either move right or down.
void maze1(int i, int j, int n, int m, string storepath){
    
    if(i>=n || j>=m) 
        return;
    if(i==n-1&&j==m-1){
        cout<<storepath<<endl;
        return;
    }
    maze1( i, j+1, n, m, storepath+'R');
    maze1( i+1, j, n, m, storepath+'D');
}

// 3 - Print Stair Path: print ways you can come down the stairs when initially standing at nth stair
// you can have 3 choices of skipping stairs at a time, they are [1, 2, 3]
// eg: currently you're at 4 stair then possible answers for ways to 
// reach ground floor or 0th floor are: [31, 22, 211, 13, 121, 112, 1111]
void skipstairs(int n, string storepath){
    if(n==0){
        cout<<storepath<<endl;
        return;
    }
    if(n>=3)
        skipstairs(n-3, storepath+'3');
    if(n>=2)
        skipstairs(n-2, storepath+'2');
    if(n>=1)
        skipstairs(n-1, storepath+'1');
}

// 2 - print key pad combinations
// given below is codes for a particular keypad number, here it corresponds to the index
// so eg: number given "573" then print all words formed using those words at 5th, 7th and 3rd index
// or do a cartesian product of "mno"X"tu"X"ghi", this will give 18 words.
vector<string> codes = { ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
void generatekeypadcombinations(string num, string storesub) {

    if( num.empty() ){
        cout<<storesub<<endl;
        return;
    }
    int n = num[0]-'0';
    for (int i = 0; i < codes[n].size(); i++){
        generatekeypadcombinations( num.substr(1), storesub+codes[n][i] );
    }
}

// 1.1 - print all subsequences of a string
void printsubsequenceofastring( string s, string storesub){
    if(s.empty()){
        cout<<storesub<<endl;
        return;
    }
    printsubsequenceofastring( s.substr(1), storesub+s[0]);
    printsubsequenceofastring( s.substr(1), storesub);
}

// 1.2 - Store all subsequence and return them in a string vector
// Expectation : subsequenc(abc) -> [---, --c, -b-, -bc, a--, a-c, ab-, abc]
// faith : subsequence(bc) -> [--, -c, b-, bc]
vector<string> storeallsubsequence(string s){
    if(s.empty()){
        vector<string> res = {""};
        return res;
    }
    vector<string> res;
    char c = s[0];
    string rest = s.substr(1);
    vector<string> temp = storeallsubsequence(rest);
    for(auto x: temp){
        res.pb(x);
    }
    for(auto x: temp){
        res.pb(c+x);
    }
    return res;
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


