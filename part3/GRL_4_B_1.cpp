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
list<int> out;
bool V[MAX];
int N;
int indeg[MAX];

void bfs(int s){
    queue<int> q;
    q.push(s);
    V[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        out.push_back(u);
        for (int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            indeg[v]--;
            if(indeg[v] == 0 && !V[v]){
                V[v] = true;
                q.push(v);
            }
        }
    }
}

void tsort(){
    for (int i = 0; i < N; ++i){
        indeg[i] = 0;
    }

    for (int u = 0; u < N; ++u){
        for (int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            indeg[v]++;
        }
    }
    for (int u = 0; u < N; ++u)
        if(indeg[u] == 0 && !V[u])
            bfs(u);
    for (list<int>::iterator it = out.begin(); it != out.end(); ++it){
        cout << *it << endl;
    }
}

int main(){
    int s, t, M;
    cin >> N >> M;

    for (int i = 0; i < N;++i)
        V[i] = false;
    for (int i = 0; i < M; ++i){
        cin >> s >> t;
        G[s].push_back(t);
    }
    tsort();

    return 0;
}