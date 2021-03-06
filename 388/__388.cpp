#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int N = 107;
int n, m[2];
int p[ N * N * 2 + N * 2 ][5], poi;
int s[ N * 2 ];
int dis[ N * 2 ][2];
bool in[ N * 2 ][2];
int pre[ N * 2 ][2];
int use[ N * 2 ][2];
vector<ppi> q[2];
bool usd[2][ N * N ];
int z[ N * 2 ]; 
vector<int> ed[N];
bool vis[N];
int c[N];
vector<ppi> edd[2];
void add( int a, int b )
{
  ed[a].push_back(b);
  ed[b].push_back(a);
}
void dfs( int v, int from )
{
  if( vis[v] )
    return;
  vis[v] = true;
  c[v] = 1 ^ c[from];
  for( int i = 0; i < ed[v].size(); ++i )
    dfs(ed[v][i], v);
}
int coup( int idx )
{
  return idx + ( idx & 1 ? 1 : -1 );
}
int ad( int from, int to, int f, int c, int id )
{
  ++poi;
  p[poi][0] = to, p[poi][1] = f, p[poi][2] = c, p[poi][3] = s[from],
    s[from] = poi, p[poi][4] = id;
  return poi;
}
int add( int from, int to, int c, int id )
{
  ad( from, to, 1, c, id );
  return ad( to, from, 0, -c, id );
}
int gid( int i )
{
  if( p[i][4] < 0 )
    return p[i][4];
  if( i & 1 )
    return p[i][4];
  return p[i][4] ^ 1;
}
bool test( int ss, int tt )
{
  memset( dis, 1 << 6, sizeof(dis) );
  memset( in, 0, sizeof(in) );
  in[ss][0] = in[ss][1] = true;
  for( int i = s[ss]; i; i = p[i][3] )
    if( p[i][1] )
      {
	int t = p[i][0];
	int j = gid(i);
	// cout << t << ' ' << j << ' ' << p[i][2] << endl;
	dis[t][j] = p[i][2], pre[t][j] = ss,
	  use[t][j] = i;
      }
  // if( ss == 3 )
  //   cout << "!!" << pre[11][0] << ' ' << pre[11][1] << endl;
  for( ; ; )
    {
      int disI = 0, disJ = 0;
      for( int i = 1; i <= 2 * n; ++i )
	for( int j = 0; j < 2; ++j )
	  if( !in[i][j] && dis[disI][disJ] > dis[i][j] && i != tt )
	    disI = i, disJ = j;
      if( disI == 0 )
	break;
      // if( ss == 3 )
      // 	cout << disI << " " << disJ << "!" << endl;
      in[disI][disJ] = true;
      // cout << disI << ' ' << disJ << endl;
      for( int i = s[disI]; i; i = p[i][3] )
	if( p[i][1] && gid(i) != disJ )
	  {
	    int t = p[i][0];
	    int tmp = dis[disI][disJ] + p[i][2];
	    int JJ = p[i][4] < 0 ? disJ : 1 ^ disJ;
	    if( !in[t][JJ] && dis[t][JJ] > tmp )
	      {
		  // cout << "!" << disI << ' ' << in[11][1] << ' ' <<
		  //      in[11][0] << endl;
		// cout << disI << ' ' << t << ' ' << tmp << ' ' << JJ << endl;
		dis[t][JJ] = tmp, pre[t][JJ] = disI, 
		  use[t][JJ] = i;
	      }
	  }
    }
  // if( ss == 3 )
  //   cout << pre[11][0] << ' ' << pre[11][0] << ' ' << pre[11][1] << endl;
  // if( ss == 6 )
  //   {
  //     cout << endl;
  //     for( int i = 1; i <= n * 2; ++i )
  // 	if( dis[i][0] < dis[0][0] || dis[i][1] < dis[0][0] )
  // 	  cout << i << ' ' << dis[i][0] << ' ' << dis[i][1] << endl;
  //     for( int i = s[12]; i; i = p[i][3] )
  //     	// if( p[i][1] )
  //     	cout << '!' << p[i][0] << ' ' << p[i][4] << ' ' << p[i][1] << endl;
  //   }
  if( dis[tt][0] < 0 || dis[tt][1] < 0 )
    {
      for( int i = tt, j = dis[tt][0] < 0 ? 0 : 1; i != ss ;)
	{
	  // cout << i <<  ' ' << j << ' ' << pre[i][j] << ' ' << dis[tt][1] << endl;
	  int u = use[i][j];
	  p[u][1] -= 1, p[ coup( u ) ][1] += 1;
	  i = pre[i][j];
	  if( p[u][4] >= 0 )
	    j ^= 1;
	}
      return true;
    }
  return false;
}
int main()
{
  scanf("%d%d%d", &n, &m[0], &m[1] );
  for( int i = 0; i < 2; ++i )
    for( int j = 0; j < m[i]; ++j )
      {
	int a, b;
	scanf("%d%d", &a, &b);
	add( a, b );
	edd[i].push_back( ppi( a, b ) );
      }
  for( int i = 1; i <= n; ++i )
    if( !vis[i] )
      dfs(i, 0);
  for( int i = 0; i < 2; ++i )
    for( int j = 0; j < edd[i].size(); ++j )
      {
	int a = edd[i][j].first;
	int b = edd[i][j].second;
	if( c[a] )
	  swap(a, b);
	if( i )
	  add( a, b + n, 0, i);
	else add( b, a + n, 0, i );
      }
  for( int i = 1; i <= n; ++i )
    z[i] = add( n + i, i, -1, -1);
  for( ; ; )
    {
      bool chg = false;
      for( int i = 1; i <= n; ++i )
	if( p[ z[i] ][1] == 0 )
	  {
	    if( test( i, n + i ) )
	      {
		int qq1 = z[i];
		int qq2 = coup( qq1 );
		++p[qq1][1];
		--p[qq2][1];
		chg = true;
	      }
	  }
      if( !chg )
	break;
    }
  vector<ppi> a[2];
  int ans(0);
  for( int i = 1; i <= n; ++i )
    if( p[ z[i] ][1] )
      {
	++ans;
	for( int j = s[i]; j; j = p[j][3] )
	  if( ( j & 1 ) && p[j][4] >= 0 && p[j][1] == 0 )
	    {
	      a[ p[j][4] ].push_back( ppi( i, p[j][0] - n ) );
	      break;
	    }
      }
  printf("%d", ans / 2);
  for( int i = 0; i < 2; ++i )
    for( int j = 0; j < a[i].size(); ++j )
      printf("\n%d %d", a[i][j].first, a[i][j].second );
  return 0;
}
