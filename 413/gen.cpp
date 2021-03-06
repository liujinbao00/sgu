#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <iostream>
using namespace std;
#define N 100
#define M 1000
int p[N+1][N+1];
int d[N+1];
int main()
{
  freopen("in.txt","w",stdout);
  int tst=1;
  cout<<tst<<endl;
  srand(12);
  for(int i=0;i<tst;++i)
    {
      int n=20,m=30;
      cout<<n<<' '<<m<<endl;
      memset(p,0,sizeof(p));
      memset(d,0,sizeof(d));
      for(int j=0;j<m;++j)
	{
	  for(;;)
	    {
	      int a=1+(rand()%n);
	      int b=1+(rand()%n);
	      if(!p[a][b] && a!=b && d[a]<30 && d[b]<30)
		{
		  ++d[a];
		  ++d[b];
		  p[a][b]=p[b][a]=1;
		  cout<<a<<' '<<b<<endl;
		  break;
		}
	    }
	}
    }
  return 0;
}
