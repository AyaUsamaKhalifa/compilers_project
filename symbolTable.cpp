#include "symbolTable.h"
#include<string.h>
Node *symbolTable::create(Node *parent)
{
    Node *new_node = new Node;
    new_node->parent = parent;
    return new_node;
}

bool symbolTable::insert(string identifier, string kind, int type, Node *curr_node)
{
    //if the identifier already exists in current scope
    bool exists = false;
    for (auto it = curr_node->node_data.begin(); it != curr_node->node_data.end(); ++it) {
        if( it->first == identifier)
        {
            exists = true;
        }
    }
    if(exists){
        return false;
    }
    string typeString;
    switch(type){
        case 0: //integer
            typeString="integer";
            break;
        case 1: //float
            typeString="float";
            break;
        case 2: //string
            typeString="string";
            break;
        case 3: //bool
            typeString="boolean";
            break;
        case 4: //void
            typeString="void";
            break;
        case 5: //char
            typeString="char";
            break;
        case 6: //enum
            typeString="enum";
            break;
    }
    // current node does not exist return false
    vector<string> data(2);
    data[0] = kind;
    data[1] = typeString;
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
