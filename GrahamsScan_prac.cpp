#include<iostream>
#include<limits>
#include<vector>
#include<algorithm>

using namespace std;

struct Point {
    int x,y;
}

Point bottomLeft;

int distSq(Point p1 ,Point p2){
    return ((p2.x - p1.x)*(p2.x - p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

int orientation(Point p,Point q,Point r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x)*(r.y-q.y);

    if(val == 0){
        return 0;
    }
    return (val > 0) ? 1 : 2;
}

bool compare(Point p1,Point p2){
    int o = orientation(bottomLeft,p1,p2);

    if(o == 0){
        return (distSq(bottomLeft,p2) >= distSq(bottomLeft,p1));
    }
    return (o==2);
}