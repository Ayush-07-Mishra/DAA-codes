#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Point {
    int x, y;
};

Point bottomLeft;

int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}
int orientation(Point p, Point q, Point r) {
    int val = 
(q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}
bool compare(Point p1, Point p2) {
    int o = orientation(bottomLeft, p1, p2);
    if (o == 0) {
        return (distSq(bottomLeft, p2) >= distSq(bottomLeft, p1));
    }
    return (o == 2); 
}

vector<Point> convexHull(vector<Point>& points) {
    vector<Point> convexHullPoints;

    int minIdx = 0;
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i].y < points[minIdx].y || (points[i].y == points[minIdx].y && points[i].x < points[minIdx].x))
            minIdx = i;
    }
    bottomLeft = points[minIdx];

    sort(points.begin(), points.end(), compare);

    stack<Point> stk;
    stk.push(points[0]);
    stk.push(points[1]);

    for (size_t i = 2; i < points.size(); i++) {
        while (stk.size() > 1) {
            Point top = stk.top();
            stk.pop();
            Point nextTop = stk.top();

            if (orientation(nextTop, top, points[i]) == 2) {
                stk.push(top);
                break;
            }
        }
        stk.push(points[i]);
    }
    while (!stk.empty()) {
        convexHullPoints.push_back(stk.top());
        stk.pop();
    }
    return convexHullPoints;
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Enter the coordinates of each point:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Point " << i + 1 << ": ";
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> convexHullPoints = convexHull(points);

    cout << "Points forming the convex hull:\n";
    for (size_t i = 0; i < convexHullPoints.size(); ++i) {
        cout << "(" << convexHullPoints[i].x << ", " << convexHullPoints[i].y << ")\n";
    }
    return 0;
}
