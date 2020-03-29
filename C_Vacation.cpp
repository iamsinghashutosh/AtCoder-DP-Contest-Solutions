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
  int n;
  cin >> n;
  int a[n+1],b[n+1],c[n+1];
  a[0]=b[0]=c[0]=0;
  fp(i,1,n)
    cin >> a[i] >> b[i] >> c[i];
  int dp[n+1][3];
  dp[0][0]=dp[0][1]=dp[0][2]=0;
  fp(i,1,n)
  {
      dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
      dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]);
      dp[i][2]=c[i]+max(dp[i-1][1],dp[i-1][0]);
  }
  cout << max(dp[n][0],max(dp[n][1],dp[n][2])) << '\n';
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