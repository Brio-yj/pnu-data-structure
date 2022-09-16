#include <bits/stdc++.h>

using namespace std;

int t = 0;
int N;

vector<int> readCoor(){

    int x,y;
    vector<int> coor;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> x >> y;
        coor.push_back(x);
        coor.push_back(y);
    }
    coor.push_back(coor[0]);
    coor.push_back(coor[1]);

    return coor;
}

vector<int> readRequest(){

    vector<int> request;
    int a,b,c,d,e;

    cin >> a >> b >> c >> d >> e;

    request.push_back(a);
    request.push_back(b);
    request.push_back(c);
    request.push_back(d);
    request.push_back(e);

    return request;
}

vector<int> calTotal(vector<int> & coor){

    int curX = coor[0],curY = coor[1];
    int i = 1;

    vector<int> locationByTime;

    while(i <= N){

        int targetX = coor[2*i],targetY = coor[2*i+1];

        while(1){

            if(curX == targetX && curY == targetY){break;}

            locationByTime.push_back(curX);
            locationByTime.push_back(curY);

            if(curX == targetX){
                    if(curY < targetY){curY += 1;}
                    else{curY -= 1;}
            }
            else if(curY == targetY){
                    if(curX < targetX){curX += 1;}
                    else{curX -= 1;}
            }
            t += 1;
        }
        i += 1;
    }
    return locationByTime;
}

void printResult(vector<int> &locationByTime,vector<int> &request){

    for(int i : request){
        cout << locationByTime[(i%t)*2] << " " << locationByTime[(i%t)*2+1] << endl;
    }
}

int main(){

    vector<int> coor = readCoor();
    vector<int> request = readRequest();
    vector<int> locationByTime = calTotal(coor);
    printResult(locationByTime,request);

    return 0;
}
