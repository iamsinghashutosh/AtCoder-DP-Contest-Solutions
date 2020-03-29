/*
 Ashutosh Singh
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include<boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define mod 1000000007
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i++)
#define fr(i,k,n) for(int i=k;i>=n;i--)
#define pb push_back
#define F first
#define S second
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
 
void solve()
{
  int n,lim;
  cin >> n >> lim;
  int wt[n+1],val[n+1];
  fp(i,1,n)
    cin >> wt[i] >> val[i]; 
  int dp[n+1][lim+1];
  
  fp(i,0,n)
   { 
       fp(w,0,lim)
       { 
           if(i==0 || w==0)
            dp[i][w]=0;
           else if(wt[i]<= w) 
              dp[i][w] = max(val[i] + dp[i-1][w-wt[i]],  dp[i-1][w]); 
           else
              dp[i][w] = dp[i-1][w]; 
       } 
   } 
      
  cout << dp[n][lim] << '\n';
  return ;
}

signed main()
{
   FAST;
	int T=1;
	// cin >> T;
	while(T--)
	{
		solve();
	}
    return 0;
}