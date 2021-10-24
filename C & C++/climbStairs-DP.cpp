#include<bits/stdc++.h>
using namespace std;
 
 long int countWays(int n)
    {
        long int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        long long int M = 1000000000+7;
        for(int i = 2 ; i <= n ; i++){
            
                 dp[i] = (dp[i-2] + dp[i-1]) %M;
            
           
        }
      return dp[n];  
    }

int main(){
    int n;
    cin>>n;
    cout<<countWays(n);
    return 0;
}
