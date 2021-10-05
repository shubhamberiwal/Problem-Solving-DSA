

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;


// In the following problems, analyse them by making a euler trail(tree)
// and find what choices you want to make at each level of the tree.
// first think and analyse and then proceed to code

// 4 - Permutation 2
// this method is of achieving permutation from combination
// question is same as 3 but the approach is different.
void permutation2( int currentindex, int totalboxes, int selectionsofar, vi&ds, int targetitems, vi &itemsused){
    
    if(currentindex == totalboxes){
        if(selectionsofar >= targetitems){
            for(auto x: ds){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        return; 
    }
    // do not pick anything in this recursion steps
    permutation2( currentindex+1, totalboxes, selectionsofar, ds, targetitems, itemsused);
    // try and pick all possible choices apart from not picking
    for (int i = 1; i <= targetitems; i++)
    {
        if( itemsused[i] != 1 ){
            itemsused[i] = 1;
            ds[currentindex] = i;
            permutation2( currentindex+1, totalboxes, selectionsofar+1, ds, targetitems, itemsused);
            ds[currentindex] = 0;
            itemsused[i] = 0;
        }
    }
}


// 3 - Permutation 1
// normal permutation method
// Unlike in previous question this time you're given unidentical items
// and you have to find the number of ways first that they can be selected and then
// also considered the number of ways they can be arranged, so basically find the permutation here
void permutation1(int currentbox, int totalboxes, vi&ds, int targetpermutation){
    
    if(currentbox>targetpermutation){
        for(auto x: ds){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    
    for (int i = 0; i < totalboxes; i++)
    {
        if( ds[i]==0){
            ds[i] = currentbox;
            permutation1( currentbox+1, totalboxes, ds, targetpermutation);
            ds[i] = 0;
        }
    }    
}


// 2 - Combination 2
// this method is: permutation se combination banane ka tareeka
// same quesion given number of boxes and some identical items
// print ways to place them in boxes. 1 box can have 1 items

void combination2( int level, int totalboxes, int currentitems, vi &box, int targetcombination){
    if( level>targetcombination){
        return;
    }
    if(currentitems == targetcombination){
        for(auto x: box){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    for (int i = level+1; i < totalboxes; i++)
    {
        if( box[i] == 0 ){
            box[i] = 1;
            combination2( i, totalboxes, currentitems+1, box, targetcombination);
            box[i] = 0;
        }
    }
}

// 1 - Combination 1
// normal combination
// try and understand this concept, this is problem on combination 
// that means the items here are treated as identical.
// Permutation is different and this problem is on combination
// this problem is where you have 'n' totalboxes given and you have to place 
// 'i' identical items in it(target combination). So this problem can be
// interpreted as selection of i boxes from given n boxes. So just print the ways you can do that.
void combination1( int currentbox, int totalboxes, int selectionsofar, vi&ds, int targetcombination){
    if(currentbox==totalboxes+1){
        if(selectionsofar==targetcombination){
            for(auto x: ds){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        return;
    }
    ds.pb(1);
    combination1( currentbox+1, totalboxes, selectionsofar+1, ds, targetcombination);
    ds.pop_back();
    ds.pb(0); // 0 means that box is not selected
    combination1( currentbox+1, totalboxes, selectionsofar, ds, targetcombination);
    ds.pop_back();
}


int main()
{

    // utility calls and variables for ques1
    // vi ds;
    // int totalboxes = 4;
    // int currentbox = 1;
    // int targetboxes = 2;
    // int selectionsofar = 0;
    // combination1(currentbox, totalboxes, selectionsofar, ds, targetboxes);
    
    // utility calls and vairalbes for ques2
    // vi ds2(4,0);
    // combination2( -1, 4, 0, ds2, 3);

    // utility calls and variables for ques3
    // vi ds3(4,0);
    // permutation1(1, 4, ds3, 3);

    // utility calls and variables for ques4
    vi ds(4,0);
    vi itemsused((4+1),0);

    permutation2(0,4,0,ds,3,itemsused);

    return 0;
}


