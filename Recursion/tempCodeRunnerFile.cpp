#include <iostream>
#include <stack>
using namespace std;
class point{
    public:
    int x,y;
    point(){
        x=0,y=0;
    }
    point(int x,int y):x(x),y(y){};
};
//3 steps in recurse
// pre // recurse // post
bool walk(char** maze,char wall, point current_pnt, point end_pnt,bool** seen, stack<point>& path){
    if(current_pnt.x<0||current_pnt.x>sizeof(maze[0])||
    (current_pnt.x<0||current_pnt.x>sizeof(maze[0]))){
        return false;
    }
    if(maze[current_pnt.x][current_pnt.y]==wall){
        return false;
    }
    if(current_pnt.x == end_pnt.x && current_pnt.y==end_pnt.y){
        path.push(current_pnt);
        return true;
    }
    if(seen[current_pnt.x][current_pnt.y]){
        return false;
    }

    seen[current_pnt.x][current_pnt.y]=true;

    if(walk(maze,wall,point(current_pnt.x -1,current_pnt.y),end_pnt,seen,path)||
      walk(maze,wall,point(current_pnt.x +1,current_pnt.y),end_pnt,seen,path)||
      walk(maze,wall,point(current_pnt.x ,current_pnt.y-1),end_pnt,seen,path)||
      walk(maze,wall,point(current_pnt.x,current_pnt.y+1),end_pnt,seen,path)){
        return true;
      }
    return false; 
}
bool mazesolver(char** maze,char wall, point current_pnt, point end_pnt,int rows,int cols){

    bool** seen = new bool*[rows];
    for(int i =0;i<rows;i++){
        seen[i]=new bool[cols];
        for(int j =0;j<cols;j++){
            seen[i][j]=false;
        }
    }

    stack<point> path;

    bool result = walk(maze,wall,current_pnt,end_pnt,seen,path);
    for(int i =0;i<rows;i++){
        delete[] seen[i];
    }
    delete[] seen;

    if(result){
        cout<<"Path found!"<<endl;
        cout<<"Path steps: "<<endl;
        while(!path.empty()){
            point step = path.top();
            cout<<"step ("<<step.x<<", "<<step.y<<")"<<endl;
            path.pop();
        }
    } else{
        cout<<"NO path found. "<<endl;
    }

    return result;
}


int main(){
    char maze[5][5]={
        { 'S', ' ', ' ', 'W', 'E' },
        { 'W', 'W', ' ', ' ', ' ' },
        { 'W', ' ', ' ', 'W', 'W' },
        { ' ', ' ', ' ', ' ', ' ' },
        { 'W', 'W', ' ', 'W', 'W' }
    };
    int rows=5,cols=5;
    char** mazeptr = new char*[rows];

    for(int i =0;i<5;i++){
        mazeptr[i]=new char[cols];
        for(int j=0;j<cols;j++){
            mazeptr[i][j]=maze[i][j];
        }
    };

    point current_pnt(0,0);
    point end_pnt(0,4);
    mazesolver(mazeptr,'W',current_pnt,end_pnt,rows,cols);

    for(int i=0;i<cols;i++){
        delete[] mazeptr[i];
    }
    delete[] mazeptr;

    return 0;

}