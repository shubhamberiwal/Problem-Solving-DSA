/*
Implement N Queen's problem using Back Tracking
Shubham Beriwala - 4ni19is097
*/
#include<stdio.h>
#include<bits/stdc++.h>  
int place(int m[50], int k)
{   int i;
    for(i=0;i<k;i++)
    if((m[i]==m[k])||(abs(m[i]-m[k])==abs(i-k)))
      return 0;
    return 1;
}
void display(int m[50],int n)
{   int i, j, s[10][10]={0};
    for(i=0;i<n;i++)
    s[i][m[i]]=1;
    for(i=0;i<n;i++)
    { for(j=0;j<n;j++)
        if(s[i][j])
           printf("Q\t");
        else
           printf("x\t");
        printf("\n");
    }
    exit(1);
}
int main()
{   int m[50], s[50][50], n, k;
    printf("Enter number of Queens:");
    scanf("%d",&n);
    printf("\nThe solution for the problem is:\n");
    n--;
    for(m[0]=0, k=0;k>=0; m[k]+=1)
    {
     while((m[k]<=n) && (!place(m,k)))
     m[k]+=1;
     if(m[k]<=n)
       if(k==n)
          display(m,n+1);
       else
       { k++;
         m[k]=-1;
       }
     else
       k--;
    }
}