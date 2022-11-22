#include <bits/stdc++.h>

#include <utility>

using namespace std;
typedef pair<string,string> strpair;
list<strpair> predata;


class Tnode{
public:
    string _data;
    vector<Tnode*> children;
    int child_n = 0;
    int level = 0;

    Tnode(string data): _data(move(data)){};

};

vector<Tnode*> all_people;


void node_append(Tnode* node, string data){//append the node to tree
    Tnode *temp = new Tnode(data);
    node->children.push_back(temp);
}



void make_level(Tnode *root,int x = 0){ //set the level at each node
    root->level = x;
    x++;
    for(auto w = root->children.begin();w != root->children.end(); w++){
        make_level(*w,x);
    }
}

int make_chilen(Tnode *root){//set the number of children at each node
    int temp = root->children.size();
    for(auto w = root->children.begin();w != root->children.end(); w++){
        temp += make_chilen(*w);
    }
    return temp;
}

void insert_all(Tnode *root){ //insert all nodes to vector
    root->child_n= make_chilen(root);
    all_people.push_back(root);
    for(auto w = root->children.begin();w != root->children.end(); w++){
        insert_all(*w);
    }
}

bool compare(Tnode* x,Tnode* y){//compare for sorting
    tuple<int,int,string> tempa(x->child_n, x->level, x->_data);
    tuple<int,int,string> tempb(y->child_n, y->level, y->_data);
    swap(get<0>(tempa),get<0>(tempb));

    return tempa<tempb;
}

string decide_root(int N){//function to decide the root
    string person, boss;
    vector<string> personv, bossv;
    while(N--){
        cin>>person>>boss;
        personv.push_back(person);
        bossv.push_back(boss);
        predata.push_back({person, boss});
    }
    sort(bossv.begin(),bossv.end());
    bossv.erase(unique(bossv.begin(),bossv.end()),bossv.end());


    for(auto &w: bossv){
        if(find(personv.begin(),personv.end(),w)==personv.end()) return w;
    }//The root has not parent
}

void make_tree(Tnode* root){//make tree
    auto func = [=](strpair& x){return x.second == root->_data;};
    auto pointer = find_if(predata.begin(),predata.end(),func);
    if (pointer != predata.end()) {
        while (true) {
            node_append(root, pointer->first);
            pointer = find_if(next(pointer), predata.end(), func);
            if (pointer == predata.end()) break;
        }
    }

    if(root->children.empty()) return;
    for(auto w = root->children.begin();w != root->children.end(); w++){
        make_tree(*w);
    }
}

int main() {
    int N;
    cin>>N;
    N--;

    Tnode* tree = new Tnode(decide_root(N));
    predata.sort([](strpair& a,strpair& b){return a.second<b.second;});

    make_tree(tree);
    make_level(tree);
    make_chilen(tree);
    insert_all(tree);

    sort(all_people.begin(),all_people.end(), compare);//sort hierarchy
    for(auto w:all_people){
        cout<<w->_data<<endl;
    }
    return 0;
}
