//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <bits/stdc++.h>
#include<queue>
#include <numeric>
using namespace std;
 
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
 
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
 template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define fore(i,a) for(auto &i:a)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
 
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C

static const int N = 100;
static const int INFTY = (1 << 21);

int n, M[N][N];
int d[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    for (int i = 0; i < n; ++i)
        d[i] = INFTY;
    d[s] = 0;
    int u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v){
            if(M[u][v] == 0)
                continue;
            if(d[v] != INFTY)
                continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    for (int i = 0; i < n; ++i){
        cout << i+1 << " " << ((d[i] == INFTY) ? (-1) : d[i]) << endl;
    }
}

int main(){
    int u, k, v;

    cin >> n;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            M[i][j] = 0;
    }
    for (int i = 0; i < n; ++i){
        cin >> u >> k;
        u--;
        for (int j = 0; j < k; ++j){
            cin >> v;
            v--;
            M[u][v] = 1;
        }
    }
    bfs(0);

    return 0;
}