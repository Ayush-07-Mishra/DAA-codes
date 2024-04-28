#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

struct LineSegment {
    Point p1, p2;
};

bool sortByX(const Point &a, const Point &b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

bool doIntersect(LineSegment s1, LineSegment s2) {
    int o1 = orientation(s1.p1, s1.p2, s2.p1);
    int o2 = orientation(s1.p1, s1.p2, s2.p2);
    int o3 = orientation(s2.p1, s2.p2, s1.p1);
    int o4 = orientation(s2.p1, s2.p2, s1.p2);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(s1.p1, s2.p1, s1.p2)) return true;
    if (o2 == 0 && onSegment(s1.p1, s2.p2, s1.p2)) return true;
    if (o3 == 0 && onSegment(s2.p1, s1.p1, s2.p2)) return true;
    if (o4 == 0 && onSegment(s2.p1, s1.p2, s2.p2)) return true;

    return false;
}

int countIntersections(vector<LineSegment> segments) {
    int count = 0;
    for (size_t i = 0; i < segments.size(); ++i) {
        for (size_t j = i + 1; j < segments.size(); ++j) {
            if (doIntersect(segments[i], segments[j]))
                count++;
        }
    }
    return count;
}

int main() {
    cout << "AYUSH MISHRA 22BCE3940"<<endl;
    int n;
    cout << "Enter the number of line segments: ";
    cin >> n;
    vector<LineSegment> segments(n);
    cout << "Enter the starting and ending points of all line segments:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Segment " << i + 1 << ": ";
        cin >> segments[i].p1.x >> segments[i].p1.y >> segments[i].p2.x >> segments[i].p2.y;
    }

    int intersections = countIntersections(segments);
    cout << "Number of intersections: " << intersections << endl;

    return 0;
}
