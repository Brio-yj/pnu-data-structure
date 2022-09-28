#include <bits/stdc++.h>
#define Title 0
#define Genre 1
#define Filesize 4

using namespace std;

typedef tuple <string, char, int, int, double> song;

bool compare(const song& a, const song& b) {
    song r1, r2 ;
    r1 = a ;
    r2 = b ;
    get<Title>(r1) = get<Title>(r2);
    get<Genre>(r1) = get<Genre>(r2);
    swap( get<Filesize>(r1), get<Filesize>(r2) ) ;

    return ( r1 > r2 );
}//end of compare


void input_songs(vector<song> &is, int N){
    string T;
    char G;
    int B, D;
    double F;


    for (int i = 0; i < N; i++){
        cin>>T>>G>>B>>F>>D;
        is.push_back( make_tuple(T, G, B, D, F));
    }

}//end of input songs



void final_sorting(vector<song> &pre, vector<string> &after, int N){
    char pre_genre = 'X';
    auto noeq = [&] (song x) {return pre_genre != get<Genre>(x);};

    while(after.size() != N) {

        auto diff_g = find_if(pre.begin(), pre.end(), noeq);

        if (diff_g != pre.end()){
            pre_genre = get<Genre>(*diff_g);
            after.emplace_back(get<Title>(*diff_g));
            pre.erase(diff_g);
        }else{
            for (auto w = pre.begin(); w != pre.end(); w++) {
                after.emplace_back(get<Title>(*w));
            }
        }
    }
}//end of final sorting


int main() {
    int N,k;
    cin>>N>>k;

    vector<song> songs_data;
    input_songs(songs_data,N);
    sort(songs_data.begin(), songs_data.end(), compare);

    vector<string> final{};
    final_sorting(songs_data,final,N);

    cout<<final[k-1];

    return 0;
}
