#include "walk.h"

namespace DATA_STRUCTURE {

void walk::print_para() {
    std::cout << steps << std::endl;
    for (int i = 0; i < gold_num; i++) {
        std::cout << *(gold + 2 * i) << " " << *(gold + 2 * i + 1) << " " << *(gold_value + i) << std::endl;
    }
}

int walk::compute_distance(int x1, int y1, int x2, int y2) {
    int xdiff=x1>x2?x1-x2:x2-x1;
    int ydiff=y1>y2?y1-y2:y2-y1;
    int step=(xdiff+1)/2+(ydiff+1)/2;
    return step;
}

void walk::buildgraph(){
    auto idx2num=[](int idx,int xy){
        return (idx-1)*2+xy;
    };
    for(int i=1;i<gold_num;i++){
        int dis=compute_distance(0,0,idx2num(i,0),idx2num(i,1));
        distances[0][i]=dis;
        distances[i][0]=dis;
        for(int j=i+1;j<=gold_num;j++){
            int dis=compute_distance(idx2num(i,0),idx2num(i,1),idx2num(j,0),idx2num(j,1));
            distances[i][j]=dis;
            distances[j][i]=dis;
        }
    }
}

int walk::get_subvalue(int begin,bool* visited){
    int max_value=0;
    int cur=-1;
    for(int i=1;i<=gold_num;i++){
        if(!visited[i]&&distances[begin][i]>0){
            int cur_value=get_subvalue(i,visited);
            if(cur_value>max_value){
                cur=i;
                max_value=cur_value;
            }
        }
    }
    if(cur!=-1){
        visited[cur]=true;
    }
    else{
        max_value+=gold_value[cur];
    }
    return max_value;
}

int walk::get_value() {
    bool visited[100]={false};
    int max_value = 0;

    // TODO
    return max_value;
}

}