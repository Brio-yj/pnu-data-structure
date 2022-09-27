#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a,n,val,sub;
    cin>>n;
    int point[2*n+2];
    for(int i=0; i<2*n; i++){
        cin>>a;
        point[i]=a;
    }
    point[2*n]=point[0];
    point[2*n+1]=point[1];
    vector <double> v1,v2;
    for(int i=0; i<n; i++){
        int xlow  =point[2*i],
            xhigh =point[2*(i+1)],
            ylow  =point[2*i+1],
            yhigh =point[2*(i+1)+1];
            if(xlow==xhigh){
            val = abs(yhigh-ylow);
            sub = yhigh-ylow;
            for(double j=0; j<val; j+=0.5){
                if(sub>0){
                    v1.push_back(xlow);
                    v2.push_back(ylow+j);
                }
                else {
                    v1.push_back(xlow);
                    v2.push_back(ylow-j);
                }
            }
        }
        else if(ylow==yhigh){
            val = abs(xhigh-xlow);
            sub = xhigh-xlow;
            for(double j=0; j<val; j+=0.5){
                if(sub>0){
                    v1.push_back(xlow+j);
                    v2.push_back(ylow);
                }
                else {
                    v1.push_back(xlow-j);
                    v2.push_back(ylow);
                }
            }
        }
    }

    int cnt=0;
    while(1){
        if( (v1[cnt]==point[n-2]) && (v2[cnt]==point[n-1]) )
            break;
        else cnt++;
    }

    int half=v1.size()/2, cnthalf=cnt/2, allsize=v1.size(),
        time, tt, quotient, remainder;
    cin>>time;
    time=time*2;
    tt=time - cnt/2 ;
    quotient=tt/half;
    remainder=tt%half;

    if(time<=cnthalf){
        cout<<v1[time]<<" "<<v2[time]<<
        endl<<v1[cnt-time]<<" "<<v2[cnt-time];
    }
    else{
        if(quotient%2 == 0){
            if(cnthalf-remainder<0){
                cout<<v1[allsize+cnthalf-remainder]<<" "<<v2[allsize+cnthalf-remainder]<<
                endl<<v1[cnthalf+remainder]<<" "<<v2[cnthalf+remainder];
            }
            else{
                cout<<v1[cnthalf-remainder]<<" "<<v2[cnthalf-remainder]<<
                endl<<v1[cnthalf+remainder]<<" "<<v2[cnthalf+remainder];
            }
        }
        else if(quotient%2 == 1){
            if(cnthalf+half+remainder>allsize){
                cout<<v1[remainder+cnthalf-half]<<" "<<v2[remainder+cnthalf-half]<<
                endl<<v1[cnthalf+half-remainder]<<" "<<v2[cnthalf+half-remainder];
            }
            else{
                cout<<v1[cnthalf+half+remainder]<<" "<<v2[cnthalf+half+remainder]<<
                endl<<v1[cnthalf+half-remainder]<<" "<<v2[cnthalf+half-remainder];
            }

        }
    }
}




