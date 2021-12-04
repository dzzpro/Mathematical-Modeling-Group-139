#include <queue>

struct Pre{
	int v;//从起点过来的 前一个点
	int e;//靠近起点的 前一条边 
}pre[maxn];

struct Edge{
	int u, v, w, next;
}edge[maxn << 1];
int cnt = -1, head[maxn];
inline void addedge(int u, int v, int w){
	edge[++cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}
int inq[maxn];
bool bfs(){
	queue <int> q;
	memset(pre, -1, sizeof(pre));
	memset(inq,0,sizeof(inq));
	inq[s] = 1;
	q.push(s);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int i = head[u]; i; i = edge[i].next){
			int v = edge[i].v;
			if(!inq[v] && edge[i].w){
				inq[v] = 1;
				pre[v].v = u;
				pre[v].e = i;
				if(v == t)return 1;
				q.push(v);				
			}
		}
	}
	return 0;//表示是否有增广路 
}
int EK(){
	int ans = 0;
	while(bfs()){
		int mini = INF;
		for(int i = t; i != s; i = pre[i].v){
			mini = min(mini, edge[ pre[i].e ].w);
		}
		for(int i = t; i != s; i = pre[i].v){
			edge[ pre[i].e ].w -= mini; 
			edge[ pre[i].e ^ 1].w += mi;
		}
		ans += mini;
	}
	return ans;
}
int t1, t2, t3;
int main(){
	for(int i = 1; i <= N; i++){
		cin>> t1>> t2>> t3;
		addedge(t1,t2,t3);addedge(t2,t1,0);	
	}
}
