#include "symbolTable.h"
#include<string.h>
Node *symbolTable::create(Node *parent)
{
    Node *new_node = new Node;
    new_node->parent = parent;
    return new_node;
}

bool symbolTable::insert(string identifier, string kind, string type, Node *curr_node)
{
    // current node does not exist return false
    vector<string> data(2);
    data[0] = kind;
    data[1] = type;
    curr_node->node_data[identifier] = data;
    return true;
}

bool symbolTable::lookup(string identifier, Node *curr_node)
{
    if(curr_node == nullptr)
    {
        return false;
    }
    for (auto it = curr_node->node_data.begin(); it != curr_node->node_data.end(); ++it) {
        if( it->first == identifier)
        {
            return true;
        }
    }
    return lookup(identifier, curr_node->parent);
}

void symbolTable::print(Node *curr_node)
{
    if(curr_node == nullptr)
    {
        return;
    }
    for (auto it = curr_node->node_data.begin(); it != curr_node->node_data.end(); ++it) {
        std::cout << it->first << " " << it->second[0] << " " << it->second[1] << std::endl;
    }
    print(curr_node->parent);
}


// int main()
// {
//     Node *new_node = new Node;
//     bool check = insert("x", "var", "int", new_node);
//     Node *child_node = create(new_node);
//     check = insert("y", "var", "float", child_node);
//     check = lookup("x", child_node);
//     cout << check << endl;
//     check = lookup("y", child_node);
//     cout << check << endl;
//     check = lookup("z", child_node);
//     cout << check << endl;
//     print(child_node);
//     return 0;
// }
