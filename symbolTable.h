#include<iostream>
#include <unordered_map>
#include<string>
#include<vector>
using namespace std;

struct Node
{
    Node *parent;
    unordered_map<string, vector<string>> node_data;
};

Node* create(Node* parent);
bool insert(string identifier, string kind, string type, Node* curr_node);
bool lookup(string identifier, Node* curr_node);