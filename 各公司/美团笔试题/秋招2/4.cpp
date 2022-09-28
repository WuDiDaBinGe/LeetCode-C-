#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int> 
#define piii pair<pii, int>
/*
小团正忙着用机器人收衣服！因为快要下雨了，小团找来了不少机器人帮忙收衣服。他有n件衣服从左到右成一行排列，所在位置分别为1~n，在每个位置上已经有一个就绪的机器人可以帮忙收衣服，但第 i 个位置上的机器人需要pi的电量来启动，然后这个机器人会用ti的时间收衣服，当它收完当前衣服后，会尝试去收紧邻的右边的一件衣服(如果存在的话)，即 i+1处的衣服，如果 i+1 处的衣服已经被其他机器人收了或者其他机器人正在收，这个机器人就会进入休眠状态，不再收衣服。不过如果机器人没有休眠，它会同样以ti时间来收这件 i+1 处的衣服（注意，不是ti+1的时间，收衣服的时间为每个机器人固有属性），然后它会做同样的检测来看能否继续收 i+2 处的衣服，一直直到它进入休眠状态或者右边没有衣服可以收了。形象地来说，机器人会一直尝试往右边收衣服，收k件的话就耗费k*ti的时间，但是当它遇见其他机器人工作的痕迹，就会认为后面的事情它不用管了，开始摸鱼，进入休眠状态。

小团手里总共有电量b，他准备在0时刻的时候将所有他想启动的机器人全部一起启动，过后不再启动新的机器人，并且启动的机器人的电量之和不大于b。他想知道在最佳选择的情况下，最快多久能收完衣服。若无论如何怎样都收不完衣服，输出-1。



*/
int main()
{
   int n, p; cin>>n>>p;
   vector<int> pbs(n);
   vector<int> times(n);
   priority_queue<piii, vector<piii>, greater<piii>> pq, pq2;
   int need_p_all = 0, max_t = -1;
   for(int i = 0; i < n; ++i) {
      cin>>pbs[i];
      need_p_all += pbs[i];
   }
   for(int i = 0; i < n; ++i) {
      cin>>times[i];
      if(i > 0) {
         pq.push(make_pair(make_pair(pbs[i], times[i]), i));
         pq2.push(make_pair(make_pair(times[i], pbs[i]), i));
      }
      max_t = max(max_t, times[i]);
   }
   if(pbs[0] > p) {
      cout<<-1<<endl;
      return 0;
   }
   // 启动最多的机器人
   vector<int> init_indexs, init_indexs2;
   init_indexs.push_back(0);
   init_indexs2.push_back(0);
   p -= pbs[0];
   int temp_p = p;
   while(!pq.empty() && p >= pq.top().first.first) {
      auto item = pq.top(); pq.pop();
      //cout<<item.second<<endl;
      p -= item.first.first;
      init_indexs.push_back(item.second);
   }
   while(!pq2.empty() && temp_p >= pq2.top().first.second) {
      auto item = pq2.top(); pq2.pop();
      
      temp_p -= item.first.second;
      init_indexs2.push_back(item.second);
   }
   sort(init_indexs.begin(), init_indexs.end());
   sort(init_indexs2.begin(), init_indexs2.end());
   int res = -1;
   int nn = init_indexs.size();
   for(int i = 0; i < nn - 1; ++i) {
      int gap = init_indexs[i + 1] - init_indexs[i];
      int cur_time = times[init_indexs[i]];
      res = max(res, cur_time * gap);
   }   
   //cout<<res<<endl;
   int gap = n - init_indexs[nn - 1];
   int cur_time = times[init_indexs[nn - 1]];
   res = max(res, gap * cur_time);
   int res1 = 0;
   nn = init_indexs2.size();
   for(int i = 0; i < nn - 1; ++i) {
      int gap = init_indexs2[i + 1] - init_indexs2[i];
      int cur_time = times[init_indexs2[i]];
      res1 = max(res1, cur_time * gap);
   }   
   //cout<<res<<endl;
   gap = n - init_indexs2[nn - 1];
   cur_time = times[init_indexs2[nn - 1]];
   res1 = max(res1, gap * cur_time);
   cout<<min(min(res, res1), times[0] * n)<<endl;
   return 0;
}