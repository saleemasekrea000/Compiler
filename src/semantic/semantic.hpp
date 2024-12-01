#ifndef SEMANTIC_ANALYSIS_HPP
#define SEMANTIC_ANALYSIS_HPP


#include "../parser/ast.hpp"



class Semantic_Analysis {
private:
    AST_Node *root;

public:
    Semantic_Analysis(AST_Node *rootNode) : root(rootNode) {}
    void Semantic_Analysis_Checks(AST_Node *node);
    void optimize(AST_Node* node);
};

#endif 
