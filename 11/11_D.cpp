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

static const int MAX = 100000;
static const int NIL = -1;
int n;
vector<int> G[MAX];
int color[MAX];

void dfs(int r, int c){
    stack<int> S;
    S.push(r);
    color[r] = c;
    while(!S.empty()){
        int u = S.top();
        S.pop();
        for (int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            if(color[v] == NIL){
                color[v] = c;
                S.push(v);
            }
        }
    }
}

void assignColor(){
    int id = 1;
    for (int i = 0; i < n; ++i)
        color[i] = NIL;
    for (int u = 0; u < n; ++u){
        if(color[u] == NIL)
            dfs(u, id++);
    }
}

int main(){
    int s, t, m, q;
    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    assignColor();
    cin >> q;

    for (int i = 0; i < q; ++i){
        cin >> s >> t;
        if(color[s] == color[t]){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}