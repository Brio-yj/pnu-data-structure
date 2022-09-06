#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int calLineXi(int xLine[],int i){
    int xi=0;if(i==0){
        return xi;
    }
    for(int j=0;j<i;j++){
        xi=xi+xLine[j];
    }return xi;
}
int calLineYi(int yLine[],int YLine,int i){
    int yi=YLine;if(i==0){
        return yi;
    }
    for(int j=0;j<i;j++)
        yi=yi-yLine[j];
    return yi;
}
void output(int queryCnt,int lineCnt,int XLine,int x[],int xLine[],int YLine,int y[],int yLine[]){
    for(int i=0;i<queryCnt/2;i++){
        for(int j=0;j<lineCnt/2;j++){
            if(XLine<x[i]){
                cout<<"out"<<endl;
                break;
            }
            else if( (calLineXi(xLine,j)<x[i]) && (x[i]<calLineXi(xLine,j+1))){
                if((0<y[i]) && (y[i]<calLineYi(yLine,YLine,j))){
                    cout<<"in"<<endl;
                    break;
                }
                else if(y[i]==calLineYi(yLine,YLine,j)){
                    cout<<"on"<<endl;
                    break;
                }
                else if(calLineYi(yLine,YLine,j)<y[i]){
                    cout<<"out"<<endl;
                    break;
                }
            }
            else if(x[i]==calLineXi(xLine,j+1)){
                if((0<y[i]) && (y[i]<calLineYi(yLine,YLine,j+1))){
                    cout<<"in"<<endl;
                    break;
                }
                else if((calLineYi(yLine,YLine,j+1)<=y[i]) && (y[i]<=calLineYi(yLine,YLine,j))){
                    cout<<"on"<<endl;
                    break;
                }
                else if(calLineYi(yLine,YLine,j)<y[i]){
                    cout<<"out"<<endl;
                    break;
                }
            }
        }
    }
}

int main(){


    int linearray[41];
    int linecnt=0;
    int line;
    while(1){
        cin>>line;
        if(line==0){
            break;
        }
        linearray[linecnt]=line;
        linecnt++;
    }
    /*
    for(int i=0;i<linecnt;i++){
        cout<<linearray[i]<<"\t";
    }
    cout<<endl<<linecnt;
    */

    int xpoint, ypoint;
	int queryarray[30];
	int querycnt=0;
	while (cin >> xpoint >> ypoint) {
        queryarray[querycnt]=xpoint;
        querycnt++;
        queryarray[querycnt]=ypoint;
        querycnt++;

	}
	/*
	for(int i=0;i<querycnt;i++){
        cout<<queryarray[i]<<"\t";
	}
    */

    int xLine[linecnt/2];
    int yLine[linecnt/2];
    for(int i=0; i<linecnt/2;i++){
        xLine[i]=linearray[2*i];
        yLine[i]=linearray[1+2*i];
    }
    int XLine=0;
    for(int i=0;i<linecnt/2;i++){
        XLine+=xLine[i];
    }
    int YLine=0;
    for(int i=0;i<linecnt/2;i++){
        YLine+=yLine[i];
    }


    int x[querycnt/2];
    int y[querycnt/2];
    for(int i=0; i<querycnt/2;i++){
        x[i]=queryarray[2*i];
        y[i]=queryarray[1+2*i];
    }
    output(querycnt,linecnt,XLine,x,xLine,YLine,y,yLine);





}
