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

const int MX=10e3+5;
int mat[MX][MX];
int vis[MX];
int dx[2]={0,1};
int dy[2]={1,0};
int h,w;
int dp[MX][MX];

bool isValid(int x,int y)
{
    if(x<1 || y<1 || mat[x][y]==0)
        return false;
    return true;
}

int bfs(int x,int y)
{
    if(!isValid(x,y))
        return 0;
    if(x==1 && y==1)
        {
            return 1;
        }
    if(dp[x][y]!=-1)
        return dp[x][y];
    dp[x][y]=0;
    dp[x][y]=bfs(x,y-1)%mod + bfs(x-1,y)%mod;
    dp[x][y]%=mod;
    return dp[x][y];
}

void solve()
{
  cin >> h >> w;
  fp(i,1,h)
  {
      string s;
      cin >> s;
      fp(j,1,w)
      {
          dp[i][j]=-1;
          if(s[j-1]=='.')
            mat[i][j]=1;
           else
            mat[i][j]=0;
      }
  }
  cout << bfs(h,w) << '\n';
   
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
