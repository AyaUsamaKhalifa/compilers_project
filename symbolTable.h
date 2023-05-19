#include<iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
using namespace std;

  
struct Node
{
    Node *parent;
    unordered_map<string, vector<string>> node_data;
    vector<Node*> children;
};

struct symbolTable{
    Node* create(Node* parent);
    bool insert(string identifier, string kind, int type, Node* curr_node);
    bool lookup(string identifier, Node* curr_node);
    string checkType(string identifier, Node* curr_node);
    void print(Node*curr_node);
    void printcout(Node *curr_node);
    void print_recursive(Node* curr_node, ofstream& myfile);
    Node *switchScope(Node* currentScope);
    Node *functionScope(Node* currentScope);
    Node* switchBack(Node* currentScope);
};

