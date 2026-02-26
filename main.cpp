#include<bits/stdc++.h>
using namespace std;

class point{
    int x;
    int y;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<point> hull;
    point p0 = hull[0];
    for(int i=1; i<hull.size(); i++){
        if(hull[i].y < p0.y || hull[i].y == p0.y && hull[i].x < p0.x){
            p0 = hull[i];
        }
    }

    return 0;
}