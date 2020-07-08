#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int         long long
#define mod         1000000007
#define FAST        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n)      for(int i=0;i<n;i++)
#define fp(i,k,n)   for(int i=k;i<=n;i++)
#define fr(i,k,n)   for(int i=k;i>=n;i--)
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define dbg(x)      cout << (#x) << " is " << (x) << '\n' 
#define F           first
#define S           second
#define sz(x)       (int)(x).size()
#define lb          lower_bound
#define ub          upper_bound
#define mems(x)     memset(x,0,sizeof(x))
#define all(a)      a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
/*---------------------------------------------------------------------------------------------------*/

void solve()
{
  string a,b;
  cin >> a >> b;
  int n=a.length(),m=b.length();
  int dp[n+1][m+1];
  mems(dp);
  f(i,n+1)
  {
      f(j,m+1)
      {
          if(i==0 || j==0)
            continue;
           if(a[i-1]==b[j-1])
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
           else
            dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
      }
  }
  int len=dp[n][m];
  string s;
  s="";
  int l=n,r=m;
  while(len>0)
  {
      if(a[l-1]==b[r-1])
      {
          s+=a[l-1];
          l--;r--;
          len--;
      }
      else if(dp[l-1][r]>dp[l][r-1])
        l--;
      else
        r--;
  }
  reverse(all(s));
  cout << s << '\n';
  return;
} 

signed main()
{
  FAST
  int T=1;
//   cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
