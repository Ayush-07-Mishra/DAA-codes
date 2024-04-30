#include<iostream>
#include<limits>
#include<algorithm>
#include<vector>

struct point{
    int x,y;
}
    
struct LineSegment{
    point p1,p2;
}

int orientation(point p,point q,point r){
    int val = (r.x-q.x) * (q.y-p.y) - (r.y-q.y) * (q.x-p.x);
    if(val == 0){
        return 0;
    }
    return (val > 0) ? 1 : 2;
}

bool onSegment(point p,point q,point r){
    if(q.x <= max(p.x,r.x) && q.x >= min(p.x,r.x) && q.y <= max(p.x,r.x) && q.y >= max(p.x,r.x)){
        return true;
    }

    return false;
}

bool doIntersect(LineSegment s1,LineSegment s2){
    int o1 = orientation(s1.p1,s1.p2,s2.p1);
    int o2 = orientation(s1.p1,s1.p2,s2.p2);
    int o3 = orientation(s2.p1,s2.p2,s1.p1);
    int o4 = orientation(s2.p1,s2.p2,s1.p2);

    if(o1 != o2 && o3 != o4){
        return true;
    }

    if (o1 == 0 && onSegment(s1.p1, s2.p1, s1.p2)) return true;
    if (o2 == 0 && onSegment(s1.p1, s2.p2, s1.p2)) return true;
    if (o3 == 0 && onSegment(s2.p1, s1.p1, s2.p2)) return true;
    if (o4 == 0 && onSegment(s2.p1, s1.p2, s2.p2)) return true;

    return false;
}

int countIntersections(vector<LineSegment>segments){
    int count = 0;
    for(int i =0;i<segments.size();i++){
        for(int j =i+1;j<segments.size();j++){
            if(doIntersect(segments[i],segments[j])){
                count ++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<LineSegment> segments(n);
    for(int i =0;i<n;i++){
        cout<<"Segment" << i + 1 << ": ";
        cin >> segments[i].p1.x >> segments[i].p1.y >> segments.p2.x >> segments.p2.y;
    }

    int intersections = countIntersections(segments);
    cout << intersections <<endl;
}