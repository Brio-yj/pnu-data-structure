#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//#define test
#define cintest

vector<string> split(const string &str, char Delimiter){

    vector<string> tokens;
    string token;

    istringstream tokenStream(str);
    while(getline(tokenStream,token,Delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

vector<int> processor(){
    string line;
    ifstream myfile ("zsignal.txt");

    vector<int> signalList;

    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {

            vector<string> x = split(line,' ');

            for(auto i : x){
                signalList.push_back(stoi(i));
            }
        }
        myfile.close();
    } else cout << "zsignal.txt을 열 수 없네요.";

    return signalList;
}

vector<int> makeResult(vector<int> signalList){

    vector<int> result;
    vector<int>::iterator iter = signalList.begin();
    result.push_back(*iter);
    iter += 1;

    while(iter < signalList.end()){
        if(*iter == 0){
            int x = result.back();
            int N = *(iter+1);
            for(int i=0;i<N;i++){
                result.push_back(x);
            }
            iter += 2;
        }else{
            result.push_back(result.back()+*iter);
            iter += 1;
        }
    }
    return result;
}

void calculation(vector<int> result){

    #ifdef cintest

    char type;
    int a;
    int b;
    int resultSize = result.size();

    while(cin >> type){
        if(type == 'T'){

            cin >> a;

            if(a>resultSize){
                cout << "-1" << endl;
            }else{
                cout << result[a] << endl;
            }

        }else{

            cin >> a;
            cin >> b;

            if(a<0 || b>resultSize){
                cout << "-1" <<endl;
            }else{
                cout << *min_element(result.begin()+a,result.begin()+b+1)<< " " << *max_element(result.begin()+a,result.begin()+b+1) << endl;
            }
        }
    }
    #endif
}

int main(){

    vector<int> signalList = processor();
    vector<int> result = makeResult(signalList);
    calculation(result);

    return 0;
}

