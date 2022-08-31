#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define Mat vector<vector<int>>
void Search(Mat &img, Mat &label, int l, int &g, int y, int x){
    if(x == -1 || x == img[0].size()) return;
    else if(y == -1 || y == img.size()) return;
    else if(label[y][x] != 0) return;
    else if(img[y][x] != g) return;
    label[y][x] = l;
    Search(img, label, l, g, y-1, x-0);
    Search(img, label, l, g, y+1, x+0);
    Search(img, label, l, g, y-0, x-1);
    Search(img, label, l, g, y+0, x+1);
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int rows = picture.size();
    int cols = picture[0].size();
    vector<vector<int>> imgLabeled(rows,vector<int>(cols,0));
    int l=1;
    for(int j=0; j<rows; j++){
        for(int i=0; i <cols; i++){
            if(imgLabeled[j][i]) continue;
            if(picture[j][i] == 0) continue;
            Search(picture, imgLabeled, l++, picture[j][i], j, i);
        }
    }
    vector<int> counter(l-1);
    for(auto&s : imgLabeled) for(auto&c : s) if(c) counter[c-1]++;
    return vector<int>({l-1,*max_element(counter.begin(),counter.end())});
}