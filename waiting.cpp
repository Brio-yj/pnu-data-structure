#include <bits/stdc++.h>
#define StartTime 30

using namespace std;

struct customer{
    int arrive,
        ID,
        ctime;
};

struct compare{
    bool operator() (customer &A, customer &B) {
        if (A.ctime == B.ctime) return A.ID    > B.ID;
        else                    return A.ctime < B.ctime;
    }
};

int Time = StartTime;
deque<customer> enterence;
priority_queue<customer, deque<customer>, compare> waitingroom;
vector<int> out;

void input(){
    int N;
    cin>>N;
    while(N--){
        customer person;
        cin>>person.arrive>>person.ID>>person.ctime;
        enterence.push_back(person);
    }
}

void entertheroom(){
    while(true){
        if (enterence.empty())             break;
        if (enterence.front().arrive>Time) break;

        waitingroom.push(enterence.front());
        enterence.pop_front();
    }
}

void counseling(){

    while(!waitingroom.empty()) {
        customer p;
        p = waitingroom.top();
        waitingroom.pop();
        int counselingtime = p.ctime / 2;

        if (p.ctime <= 10) {
            Time += p.ctime;
            out.push_back(p.ID);
        } else {
            Time += counselingtime;
            p.ctime -= counselingtime;
            waitingroom.push(p);
        }
        entertheroom();
    }
}

int main() {
    input();
    entertheroom();
    while(!enterence.empty()){


        if (waitingroom.empty()) {
            Time = enterence.front().arrive;
            entertheroom();
        }

        counseling();
    }

    for(auto &w:out){
        cout<<w<<endl;
    }
    return 0;
}
