#include <bits/stdc++.h>
#define terms 2001
using namespace std;

typedef vector<pair<int,int>> pair_vec;
typedef vector<pair_vec> vec_vec;
typedef pair<int,int> int_pair;
typedef array<int, terms> arr;

arr result;

void make_data(vec_vec &data, int N){
    int num;
    while(N--){
        cin>>num;
        pair_vec each_poly(num);
        for(auto& w: each_poly){
            cin>>w.first>>w.second;
        }
        data.push_back(each_poly);
    }
}

pair_vec multi_poly(const pair_vec& p1, const pair_vec& p2){
    pair_vec result;
    for(auto &w: p1){
        for(auto &v: p2){
            result.push_back(make_pair(w.first*v.first, w.second+v.second));
        }
    }
    return result;
}

pair_vec all_mul_poly(const vec_vec& data){
    pair_vec Mul = data[0];

    for (auto w = data.begin()+1; w != data.end(); w++){
        Mul = multi_poly(Mul,*w);
    }
    return Mul;
}

void all_add(arr& result, const pair_vec& Mul){
    for (auto& w:Mul){
        result[w.second] += w.first;
    }
}

void print_terms(const arr& result){
    int E = terms - 1;

    auto no_z = [](int x) {return  x != 0;};
    int number = count_if(result.begin(), result.end(), no_z);
    cout<<number<<endl;

    for(auto i = result.rbegin(); i != result.rend(); i++){
        if (*i != 0){
            cout<<*i<<" "<<E<<endl;
        }
        E--;
    }
}

int main()
{
    int N;
    cin>>N;
    vec_vec data;
    make_data(data,N);
    pair_vec Mul = all_mul_poly(data);


    all_add(result, Mul);
    print_terms(result);



    return 0;
}
