#include "../include/graph.h"
#include<iostream>

void graph::init(int u[],int v[],int w[]){
    //DONE:完成邻接表存储图
    for(int i=0;i<edge_num;i++){
        auto adj=vertex[u[i]].head;
        if(adj==NULL){
            vertex[u[i]].head=new Edge(v[i],w[i]);
        }
        else{
            while(adj->next!=NULL){
                adj=adj->next;
            }
            adj->next=new Edge(v[i],w[i]);
        }
    }
}
void graph::dfs(int s){
    //DONE:完成图的深度优先遍历，输出顶点编号
    if(!vertex[s].visited){
        vertex[s].visited=true;
        std::cout<<s<<" ";
        auto adjedge=vertex[s].head;
        while(adjedge!=NULL){
            dfs(adjedge->adj);
            adjedge=adjedge->next;
        }
    }
}