//0/1 knapsack
#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
    return (a>b) ? a:b;
}

int  kanpsack(int W,int wt[],int n,int val[]){
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(void){
    int W=50;
    int val[]={60,100,120};
    int wt[]={10,20,30};
    int n=3;
    printf("THE MAXIMUM VALUE IN THE KNAPSACK IS-->%d:",kanpsack(W, wt, n, val));
    return 0;
}
