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

//https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C

class Node{
    public:
        int location;
        int p, l, r;
        Node(){}
};

class Point{
    public:
        int id, x, y;
        Point(){}
        Point(int id, int x, int y): id(id), x(x), y(y){}
        bool operator<(const Point &p) const{
            return id < p.id;
        }
        void print(){
            printf("%d\n", id);
        }
};

static const int MAX = 10000000;
static const int NIL = -1;

int N;
Point P[MAX];
Node T[MAX];
int np;

bool lessX(const Point &p1, const Point &p2) { return p1.x < p2.x; }
bool lessY(const Point &p1, const Point &p2) { return p1.y < p2.y; }

int makeKDTree(int l, int r, int depth){
    if(!(l < r))
        return NIL;
    int mid = (l + r) / 2;
    int t = np++;
    if(depth % 2 == 0){
        sort(P + l, P + r, lessX);
    }else{
        sort(P + l, P + r, lessY);
    }
    T[t].location = mid;
    T[t].l = makeKDTree(l, mid, depth + 1);
    T[t].r = makeKDTree(mid + 1, r, depth + 1);
    return t;
}

void find(int v, int sx, int tx, int sy, int ty, int depth, vector<Point> &ans){
    int x = P[T[v].location].x;
    int y = P[T[v].location].y;

    if(sx <= x && x <= tx && sy <= y && y <= ty){
        ans.push_back(P[T[v].location]);
    }

    if(depth % 2 == 0){
        if(T[v].l != NIL){
            if(sx <= x)
                find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
        }
        if (T[v].r != NIL)
        {
            if (x <= tx)
                find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
        }
    }else{
        if(T[v].l != NIL){
            if(sy <= y)
                find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
        }
        if (T[v].r != NIL)
        {
            if (y <= ty)
                find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
        }
    }
}

int main(){
    int x, y;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i){
        scanf("%d %d", &x, &y);
        P[i] = Point(i, x, y);
        T[i].l = T[i].r = T[i].p = NIL;
    }

    np = 0;

    int root = makeKDTree(0, N, 0);

    int q;
    scanf("%d", &q);
    int sx, tx, sy, ty;
    vector<Point> ans;
    for (int i = 0; i < q; i++){
        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
        ans.clear();
        find(root, sx, tx, sy, ty, 0, ans);
        sort(ans.begin(), ans.end());
        for (int j = 0; j < ans.size(); ++j){
            ans[j].print();
        }
        printf("\n");
    }
    return 0;
}