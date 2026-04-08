#include <bits/stdc++.h>
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

using namespace std;
using vi = vector<int>;

class Robot {
public:
    int x=0,y=0,x_dir=1,y_dir=0;
    int w,h;
    Robot(int width, int height) {
        x=0;
        y=0;
        w=width-1;
        h=height-1;
    }
    
    bool valid(int x , int y){
        if(x<0 || y<0 || x>w || y>h){
            return false;
        }
        return true;
    }

    void step(int num) {
        //robot is moving in a cycle , ignore every cycle that it makes , only see after , like a monopoly board
        int cycle = 2 * (w + h);
        num %= cycle;
        if(num == 0) num = cycle;

        while(num){
            int nx=x+x_dir;
            int ny=y+y_dir;
            if(!valid(nx,ny)){
                int temp = x_dir;
                x_dir = -y_dir;
                y_dir = temp;
                nx=x+x_dir;
                ny=y+y_dir;
            }
            x=nx;
            y=ny;
            num--;
        }
    }
    
    vector<int> getPos() {
        return{x,y};
    }
    
    string getDir() {
        if(x_dir==1){
            return "East";
        }
        else if(x_dir==-1){
            return "West";
        }
        if(y_dir==1){
            return "North";
        }
        else if(y_dir==-1){
            return "South";
        }
        return "";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */