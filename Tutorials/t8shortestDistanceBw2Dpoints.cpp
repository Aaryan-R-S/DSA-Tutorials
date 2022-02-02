#include<bits/stdc++.h>
using namespace std;

// Time complexity:
// Bruteforce - O(n^2)
// Divide and Conquer - O(n*log(n))

typedef struct {
    double x, y;
}Point;

typedef struct {
    Point p1, p2;
    double delta;
}Pair;

void display(Pair &ans){
    cout<<"("<<ans.p1.x<<","<<ans.p1.y<<")"<<endl;
    cout<<"("<<ans.p2.x<<","<<ans.p2.y<<")"<<endl;
    cout<<"Distance: "<<ans.delta<<endl;
}

double distance(Point &p1, Point &p2){
    return sqrt((pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2)));
}

Pair closestBruteForce(vector<Point> &xsorted){
    Pair ans;
    ans.p1 = {-1,-1};
    ans.p2 = {-1,-1};
    ans.delta = INT_MAX;
    double d;
    for (int i = 0; i < xsorted.size(); i++){
        for (int j = i+1; j < xsorted.size(); j++){
            d = distance(xsorted[i], xsorted[j]);
            if(d<ans.delta){
                ans.p1 = xsorted[i];
                ans.p2 = xsorted[j];
                ans.delta = d;
            }
        }
    }
    return ans;
}

Pair closestPair(vector<Point> &xsorted, vector<Point> &ysorted){
    int n = xsorted.size();
    if(n<=3){
        return closestBruteForce(xsorted);
    }

    double xmidpoint = xsorted[n/2-1].x;
    vector<Point> xsorted_left;
    vector<Point> xsorted_right;
    vector<Point> ysorted_left;
    vector<Point> ysorted_right;

    for (int i = 0; i < n/2; i++){
        xsorted_left.push_back(xsorted[i]);
    }
    for (int i = n/2; i < n; i++){
        xsorted_right.push_back(xsorted[i]);
    }

    for(auto p : ysorted){
        if(p.x<=xmidpoint){
            ysorted_left.push_back(p);
        }
        else{
            ysorted_right.push_back(p);
        }
    }

    Pair l_ans = closestPair(xsorted_left, ysorted_left);
    Pair r_ans = closestPair(xsorted_right, ysorted_right);
    Pair ans = (l_ans.delta <= r_ans.delta ? l_ans : r_ans);

    vector<Point> band;
    for (auto p : ysorted){
        if(p.x > xmidpoint - ans.delta && p.x < xmidpoint + ans.delta){
            band.push_back(p);
        }
    }
    
    double d;
    for (int i = 0; i < band.size(); i++){
        for (int j = i+1; j < min(i+8, (int)band.size()); j++){
            d = distance(band[i], band[j]);
            if(d<ans.delta){
                ans.p1 = band[i];
                ans.p2 = band[j];
                ans.delta = d;
            }
        }
    }
    
    return ans;
}

Pair closest(vector<Point> &points){
    vector<Point> xsorted = points;
    sort(xsorted.begin(), xsorted.end(), [&](Point a, Point b){
        if(a.x!=b.x) return a.x<b.x;
        return a.y<=b.y;
    });
    vector<Point> ysorted = points;
    sort(ysorted.begin(), ysorted.end(), [&](Point a, Point b){
        if(a.y!=b.y) return a.y<b.y;
        return a.x<=b.x;
    });
    return closestPair(xsorted, ysorted);
}

int main(){
    int n; cin>>n;
    double x,y;

    vector<Point> points;
    for (int i = 0; i < n; i++){
        cin>>x>>y;
        points.push_back({x,y});
    }
    
    Pair ans = closest(points);
    display(ans);

    return 0;
}