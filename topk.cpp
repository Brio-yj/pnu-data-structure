#include <bits/stdc++.h>

using namespace std;

int N,k;

struct type{

    string T;
    char G;
    int B;
    double S;
    int D;

};

void processor(vector<type> &v){

        type in;
        cin >> N >> k;

        for(int i = 0;i < N;i++){
            cin >> in.T >> in.G >> in.B >> in.S >> in.D;
            v.push_back(in);
        }

}

bool compare(const type &a,const type &b){

    bool swap = false;
    if(a.B > b.B) swap = true;
    if(a.B == b.B && a.D > b.D) swap = true;
    if(a.B == b.B && a.D == b.D && a.S < b.S) swap = true;

    return swap;
}

void calcul(vector<type> &v){

    vector<type> newv;

    for(auto i = v.begin();i<v.end()-1;i++){

        newv.push_back(*i);
        if((*i).G == (*(i+1)).G){
            auto j = i+1;
            while((*j).G == (*i).G){
                j += 1;
            }
            newv.push_back(*j);
            v.erase(j);
        }
    }
    newv.push_back(v.back());

    cout <<newv[k-1].T;

}

int main(){

    vector<type> v;
    processor(v);
    stable_sort(v.begin(),v.end(),compare);
    calcul(v);

}
