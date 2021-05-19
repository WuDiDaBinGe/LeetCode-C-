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
using namespace std;

//Search Node Class
class Node
{
    public:
        Node* parent;                           //父节点 
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
        void show();                                            //显示状态函数
        int findValueInState(int goal,int &row,int &col);       //在State中找到元素并记录坐标值
        void setFGH(int gg,int hh){g=gg;h=hh;f=g+h;};           //设置启发式的值
        int getChildByMove(int direction,int cost,Node &children,Node& t);  //获得子节点的函数 0：左 1：上 2：右 3：下
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
}
void Node::show()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout<<state[i][j]<<" ";
        }
        cout<<endl;
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
    计算两个节点之间的曼哈顿距离，如出错返回-1
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
/*
    获得子节点的函数 0：左 1：上 2：右 3：下
    child记录获得的子节点
*/
int Node::getChildByMove(int direction,int cost,Node &child,Node& t)
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
            swap(child.state[x][y],child.state[x][y-1]);
            child.setFGH(g+cost,child.countHByMH(t));
            child.parent=this;
        }
    }
    else if(direction==1)       //上移空白格
    {
        if(x==0)
            return -1;
        else{
            swap(child.state[x][y],child.state[x-1][y]);
            child.setFGH(g+cost,child.countHByMH(t));
            child.parent=this;
        }
    }
    else if(direction==2)       //右移空白格
    {
        if(y==(size-1))
            return -1;
        else{
            swap(child.state[x][y],child.state[x][y+1]);
            child.setFGH(g+cost,child.countHByMH(t));
            child.parent=this;
        }
    }
    else if(direction==3)       //下移空白格
    {
        if(x==(size-1))
            return -1;
        else{
            swap(child.state[x][y],child.state[x+1][y]);
            child.setFGH(g+cost,child.countHByMH(t));
            child.parent=this;
        }
    }
    return 1;
}
//输入文件
ifstream infile("Npuzzle_in.txt");
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
    initNode.parent=NULL;
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
    从目标节点开始回溯路径
*/
void printPath(Node *node)
{
    if(node->parent!=NULL)
    {
        printPath(node->parent);
    }
    node->show();
    cout<<endl;
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
    无解返回-1，找到返回1
*/
int aStarSearch()
{
    //frontier
    vector<Node> frontier;
    //explored
    vector<Node> explored;
    if (initNode==targetNode)
    {
        targetNode.parent=NULL;
        printPath(&initNode);
        return 1;
    }
    frontier.push_back(initNode);
    while (true)
    {
        //返回失败
        if(frontier.empty()) return -1;
        sort(frontier.begin(),frontier.end());      //按照f从大到小的顺序排列
        Node currentNode=frontier.back();
        frontier.pop_back();
        vector<Node> childNodeList;
        for(int i=0;i<4;i++)
        {
            Node tmpChildNode=Node(N);
            int flag=currentNode.getChildByMove(i,1,tmpChildNode,targetNode);
            if(flag!=-1)    childNodeList.push_back(tmpChildNode);
        }
        //对子节点进行目标测试
        for(int i=0;i<childNodeList.size();i++)
        {
            if(childNodeList[i]==targetNode)
            {
                printPath(&childNodeList[i]);
                return 1;
            }
        }
        explored.push_back(currentNode);
        //将childNode加入到frontier中
        for(int i=0;i<childNodeList.size();i++)
        {
            int indexInExplored=searchInVector(frontier,currentNode);
            int indexInFront=searchInVector(explored,currentNode);
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
    return -1;
}
int main()
{
    initInputState();
    int result=aStarSearch();
    if(result==-1)
        cout<<"无解！"<<endl;
    return 0;
}