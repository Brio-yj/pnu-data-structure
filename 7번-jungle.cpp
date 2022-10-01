#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Point{
    int x,y;

    bool operator > (const Point &P){
    if(x==P.x) return y<P.y;
    return x<P.x;
    }
};
bool compare(Point a,Point b){
    return a>b;
}

int main()
{
    int n,a,b,inputy=1;
    cin>>n;
    Point point;
    vector<Point> pv;
    vector<int> inputv;
    while(cin>>a>>b){
        inputv.push_back(a);
        inputv.push_back(b);
    }
    for(int i=0;i<inputv.size();i++){
        if( (inputv[0]==0) && (i==0) ) {
                inputy+=inputv[1];
                i++;
                continue;
        }
        else{
            if( (inputv[i]==0) && (inputv[i+1]!=0) ){
                inputy++;
            }
            else if( (inputv[i]==0) && (inputv[i+1]==0) ){
                inputy+=inputv[i+2]+1;
                i+=2;
                continue;
            }
            else{
                point.x=inputv[i];
                point.y=inputy;
                pv.push_back(point);
            }
        }
    }
    sort(pv.begin(),pv.end(),compare);
    cout<<n<<endl;
    int inputx=1;
    for(int i=0;i<pv.size();i++){
        int sub=pv[i].x-(inputx+1);
        if( (pv[0].x!=1) && (i==0)  ){
            cout<<"0 "<<pv[0].x-1<<"\n"<<pv[0].y<<" ";
            inputx = pv[0].x;
            continue;
        }
        if( pv[i].x==inputx ){
            cout<<pv[i].y<<" ";
            continue;
        }
        if( (pv[i].x!=inputx) && (sub!=0) ){
            cout<<"0"<<endl<<"0 "<<sub<<endl<<pv[i].y<<" ";
            inputx +=sub+1;
            continue;
        }
        if( (pv[i].x!=inputx) && (sub==0) ){
            cout<<"0"<<endl<<pv[i].y<<" ";
            inputx++;
            continue;
        }
    }
    cout<<"0";
    if(inputx!=n){
        cout<<endl<<"0 "<<n-inputx;
    }
}
