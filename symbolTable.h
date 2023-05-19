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
    bool insertEnumVar(string identifier, string kind, string type, Node *curr_node);
    bool lookup(string identifier, Node* curr_node);
    string checkType(string identifier, Node* curr_node);
    string checkKind(string identifier, Node *curr_node);
    bool checkEnum(string enumName, string identifier, Node *curr_node);
    void print(Node*curr_node);
    void printcout(Node *curr_node);
    void print_recursive(Node* curr_node, ofstream& myfile);
    void updateEnumMap(Node* curr_node, string identifier);
    void updateFunctionMap(Node* curr_node, string identifier);
    Node *switchScope(Node* currentScope);
    Node *functionScope(Node* currentScope);
    Node* switchBack(Node* currentScope);
    unordered_map<string, Node*> enumMap;
    unordered_map<string, Node*> functionMap;
};

