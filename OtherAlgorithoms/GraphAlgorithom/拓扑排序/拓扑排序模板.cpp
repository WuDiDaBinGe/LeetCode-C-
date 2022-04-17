#include<bits/stdc++.h>
using namespace std;
int indegree[1000];
vector<int> G[5010];
void Init(){
	for(int i=1;i<=m;i++){
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		G[t1].push_back(t2);
		indegree[t2]++;
	}
}

bool topo(int n){
    queue<int> q, q2;
	for(int i=1;i<=n;i++)
		if(!indegree[i])	q.push(i);    //如果要求字典序，就用优先队列
	int cnt = 0;
	while(!q.empty()){
		cnt++;
		int p = q.front();	q.pop();
		q2.push(p);
		for(int j=0;j<G[p].size();j++){
			int v = G[p][j];
			indegree[v]--;
			if(indegree[v] == 0)	q.push(v);
		}
	}
	if(cnt != n)	return false;   //用于判环
	else{
		while(!q2.empty())	cout<<q2.front()<<" ";	q2.pop();
	}
}