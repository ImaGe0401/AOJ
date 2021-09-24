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

//https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B

static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[N][N];
int color[N], d[N], f[N], tt;
int nt[N];

int next(int u){
    for (int v = nt[u]; v < n; v++){
        nt[u] = v + 1;
        if(M[u][v])
            return v;
    }
    return -1;
}

void dfs_visit(int r){
    for (int i = 0; i < n; ++i)
        nt[i] = 0;
    stack<int> S;
    S.push(r);
    color[r] = GRAY;
    d[r] = ++tt;

    while(!S.empty()){
        int u = S.top();
        int v = next(u);
        if(v != -1){
            if(color[v] == WHITE){
                color[v] = GRAY;
                d[v] = ++tt;
                S.push(v);
            }
        }else{
            S.pop();
            color[u] = BLACK;
            f[u] = ++tt;
        }
    }
}

void dfs(){
    for (int i = 0; i < n; ++i){
        color[i] = WHITE;
        nt[i] = 0;
    }
    tt = 0;

    for (int u = 0; u < n; ++u){
        if(color[u] == WHITE)
            dfs_visit(u);
    }
    for (int i = 0; i < n; ++i){
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
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
    dfs();

    return 0;
}