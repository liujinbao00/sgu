#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
  int n,t;
  t=1,n=25;
  freopen("in.txt","w",stdout);
  cout<<t<<' '<<n<<endl;
  srand(3);
  for(;t--;)
    {
      for(int i=0;i<n*3;++i)
	cout<<(rand()%1001)<<' ';
      cout<<endl;
    }
  return 0;
}
