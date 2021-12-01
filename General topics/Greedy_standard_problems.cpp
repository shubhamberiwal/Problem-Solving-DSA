

#include<bits/stdc++.h>
using namespace std;

// tuf

// 1 - N meetings in one room
// given n and start and end time of n meetings
// give maximum number of meet in one room. start of 1 meet can't be equal to another meet
// for eg: n=6 , start : [1,0,3,8,5,8] and end: [2,6,4,9,7,9]
// ans is 4 meet they are 1st, 3rd, 5th and 4th meeting 
// tc: O(nlogn + n)
struct meeting {
    int start;
    int end;
    int pos;
};
bool comparator(meeting m1, meeting m2){
    if(m1.end<m2.end) return true;
    else if(m1.end>m2.end) return false;
    else if(m1.pos<m2.pos) return true;
    return false;
}
void nmeetings(int s[], int e[], int n) {
    meeting meet[n];
    for (int i = 0; i < n; i++) {
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i+1;
    }
    sort (meet, meet+n, comparator);
    vector<int> answer;
    answer.push_back(meet[0].pos);
    int limit = meet[0].end;
    for (int i = 1; i < n; i++) {
        if( limit<=meet[i].start) {
            limit = meet[i].end;
            answer.push_back(meet[i].pos);
        }
    }
    for(auto x: answer){
        cout<<x<<" ";
    }
    cout<<endl;
}


// 2 - Minimum number of platforms required for a railway station
// tc: O(2nlogn) + O(2n), sc: O(1)
void minplatforms(int arr[], int dep[], int n) {
    sort(arr,arr+n);
    sort(dep, dep+n);
    int j=0,k=0;
    int maxplat=0, currentinuse = 0;
    // dept.push_back(dep[0]);
    while(j<n)
    {
        if( arr[j] <= dep[k]){
            currentinuse++;
            maxplat = max(maxplat, currentinuse);
            j++;
        }
        else if( arr[j] > dep[k]){
            currentinuse--;
            k++;
        }
    }
    
}

// 3 - Job sequencing Problem
// 
struct Job{
    int id;
    int deadline;
    int profit;
};
bool comparison(Job a, Job b){
    return (a.profit>b.profit);
}
pair<int,int> Jobscheduling(Job arr[], int n){
    sort(arr, arr+n, comparison);
    int maxi = arr[0].deadline;
    for (int i = 1; i < n; i++){
        maxi = max(maxi, arr[i].deadline);
    }
    int slot[maxi+1];
    for (int i = 0; i <= maxi; i++){
        slot[i] = -1;
    }
    int countjobs = 0, jobprofit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if(slot[j] == -1){
                slot[j] = i;
                countjobs++;
                jobprofit+=arr[i].profit;
                break;
            }
        }
    }
    return make_pair(countjobs, jobprofit);
}
// 4 - Fractional Knapsack
// value and weight of an item given along with total weight
// items can be fractionally divided
// eg: val: 60, 100, 120 and weight: 10, 20, 30 but value per weight : 60, 50, 40
// now if w is given as 50 then choose 10 + 20 + 20(this 20 is taken fractionally from 30) value will be: 240
// tc: O(nlogn)+O(n) sp: O(1)
struct Item{
    int value;
    int weight;
    double valueperweight = value/weight;
};
bool compare(Item a, Item b){
    return ( a.valueperweight > b.valueperweight );
}
double fractionalKnapsack(int w, Item arr[], int n){
    sort(arr, arr+n, compare);
    double currentweight = 0.0;
    double finalvalue = 0.0;
    for(int i = 0; i<n ; i++){
        
        if( currentweight + arr[i].weight <= w){
            currentweight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else {
            double remain = w - currentweight;
            finalvalue += (arr[i].valueperweight * remain);
            break;
        }
    }
    return finalvalue;
}
// 5 - Minimum number of coins
// given a value V. To find the minimum combination of coins to make that value v
// eg: 49 : 20+20+5+2+2
// tc: O(V) sp: O(1)
void findmin(int v){
    vector<int> ans ;
    vector<int> deno = {1,2,5,10,20,50,100,500,1000};
    int n = deno.size();

    for( int i = n-1; i>=1; i--){
        // finding denominations
        while(v>=deno[i]){
            v-=deno[i];
            ans.push_back(deno[i]);
        }
    }
    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

int main()
{

    int s[] = {0,1,3,5,8,5};    
    int e[] = {6,2,4,7,9,9};
    nmeetings(s,e,6);
    
    

    return 0;
}

