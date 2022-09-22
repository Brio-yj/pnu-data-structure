#include <iostream>
#include <vector>
using namespace std;
void rob(int num, int type, int time,int cnt,double &x1,
         double &y1,double &x2, double &y2, vector <double> v1, vector <double> v2 ){
    int half=v1.size()/2, cnthalf=cnt/2, allsize=v1.size();
    time=time*2;
    if(time>cnt/2){
        int i=0;
        while(1){
            if( (cnthalf + half*i < time) && (time <=cnthalf + half*(i+1) ) )
                break;
            else i++;
        }
        if( i % 2==0 )
            type =2;
        else if( i % 2==1 )
            type =3;
        time=time-(cnthalf + half*i);
    }
    if(num==1){
    x1=v1[time];
    y1=v2[time];
        switch(type){
            case 2 :{
                x1=v1[cnthalf-time];
                y1=v2[cnthalf-time];
                if(cnthalf-time<0){
                    x1=v1[allsize+cnthalf-time-2];
                    y1=v2[allsize+cnthalf-time];
                }
            break;
            }
            case 3 :{
                x1=v1[cnthalf+half+time];
                y1=v2[cnthalf+half+time];
                if(cnthalf+half+time>allsize){
                    x1=v1[time+cnthalf-half];
                    y1=v2[time+cnthalf-half];
                }
            break;
            }
        break;
        }
    }
    if(num==2){
        x2=v1[cnt-time];
        y2=v2[cnt-time];
        switch(type){
            case 2 :{
                x2=v1[cnthalf+time];
                y2=v2[cnthalf+time];
            break;
            }
            case 3 :{
                x2=v1[ cnthalf+ half - time];
                y2=v2[ cnthalf+ half - time];
            break;
            }
        break;
        }
    }
}

int main()
{
    int a,val,sub,n;
    double x1=0,y1=0,x2=0,y2=0;
    cin>>n;
    int point[2*n+2];
    for(int i=0; i<2*n; i++){
        cin>>a;
        point[i]=a;
    }
    point[2*n]=point[0];
    point[2*n+1]=point[1];
    vector <double> v1,v2;
    v1.push_back(point[0]);
    v2.push_back(point[1]);
    for(int i=0; i<n; i++){
        int xlow  =point[2*i],
            xhigh =point[2*(i+1)],
            ylow  =point[2*i+1],
            yhigh =point[2*(i+1)+1];
            if(xlow==xhigh){
            val = abs(yhigh-ylow);
            sub = yhigh-ylow;
            for(double j=0.5; j<val+0.5; j+=0.5){
                if(sub>0){
                    v1.push_back(xlow);
                    v2.push_back(ylow+j);
                }
                else if(sub<0){
                    v1.push_back(xlow);
                    v2.push_back(ylow-j);
                }
            }
        }
        else if(ylow==yhigh){
            val = abs(xhigh-xlow);
            sub = xhigh-xlow;
            for(double j=0.5; j<val+0.5; j+=0.5){
                if(sub>0){
                    v1.push_back(xlow+j);
                    v2.push_back(ylow);
                }
                else if(sub<0){
                    v1.push_back(xlow-j);
                    v2.push_back(ylow);
                }
            }
        }
    }
    int type=0,cnt=0;
    double time=0;
    while(1){
        if( (v1[cnt]==point[n-2]) && (v2[cnt]==point[n-1]) )
            break;
        else cnt++;
    }
    cin>>time;
    rob(1,type,time,cnt,x1,y1,x2,y2,v1,v2);
    cout<<x1<<" "<<y1<<endl;
    rob(2,type,time,cnt,x1,y1,x2,y2,v1,v2);
    cout<<x2<<" "<<y2<<endl;
}





