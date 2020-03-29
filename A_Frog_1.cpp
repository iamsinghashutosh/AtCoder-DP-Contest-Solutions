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
  int n,k;
  cin >> n >> k;
  int a[n+1];
  fp(i,1,n)
    cin >> a[i];
  int cst[n+1];
  fill(cst,cst+n+1,mod);
  cst[1]=0;
  cst[2]=cst[1]+abs(a[2]-a[1]);
  fp(i,3,n)
  {
     for(int j=i-1;j>=(i-k),j>=1;j--)
        cst[i]=min(cst[j]+abs(a[j]-a[i]),cst[i]);
  }
  cout << cst[n] << '\n';
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
