/*
    Author：Yu Xiubin
    Date：2021.05.19
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<ctime>
#include<map>
using namespace std;
#define PASTCOST 2           //定义路径值
#define MANHATTAN 1
#define HAMMING 2
#define OuShi 3
//输入出文件
ifstream infile("Npuzzle_in.txt");
ofstream outfile("Npuzzle_out.txt");
//Search Node Class
class Node
{
    public:
        int parent;                             //父节点 
        vector<vector<int>> state;              //数码状态                          
        int size;                               //大小
        int f;                                  //f=g+h
        int g;                                  //g表示目前的代价
        int h;                                  //h表示到target的代价
        Node():g(0),h(0),f(g+h){};
        Node(int N);
        void initByN(int N);                                    //通过大小N初始化
        bool operator <(const Node &s) const;                   //重载运算符实现优先级队列
        bool operator ==(const Node &s) const;                  //重载等号，判断两个Node的状态值
        int countHByMH(Node &s);                                //计算到另一个节点的Manhattan距离
        int countByHAIMING(Node &s);                            //计算到另一个节点的HaiMing距离
        int countByEuclideanD(Node &s);                         //计算到另一个节点的欧式距离
        void show();                                            //显示状态函数
        int findValueInState(int goal,int &row,int &col);       //在State中找到元素并记录坐标值
        void setFGH(int gg,int hh){g=gg;h=hh;f=g+h;};       //设置启发式的值
        int getInvCount();                                      //获得序列的逆序对
        int getChildByMove(int direction,int cost,Node &children,Node& t,int hn);  //获得子节点的函数 0：左 1：上 2：右 3：下
};
Node::Node(int N)
{
    if(N<2||N>6){
        cout<<"请输入正确的N值2-6"<<endl;
        return;
    }
    size=N;
    state.resize(size);
    for(int i=0;i<size;i++)
        state[i].resize(size);
    g=0;f=0;h=0;
    parent=-1;
}
void Node::initByN(int N)
{
    if(N<2||N>6){
        cout<<"请输入正确的N值2-6"<<endl;
        return;
    }
    size=N;
    state.resize(size);
    for(int i=0;i<size;i++)
        state[i].resize(size);
    g=0;f=0;h=0;
    parent=-1;
}
void Node::show()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            outfile<<state[i][j]<<" ";
        outfile<<endl;
    }
}
bool Node::operator <(const Node &s) const{
    return f>s.f;
}
bool Node::operator ==(const Node &s) const
{
    if(size!=s.size) return false;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(state[i][j]!=s.state[i][j])
                return false;
        }
    }
    return true;
}
/*
    找到返回1，找不到返回-1。
    找到的话记录行和列的坐标。
*/
int Node::findValueInState(int goal,int &row,int &col)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(goal==state[i][j])
            {
                row=i;
                col=j;
                return 1;
            }
        }
        
    }
    return -1;
}
/*
    计算两个节点之间的曼哈顿距离，海明距离和欧式距离。如出错返回-1
*/
int Node::countHByMH(Node &s)
{
    int sum=0;
    int x,y;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(state[i][j]==0) continue;
            //找到了
            if(s.findValueInState(state[i][j],x,y)){
                sum+=abs(x-i)+abs(y-j);
            }
            //找不到报错
            else return -1;
        }
    }
    return sum;
}
int Node::countByHAIMING(Node &s)
{
    int sum=0;
    int x,y;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            if(state[i][j]&&state[i][j]!=s.state[i][j]) sum++;
    }
    return sum;
}
int Node::countByEuclideanD(Node &s)
{
    int sum=0;
    int x,y;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(state[i][j]==0) continue;
            //找到了
            if(s.findValueInState(state[i][j],x,y))
                sum+=sqrt(pow((x-i),2)+pow((y-j),2));
            //找不到报错
            else return -1;
        }
    }
    return sum;
}
/*
    获得子节点的函数 0：左  1：上  2：右  3：下
    child记录获得的子节点
*/
int Node::getChildByMove(int direction,int cost,Node &child,Node& t,int hn)
{
    int x,y;                    //记录空白格的坐标
    if(findValueInState(0,x,y)==0) return -1; 
    //先将父节点State赋值给子节点
    for(int i=0;i<size;i++)
        child.state[i].assign(state[i].begin(),state[i].end());
    if (direction==0)           //左移空白格
    {
        if(y==0)
            return -1;
        else{
            child.parent=2;
            swap(child.state[x][y],child.state[x][y-1]);
        }
    }
    else if(direction==1)       //上移空白格
    {
        if(x==0)
            return -1;
        else{
            child.parent=3;
            swap(child.state[x][y],child.state[x-1][y]);
        }
    }
    else if(direction==2)       //右移空白格
    {
        if(y==(size-1))
            return -1;
        else{
            child.parent=0;
            swap(child.state[x][y],child.state[x][y+1]);
        }
    }
    else if(direction==3)       //下移空白格
    {
        if(x==(size-1))
            return -1;
        else{
            child.parent=1;
            swap(child.state[x][y],child.state[x+1][y]);
        }
    }
    if(hn==MANHATTAN)
        child.setFGH(g+cost,child.countHByMH(t));
    else if(hn==HAMMING)
        child.setFGH(g+cost,child.countByHAIMING(t));
    else if(hn==OuShi)
        child.setFGH(g+cost,child.countByEuclideanD(t));
    return 1;
}
/*
    归并排序并算出逆序数
*/
int mergeSort(vector<int>& nums,vector<int>& tmp,int l,int r)
{
    if(l>=r)
        return 0;
    int mid=(l+r)/2;
    int inv_count=mergeSort(nums,tmp,l,mid)+mergeSort(nums,tmp,mid+1,r);
    int i=l,j=mid+1,pos=l;
    while(i<=mid&&j<=r){
        if(nums[i]<=nums[j]){
            tmp[pos]=nums[i];
            inv_count+=(j-(mid+1));
            i++;
        }
        else{
            tmp[pos]=nums[j];
            j++;
        }
        pos++;    
    }
    for (int ll = i; ll <=mid; ll++)
    {
        tmp[pos++]=nums[ll];
        inv_count+=(j-(mid+1));
    }
    for (int rr = j; rr <= r; rr++)
        tmp[pos++]=nums[rr];
    copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
    return inv_count;
}
/*
    返回该节点状态的逆序对
*/
int Node::getInvCount(){
    vector<int> array;
    //先将State其转换成数组除去0
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (state[i][j]==0) continue;
            array.push_back(state[i][j]);   
        }
    }
    vector<int> tmp(array.size());
    return mergeSort(array,tmp,0,array.size()-1);
}


//大小
int N;
//初始状态节点
Node initNode;
//目标状态节点
Node targetNode;

//初始化函数
void initInputState()
{
    infile>>N;
    //初始化大小
    initNode.initByN(N);
    initNode.g=0;
    targetNode.initByN(N);
    //获得初始状态
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            infile>>initNode.state[i][j];
        }
    }
    //获得目标状态
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            infile>>targetNode.state[i][j];
        }
    }
    infile.close();
}
/*
    判断一个vector中是否有Node元素
    有返回index，无则返回-1
*/
int searchInVector(vector<Node> v,Node &node)
{
    for (int i = 0; i < v.size(); i++)
        if(v[i]==node) return i;
    return -1;
}
/*
    从目标节点开始回溯路径,需要explore队列
*/
void printPath(Node node,vector<Node> visited)
{
    vector<Node> path;
    //加入目标节点
    path.push_back(node);
    while(node.parent!=-1)
    {
        Node tmpNode=Node(N);
        int flag=node.getChildByMove(node.parent,1,tmpNode,targetNode,-1);
        path.push_back(tmpNode);
        int t_index=searchInVector(visited,tmpNode);
        if (t_index!=-1)
            node=visited[t_index];
        else
        {
            cout<<"出错"<<endl;
            return ;
        }
    }
    reverse(path.begin(),path.end());
    outfile<<"共"<<path.size()-1<<"步"<<endl;
    outfile<<"初始状态"<<endl;
    initNode.show();
    for (int i = 1; i < path.size()-1; i++){
        outfile<<"第"<<i<<"步"<<endl;
        path[i].show();
    }
    outfile<<"目标状态"<<endl;
    targetNode.show();
}
/*
    判断初始和目标节点是否有解
*/
bool isAvaliableSearch(Node& start,Node& end){
    int f_1=start.getInvCount();
    int f_2=end.getInvCount();
    if ((f_1%2)==(f_1%2))
        return true;
    else
        return false;
}
/*
    无解返回-1，找到返回1
*/
vector<Node> explored;
Node childTarget;
int aStarSearch(int hn)
{
    if (!isAvaliableSearch(initNode,targetNode))
        return -1;
    //frontier
    vector<Node> frontier;
    //explored

    frontier.push_back(initNode);
    while (true)
    {
        if(frontier.empty()) return -1;             //返回失败
        sort(frontier.begin(),frontier.end());      //按照f从大到小的顺序排列
        Node currentNode=frontier.back();
        frontier.pop_back();
        vector<Node> childNodeList;
        explored.push_back(currentNode);
        for(int i=0;i<4;i++)
        {
            Node tmpChildNode=Node(N);
            int flag=currentNode.getChildByMove(i,PASTCOST,tmpChildNode,targetNode,hn);
            if(flag!=-1)    childNodeList.push_back(tmpChildNode);
        }
        //对子节点进行目标测试
        for(int i=0;i<childNodeList.size();i++)
        {
            if(childNodeList[i]==targetNode)
            {
                childTarget=childNodeList[i];
                //printPath(childNodeList[i],explored);
                return 1;
            }
        }
        //将childNode加入到frontier中
        for(int i=0;i<childNodeList.size();i++)
        {
            int indexInFront=searchInVector(frontier,childNodeList[i]);
            int indexInExplored=searchInVector(explored,childNodeList[i]);
            if(indexInExplored==-1&&indexInFront==-1)
                frontier.push_back(childNodeList[i]);
            else if(indexInFront!=-1)
            {
                if(frontier[indexInFront].f>childNodeList[i].f)
                {
                    frontier.erase(frontier.begin()+indexInFront);
                    frontier.push_back(childNodeList[i]);
                }
            }
        }
    }
}
int main()
{
    initInputState();
    
    clock_t start = clock();
    int result=aStarSearch(OuShi);
    clock_t end = clock();
    if(result==-1)
        cout<<"无解！"<<endl;
    else{
        cout<<"扩展了节点个数:"<<explored.size()<<endl;
        cout<<"搜索用时为："<<(double)(end - start) / CLOCKS_PER_SEC<<"s"<<endl;
        printPath(childTarget,explored);
        cout<<endl;
    }
    outfile.close();
    return 0;
}