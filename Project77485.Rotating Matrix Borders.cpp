#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAT vector<vector<int>>
int RotateRect(MAT& mat, vector<int> &query){
    int y1 = query[0]-1;
    int x1 = query[1]-1;
    int y2 = query[2]-1;
    int x2 = query[3]-1;
    int x = x1; 
    int y = y1;
    int last = mat[y+1][x];
    int temp;
    int minVal = mat[y][x];
    do{
        if(x<x1 || x>x2) return -1;
        if(y<y1 || y>y2) return -1;
        temp = mat[y][x];
        minVal = temp < minVal ? temp : minVal; 
        mat[y][x] = last;
        last = temp;
        if(y==y1){
            if(x == x2){y++;}
            else{x++;}
            continue;
        }
        else if(y==y2){
            if(x == x1){y--;}
            else{x--;}
            continue;
        }
        else{
            if(x==x2){y++;}
            else{y--;}
            continue;
        }
    }while(!(x==x1 && y== y1));
    return minVal;
}
vector<int> solution(int rows, int columns, MAT queries) {
    vector<int> answer;
    MAT mat(rows,vector<int>(columns));
    for(int i=0; i < rows*columns; i++){mat[i/columns][i%columns] = i+1;}
    for(auto &q : queries) answer.push_back(RotateRect(mat, q));
    return answer;
}