#include <bits/stdc++.h>

#define try_times 5
#define input_vector(X) for(auto &w:X) cin>>w;

using namespace std;


void input_points(vector<pair<int,int>> &points){
    for(auto &w:points) {
        cin>>w.first>>w.second;
    }
    points.emplace_back(*points.begin());
}//end of initiate point vector


int calculate_difference(vector<pair<int,int>> &point_vec,vector<int> &dep) {
    auto v_iter = dep.begin();

    for (auto w = point_vec.begin()+1; w != point_vec.end(); w++) {
        if (w->first == (w-1)->first)   *v_iter = w->second - (w-1)->second;
        else                            *v_iter = w->first  - (w-1)->first;

        v_iter++;
    }
    return accumulate(dep.begin(),dep.end(),0,[](int x,int y){return x+abs(y);});
} //end of calculate difference

pair<int,int> find_position_step(vector<int> point_vec,int x) {
    int position = 0;
    for(auto w:point_vec) {
        w = abs(w);
        if (x>w) {
            x-=w;
            position++;
        } else break;
    }
    auto v_iter = point_vec.begin()+position;
    x*=(*v_iter)/abs(*v_iter);
    return {position,x};
}//end of find position

pair<int,int> direction(vector<pair<int,int>> &pv,int pos,int step) {
    auto pv_iter = pv.begin()+pos;
    if (pv_iter->first == (pv_iter+1)->first)   return {pv_iter->first,        pv_iter->second + step};
    else                                        return {pv_iter->first + step, pv_iter->second       };
}//end of direction

void print_result(vector<pair<int,int>> &point_vec, vector<int> &time, vector<int> &dep, int length) {
    for(auto w:time) {
        w=w%length;
        pair<int,int> pos_and_step = find_position_step(dep,w);
        pair<int,int> result = direction(point_vec, pos_and_step.first,pos_and_step.second);

        cout<<result.first<<" "<<result.second<<endl;
    }
}//end of print result


int main() {
    int the_number_of_points;
    cin>>the_number_of_points;

    vector<pair<int,int>> points_vector(the_number_of_points);
    input_points(points_vector);

    vector<int> difference_each_point(the_number_of_points);
    int line_length = calculate_difference(points_vector,difference_each_point);

    vector<int> time(try_times);
    input_vector(time);

    print_result(points_vector,time,difference_each_point,line_length);

    return 0;
} //end of main
