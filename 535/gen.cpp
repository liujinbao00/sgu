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
typedef long long ll;
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
int main()
{
  freopen("in","w",stdout);
  srand(19);
  for(int i=0,j=0;i<20;++i)
    if(j<5 && (rand()%5<1))
      {
	printf("*");
	++j;
      }
    else
      printf("%c",(rand()%('B'-'A'+1))+'A'+((rand()%2)?0:'a'-'A'));
  return 0;
}
