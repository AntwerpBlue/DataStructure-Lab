#include "../include/dijkstra.h"
#include <iostream>
int main()
{
    
    int n = 6;
    int m = 8;
    int s = 0;
    int u[M] = {0,0,0,1,2,3,4,4};
    int v[M] = {2,4,5,2,3,5,5,3};
    int w[M] = {10,30,100,5,50,10,60,20};
    //std::cin>>n>>m>>s;
    //for(int i=0;i<m;i++)
        //std::cin>>u[i]>>v[i]>>w[i];

    std::cout << "--------------------------" << std::endl;
    std::cout << "travelsal" << std::endl;
    std::cout << "--------------------------" << std::endl;
    graph g(n, m);
    g.init(u, v, w);
    g.dfs(s);
    std::cout << std::endl << std::endl;

    dijkstra dij(g);
    std::cout <<"--------------------------" << std::endl;
    std::cout << "dijkstra" << std::endl;
    std::cout << "--------------------------" << std::endl;
    dij.ssp(s);
    dij.print(1);std::cout<<std::endl;
    dij.print(2);std::cout<<std::endl;
    dij.print(3);std::cout<<std::endl;
    dij.print(4);std::cout<<std::endl;
    dij.print(5);std::cout<<std::endl;
    return 0;
}