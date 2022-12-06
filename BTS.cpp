#include <bits/stdc++.h>

using namespace std;

class Node{//BST node
public:
    string _word;

    int level = 0, pre_direction = 0;

    Node *left   = nullptr,
         *right  = nullptr,
         *parent = nullptr;

    Node(string word):_word(word){};
};

Node* root = nullptr;
vector<int> depth;

bool isleaf(Node* node){
    return (!node->left)and(!node->right);
}

bool node_append(string word){
    if (!root) {
        root = new Node(word);
        return true;
    }

    Node* cursor = root, *parent;
    while (cursor){
        parent = cursor;
        if      (word < cursor->_word) cursor = cursor->left;
        else if (word > cursor->_word) cursor = cursor->right;
        else    return false;
    }

    Node* newNode = new Node(word);
    newNode->parent = parent;
    if (word < parent->_word) {
        parent->left = newNode;
    }
    else {
        newNode->pre_direction = 1;
        parent->right = newNode;
    }
    return true;
}

Node* find_node(Node* node, string word){
    if (!node)               return 0;
    if (node->_word == word) return node;
    if (node->_word >  word)
        return find_node(node->left ,word);
        return find_node(node->right,word);
}

Node* Max(Node* node){
    if (!node) return 0;
    if (!node->right) return node;
    else              return Max(node->right);
}
Node* Min(Node* node){
    if (!node) return 0;
    if (!node->left) return node;
    else              return Min(node->left);
}

void remove_leaf(Node* node){
    if (node->pre_direction) node->parent->right = nullptr;
    else                     node->parent->left  = nullptr;
}

void remove(Node* node){
    if ((!node->parent)and(isleaf(node))) {
        root = nullptr;
        return;
    }

    if (isleaf(node)) {
        remove_leaf(node);
        return;
    }

    Node* temp;
    if (node->left){
        temp = Max(node->left);
        node->_word = temp->_word;
    }else{
        temp = Min(node->right);
        node->_word = temp->_word;
    }
    remove(temp);
}

void erase_node(Node* node, string word){
    Node* xx = find_node(node,word);
    if (!xx) return;
    remove(xx);
}

void setting_level(Node* node, int x = 1){
    if (!node) return;
    node->level = x;
    x++;
    setting_level(node->left,x);
    setting_level(node->right,x);
}

void print_leaf(Node* node){
    if (!node) return;
    if (isleaf(node))
        cout<<node->_word<<" ";

    print_leaf(node->left);
    print_leaf(node->right);
}

void print_depth(Node* node, int d){
    if (!node) return;
    if (node->level==d){
        cout<<node->_word<<" ";
        depth.push_back(1);
    }
    print_depth(node->left,d);
    print_depth(node->right,d);
}



void cmd(Node* root, int x){
    string word;
    int k;
    switch (x){
        case 0:
            cin>>word;
            node_append(word);
            break;
        case 1:
            cin>>word;
            erase_node(root,word);
            break;
        case 2:
            setting_level(root);
            cin>>k;
            print_depth(root,k);
            if(depth.empty()) cout<<"NO";
            cout<<endl;
            depth = {};
            break;
        case 3:
            print_leaf(root);
            cout<<endl;
            break;
    }
}

bool input_commad(){
    string command;
    cin>>command;
    if      (command == "+"    ) cmd(root,0);
    else if (command == "-"    ) cmd(root,1);
    else if (command == "depth") cmd(root,2);
    else if (command == "leaf" ) cmd(root,3);
    else if (command == "quit") return true;

    return false;
}
int main() {

    while (true){
        if (input_commad()) break;

    }
    return 0;
}
