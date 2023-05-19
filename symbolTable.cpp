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

        case 7:
            typeString="const";
            break;
    }
    // current node does not exist return false
    vector<string> data(2);
    data[0] = kind;
    data[1] = typeString;
    curr_node->node_data[identifier] = data;
    return true;
}

bool symbolTable::insertEnumVar(string identifier, string kind, string type, Node *curr_node)
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
    // current node does not exist return false
    vector<string> data(2);
    data[0] = kind;
    data[1] = type;
    curr_node->node_data[identifier] = data;
    return true;

}

void symbolTable::updateEnumMap(Node* curr_node, string identifier){
    cout<<"enum added :"<<identifier<<endl;
    enumMap[identifier] = curr_node;
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
string symbolTable::checkType(string identifier, Node *curr_node)
{
    if(curr_node == nullptr)
    {
        return "Error";
    }
    for (auto it = curr_node->node_data.begin(); it != curr_node->node_data.end(); ++it) {
        if( it->first == identifier)
        {
            return it->second[1];
        }
    }
    return checkType(identifier, curr_node->parent);
}

string symbolTable::checkKind(string identifier, Node *curr_node)
{
    if(curr_node == nullptr)
    {
        return "Error";
    }
    for (auto it = curr_node->node_data.begin(); it != curr_node->node_data.end(); ++it) {
        if( it->first == identifier)
        {
            return it->second[0];
        }
    }
    return checkKind(identifier, curr_node->parent);
}


bool symbolTable::checkEnum(string enumName, string identifier, Node *curr_node)
{
    //enumName is the type of the lhs operand, the identifier is the name of the rhs operand
    Node* enumScope = enumMap[enumName];
    for (auto it = enumScope->node_data.begin(); it != enumScope->node_data.end(); ++it) {
        if( it->first == identifier)
        {
            return true;
        }
    }
    return false;
}

Node * symbolTable::switchScope(Node* currentScope){
    Node* newNode = new Node();
    newNode->parent = currentScope;
    currentScope->children.push_back(newNode);
    currentScope = newNode;
    return currentScope;
}

Node * symbolTable::functionScope(Node* currentScope){
    Node* newNode = new Node();
    currentScope->children.push_back(newNode);
    currentScope = newNode;
    return currentScope;
}

Node* symbolTable::switchBack(Node* currentScope){
    return currentScope->parent;
}

void symbolTable::print(Node *curr_node)
{
    ofstream myfile;
    myfile.open ("symboltable.txt");
    myfile<<"id\t\tkind\t\t\ttype\n";
    cout<<"id\t\tkind\t\t\ttype\n";

    print_recursive(curr_node, myfile);
    printcout(curr_node);

    myfile.close();
}

void symbolTable::printcout(Node *curr_node)
{
    if(curr_node == nullptr)
    {
        return;
    }
    for (auto it = curr_node->node_data.begin(); it != curr_node->node_data.end(); ++it) {
        cout << it->first << "\t\t" << it->second[0] << "\t\t" << it->second[1] << endl;
    }
    cout<<"========================================================================\n";
    for(int i=0;i<curr_node->children.size();i++){
        printcout(curr_node->children[i]);
    }
}

void symbolTable::print_recursive(Node* curr_node, ofstream& myfile){
    if(curr_node == nullptr)
    {
        return;
    }
    for (auto it = curr_node->node_data.begin(); it != curr_node->node_data.end(); ++it) {
        myfile << it->first << "\t\t" << it->second[0] << "\t\t" << it->second[1] << endl;
    }
    myfile<<"========================================================================\n";
    for(int i=0;i<curr_node->children.size();i++){
        print_recursive(curr_node->children[i],myfile);
    }
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
