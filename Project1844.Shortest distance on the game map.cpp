#include<vector>
using namespace std;
void SetNextTargets(const vector<vector<int> > &maps, const int &idx, vector<int> &next){
    int step = maps[0].size();
    int x = idx%step;
    int y = idx/step;
    if(x != 0) if(maps[y][x-1]) next.push_back(y*step + x-1); 
    if(x != step-1) if(maps[y][x+1]) next.push_back(y*step + x+1);
    if(y !=0) if(maps[y-1][x]) next.push_back((y-1)*step + x); 
    if(y != maps.size()-1) if(maps[y+1][x]) next.push_back((y+1)*step + x); 
}
int solution(vector<vector<int> > maps)
{
    int refDistance = 1;
    vector<int> distance(maps.size()*maps[0].size(),-1);
    vector<int> paths(1,0);
    while(!paths.empty()){
        vector<int> nextTargets;
        for(auto&path : paths){
            if(distance[path] != -1) continue;
            distance[path] = refDistance;
            SetNextTargets(maps, path, nextTargets);
        }
        paths = nextTargets;
        refDistance++;
    }
    return distance.back();
}