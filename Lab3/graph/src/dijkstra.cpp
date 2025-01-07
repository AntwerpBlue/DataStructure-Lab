#include "../include/dijkstra.h"
#include <iostream>

void dijkstra::ssp(int s){
    //DONE:实现以s为起始点的dijkstra算法求最短路径
    vertex[s]={true,-1,0};
    for(auto it=g.vertex[s].head;it!=NULL;it=it->next){
        vertex[it->adj].dist = it->weight;
        vertex[it->adj].path = s;
    }
    for(int i = 0;i<g.vertex_num;i++){
        int cur = -1;
        for(int j = 0;j<g.vertex_num;j++){
            if(!vertex[j].sure&&(cur==-1||vertex[j].dist<vertex[cur].dist)){
                cur = j;
            }
        }
        if(vertex[cur].dist==10000) break;
        vertex[cur].sure = true;
        for(auto it=g.vertex[cur].head;it!=NULL;it=it->next){
            int node = it->adj;
            if(vertex[cur].dist+it->weight<vertex[node].dist){
                vertex[node].dist = vertex[cur].dist+it->weight;
                vertex[node].path = cur;
            }
        }
    }
}
void dijkstra::print(int u){
    //TODO:用于输出最短路径的辅助函数，可以使用递归实现
    if(!vertex[u].sure){
        std::cout<<"No path to "<<u;
        return;
    }
    if(vertex[u].path!=-1){
        print(vertex[u].path);
        std::cout<<u<<" ";
    }
    else{
        std::cout<<u<<" ";
    }
}