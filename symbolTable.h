#include<iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

    
struct Node
{
    Node *parent;
    unordered_map<string, vector<string>> node_data;
};
class symbolTable{
    Node* create(Node* parent);
    bool insert(string identifier, string kind, string type, Node* curr_node);
    bool lookup(string identifier, Node* curr_node);
    void print(Node *curr_node);
};

