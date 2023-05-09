#pragma once

#ifdef __cplusplus
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
extern "C" {
#endif
    struct Node
    {
        Node *parent;
        unordered_map<string, vector<string>> node_data;
    };

    Node* create(Node* parent);
    bool insert(string identifier, string kind, string type, Node* curr_node);
    bool lookup(string identifier, Node* curr_node);

#ifdef __cplusplus
    }
#endif