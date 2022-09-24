#include <iostream>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;

struct Song{
    string  t;
    char    g;
    int     b,d;
    double  s;

    bool operator > (const Song &S){
        if( (b==S.b) && (d==S.d) ){
            return s<S.s;
        }
        if(b==S.b){
            return d>S.d;
        }
        return b>S.b;
    }
};

bool compare(Song a,Song b){
    return a>b;
}

int main(){
    int n,k;
    cin>>n>>k;
    Song *ps = new Song[n+1];
    for(int i=0; i<n; i++){
        cin>>ps[i].t>>ps[i].g>>ps[i].b>>ps[i].s>>ps[i].d;
    }
/*

    for(int i=0; i<n; i++){
        cout<<"\t t= "<<setw(5)<<ps[i].t
            <<"\t g= "<<setw(5)<<ps[i].g
            <<"\t b= "<<setw(5)<<ps[i].b
            <<"\t s= "<<setw(5)<<ps[i].s
            <<"\t d= "<<setw(5)<<ps[i].d
            <<endl;
    }
    cout<<"\n after sort() \n ";

*/
    sort(ps, ps+n,compare);
/*
    for(int i=0; i<n; i++){
        cout<<"\t t= "<<setw(5)<<ps[i].t
            <<"\t g= "<<setw(5)<<ps[i].g
            <<"\t b= "<<setw(5)<<ps[i].b
            <<"\t s= "<<setw(5)<<ps[i].s
            <<"\t d= "<<setw(5)<<ps[i].d
            <<endl;
    }
*/
    for(int i=0; i<n-1; i++){
        int a,j;
        for(j=0; j+i<n; j++){
            if(ps[i].g==ps[i+j].g)a=0;
            else {
            a=1;
            break;
            }
        }
        if(a==0) break;
        else if(a==1){
            if(ps[i].g==ps[i+1].g){
                ps[n]=ps[i+j];
                for(int k=0;(j-k)>1;k++)
                    ps[i+j-k]=ps[i+j-(k+1)];
                ps[i+1]=ps[n];
            }
            else continue;
        }
    }
  /*
    cout<<"\n after second sort() \n ";
    for(int i=0; i<n; i++){
        cout<<"\t t= "<<setw(5)<<ps[i].t
            <<"\t g= "<<setw(5)<<ps[i].g
            <<"\t b= "<<setw(5)<<ps[i].b
            <<"\t s= "<<setw(5)<<ps[i].s
            <<"\t d= "<<setw(5)<<ps[i].d
            <<endl;
    }
*/
    cout<<ps[k-1].t;
    delete[]ps;
}









