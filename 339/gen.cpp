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
using namespace std;
typedef long long ll;
int main()
{
  freopen("in","w",stdout);
  const int mod=1e9;
  for(int i=0;i<250000;++i)
    cout<<(rand()&1?'+':'-')<<' '<<(rand()%mod)<<' '<<(rand()%mod)<<endl;
  return 0;
}
