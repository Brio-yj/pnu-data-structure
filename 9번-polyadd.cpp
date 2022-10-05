#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Point{
    int x,y;
    bool operator > (const Point &P){
        if(y==P.y) {
            return x>P.x;
        }
        return y>P.y;
    }
};
bool compare(Point a, Point b){
    return a>b;
}
int main()
{
    int k;
    cin>>k;
    vector<Point> pv;
    Point point;
    for(int i=0;i<k;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>point.x>>point.y;
            pv.push_back(point);
        }
    }

    for(int i=0;i<pv.size();i++)
        cout<<pv[i].x<<"\t"<<pv[i].y<<"\n";

    sort(pv.begin(), pv.end(), compare);

    cout<<" after sorting"<<"\n";

    for(int i=0;i<pv.size();i++)
        cout<<pv[i].x<<"\t"<<pv[i].y<<"\n";

    cout<<" solution"<<"\n";

    for(int i=0;i<pv.size()-1;i++){
        if(pv[i].y==pv[i+1].y){
            pv[i].x+=pv[i+1].x;
            pv.erase(pv.begin() + (i+1) );
            if(pv[i].x==0){
                pv.erase(pv.begin() + i );
            }
        i--;
        }
        else if( (pv[i].y!=pv[i+1].y) && (pv[i].x==0) ){
            pv.erase(pv.begin() + i);
        }
        if(pv.size()==0){
            cout<<"0"<<" "<<"0";
            break;
        }
        else if(i==pv.size()-2){
            cout<<pv.size()<<"\n";
            for(int i=0;i<pv.size();i++){
                if(pv[i].x==0) continue;
                else cout<<pv[i].x<<"\t"<<pv[i].y<<"\n";
            }
        }
    }

}
