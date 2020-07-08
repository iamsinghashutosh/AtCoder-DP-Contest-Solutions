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

const int MX=10e5+5;
vi v[MX];
int dp[MX];

int bfs(int x)
{
    if(dp[x]!=-1)
        return dp[x];
    else
    {
        dp[x]=0;
        for(auto u:v[x])
        {
            dp[x]=max(dp[x],bfs(u)+1);
        }
    return dp[x];
    }
}

void solve()
{
  int n,m;
  cin >> n >> m;
  f(i,m)
    {
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
    }
    fp(i,1,n)
        dp[i]=-1;
    vi ans;
    fp(i,1,n)
    {
       if(dp[i]==-1)
          ans.pb(bfs(i));
    }
    cout << *max_element(all(ans)) << '\n';
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
