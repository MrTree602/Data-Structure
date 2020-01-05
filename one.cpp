/*题目描述
大雪履盖了整个城市，市政府要求冬季服务部门尽快将一些街道（列在一份清单中）的积雪清除掉以恢复交通，整个城市由许多交叉路口和街道构成，当然任意两个交叉路口都是直接或间接连通的，清单给出了最少的街道，使得这些街道的积雪清除后任意两个交叉路口之间有且仅有一条通路，冬季服务部门只有一辆铲雪车及一名司机，这辆铲雪车的出发点位于某个交叉路口。
无论街道上有没有积雪，铲雪车每前进一米都要消耗一升燃料，冬季服务部门要求司机在铲除清单上的所有街道的积雪的前提下，要求消耗燃料最少，积雪铲完后车可以停在任意的交叉路口。
大雪履盖了整个城市，市政府要求冬季服务部门尽快将一些街道（列在一份清单中）的积雪清除掉以恢复交通，整个城市由许多交叉路口和街道构成，当然任意两个交叉路口都是直接或间接连通的，清单给出了最少的街道，使得这些街道的积雪清除后任意两个交叉路口之间有且仅有一条通路，冬季服务部门只有一辆铲雪车及一名司机，这辆铲雪车的出发点位于某个交叉路口。
无论街道上有没有积雪，铲雪车每前进一米都要消耗一升燃料，冬季服务部门要求司机在铲除清单上的所有街道的积雪的前提下，要求消耗燃料最少，积雪铲完后车可以停在任意的交叉路口。
输入	
输入文件的第一行包含两个整数N和S，1≤N≤100000，1≤S≤N。N为交叉路口的总数；S为铲雪车出发的路口序号。路口的标号为1~N。
接下来的N-1行为清单上的街道，每一行包含三个用空格隔开的整数A、B、C，表示一条从交叉路口A到交叉路口B的街道，C为该街道的长度，单位为米，1≤C≤1000。
输出
输出文件仅一行包含一个整数表示清除所有积雪所需的最少的燃料数量。*/

//attempt1
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
  
const int N=100010;
#define max(a,b) a>=b?a:b
  
struct node {
    int v,w;
    node() {};
    node(int V,int W) { v=V;w=W; };
};
  
int n,p,f[N],sum,maxx;
vector <node> G[N];
 
void dfs(int u,int fa) {//求树的直径
    for(int i=0,v,w;i<G[u].size();i++) {
        v=G[u][i].v,w=G[u][i].w;
        if(v==fa) continue;
        dfs(v,u);
        maxx=max(maxx,f[u]+f[v]+w);
        f[u]=max(f[u],f[v]+w);
    }
}
int main() {
    cin>>n>>p;
    for(int i=1,u,v,w;i<n;i++) {
        cin>>u>>v>>w;
        sum+=2*w;
        G[u].push_back( node(v,w) );
        G[v].push_back( node(u,w) );
    }
    dfs(p,0);
    cout<<sum-maxx;
}
