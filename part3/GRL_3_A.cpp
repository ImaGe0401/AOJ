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
static const long long INFTY = (1LL << 29);

vector<int> G[MAX];
bool visited[MAX];
int N;
int prenum[MAX], parent[MAX], lowest[MAX], timer;

void dfs(int current, int prev){
    prenum[current] = lowest[current] = timer;
    timer++;

    visited[current] = true;

    int next;

    visited[current] = true;

    for (int i = 0; i < G[current].size(); ++i){
        next = G[current][i];
        if(!visited[next]){
            parent[next] = current;

            dfs(next, current);
            lowest[current] = min(lowest[current], lowest[next]);
        }else if(next != prev){
            lowest[current] = min(lowest[current], prenum[next]);
        }
    }
}

void art_points(){
    for (int i = 0; i < N; ++i)
        visited[i] = false;
    timer = 1;

    dfs(0, -1);

    set<int> ap;
    int np = 0;
    for (int i = 1; i < N; ++i){
        int p = parent[i];
        if(p == 0)
            np++;
        else if(prenum[p] <= lowest[i])
            ap.insert(p);
    }
    if(np > 1)
        ap.insert(0);
    for (set<int>::iterator it = ap.begin(); it != ap.end(); it++)
        cout << *it << endl;
}

int main(){
    int m;
    cin >> N >> m;

    for (int i = 0; i < m; ++i){
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    art_points();

    return 0;
}