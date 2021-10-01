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

//https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C

static const int MAX = 100000;
static const long long INFTY = (1 << 30);

class Edge{
    public:
        int t, w;
        Edge(){}
        Edge(int t, int w): t(t), w(w){}
};

vector<Edge> G[MAX];
int n, d[MAX];

bool vis[MAX];
int cnt;

void bfs(int s){
    for (int i = 0; i < n; ++i)
        d[i] = INFTY;
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    int u;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for (int i = 0; i < G[u].size(); ++i){
            Edge e = G[u][i];
            if(d[e.t] == INFTY){
                d[e.t] = d[u] + e.w;
                Q.push(e.t);
            }
        }
    }
}

void solve(){
    bfs(0);
    int maxv = 0;
    int tgt = 0;
    for (int i = 0; i < n; ++i){
        if(d[i] == INFTY)
            continue;
        if(maxv < d[i]){
            maxv = d[i];
            tgt = i;
        }
    }

    bfs(tgt);
    maxv = 0;
    for (int i = 0; i < n; ++i){
        if(d[i] == INFTY)
            continue;
        maxv = max(maxv, d[i]);
    }
    cout << maxv << endl;
}

int main(){
    int s, t, w;
    cin >> n;
    for (int i = 0; i < n-1; ++i){
        cin >> s >> t >> w;
        G[s].push_back(Edge(t, w));
        G[t].push_back(Edge(s, w));
    }
    solve();
}