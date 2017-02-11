#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <utility>

using namespace std;

#define PI 3.141592653589793
#define pi acos(-1.0)
#define eps 1e-10
#define MAX 2000000000
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,a,n) for(int i=(a);i<(n);i++)
#define dec(i,n) for(int i=(n);i>0;i--)
#define decc(i,a,n) for(int i=(a);i>(n);i--)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))
#define mem(a,b) memset((a),(b),sizeof(a))

#define s1d(a) scanf("%d", &a)
#define s2d(a,b) scanf("%d %d",&a,&b)
#define s1ll(a) scanf("%lld", &a)
#define s2ll(a,b) scanf("%lld %lld",&a,&b)
#define s1f(a) scanf("%lf",&a)
#define s2f(a,b) scanf("%lf %lf",&a,&b)
#define p1d(a) printf("%d\n",a)
#define p2d(a,b) printf("%d %d\n",a,b)
#define p1ll(a) printf("%lld\n",a)
#define p2ll(a,b) printf("%lld %lld\n",a,b)
#define p1f(a) printf("%lf\n",a)
#define p2f(a,b) printf("%lf %lf\n",a,b)

typedef long long int lld;
typedef unsigned int ui;

int dirx [] = {-1, 0, 1, 0, -1, 1, 1, -1};
int diry [] = {0, 1, 0, -1, 1, 1, -1, -1};

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

char a[1000005];
vector <string> v;
int name;

struct node
{
    bool endmark;
    int prefix;
    node* next[30];
    node()
    {
        prefix=0;
        endmark=false;
        for(int i=0;i<26;i++)
            next[i]=0;
    }
};

node *root;

void insert(char* str, int len)
{
    node * current;
    current=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(!current->next[id])
            current->next[id]=new node;
        current->next[id]->prefix++;
        current=current->next[id];
    }
    current->endmark=true;

    return;
}

void check(string str,int len)
{
    node* current=root;

    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        current=current->next[id];
        if(current->prefix==1)
        {
            name++;
            break;
        }
        else
            name++;
    }

    return;
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        name=0;
        root=new node;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",a);
            v.push_back(a);
            int len=strlen(a);
            insert(a,len);
        }
        for(int i=0;i<n;i++)
        {
            int len=v[i].size();
            check(v[i],len);
        }

        p1d(name);
        v.clear();
        delete(root);
    }

    return 0;
}



