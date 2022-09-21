#include <bits/stdc++.h>


using namespace std;

struct point{
    double x= 0,y = 0;
    bool operator==(point other)const{
        if((x == other.x)&&(y == other.y)) return true;
        else return false;
    }

    point operator+=(point &other){
        x+=other.x;
        y+=other.y;
        return *this;
    }

    point operator-=(point &other){
        x-=other.x;
        y-=other.y;
        return *this;
    }

    point operator/(const int a){
        x/=a;
        y/=a;
        return *this;
    }

    double add_x_y(){
        return x+y;
    }
};

class robot{
    int position;
    vector<point> surround{};
    int clock_wise;
public:
    robot(int start, vector<point> &full, int clock_wise):position(start),clock_wise(clock_wise){
        surround = full;}

    void print_posi(){
        cout<<(surround.begin()+position)->x<<" "<<(surround.begin()+position)->y<<endl;
    }

    void Go(){
        if (clock_wise>0) position++;
        else              position--;

        if (position < 0) position = surround.size()-1;
        else if (position > surround.size()-1) position = 0;
        else return;
    }

    void change_cl(robot &other_r){
        clock_wise = -clock_wise;
        other_r.clock_wise = -other_r.clock_wise;
    }

    bool operator==(robot &other_r)const{
        if(position == other_r.position) return true;
        else return false;
    }

};

void input_points(vector<point> &points){
    for(auto &w:points) {
        cin>>w.x>>w.y;
    }
    points.emplace_back(*points.begin());
}//end of initiate point vector

void make_full(vector<point> &point_vec,vector<point> &full) {
    int N;
    struct point app;
    for (auto w = point_vec.begin() + 1; w != point_vec.end(); w++) {
        app.x = (w - 1)->x;
        app.y = (w - 1)->y;
        full.emplace_back(app);
        struct point inst;
        inst.x = w->x;
        inst.y = w->y;
        inst-=app;
        N = inst.add_x_y();
        inst/abs(N*2);
        for(int i = 1;i<abs(N*2);i++){
            full.emplace_back(app+=inst);
        }
    }
}



int main() {

    int the_number_of_points;
    cin>>the_number_of_points;

    vector<point> points_vector(the_number_of_points);
    input_points(points_vector);
    vector<point> full{};
    make_full(points_vector,full);
    int c2p = find(full.begin(),full.end(),*(points_vector.begin()+the_number_of_points/2-1)) - full.begin();


    robot r1(0,full,1);
    robot r2(c2p,full,-1);


    int time;
    cin>>time;

    for(int i = 0; i < time*2;i++){
        if (r1==r2){
            r1.change_cl(r2);
        }
        r1.Go();
        r2.Go();
    }

    r1.print_posi();
    r2.print_posi();


    return 0;
} //end of main
