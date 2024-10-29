#include <stdlib.h>
#include <stdio.h>
#include "ast.hpp"
#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>



static const std::unordered_map<Node_Type, std::string> type_map = {
    {PROGRAM, "Program"},
    {DECLARATION, "Declarations"},
    {SIMPLE_DECLARATION, "Simple declaration"},
    {VARIABLE_DECLARATION, "Variable declaration"},
    {PRIMARY_EXPRESSION, "Primary expresson"},
    {PRIMARY_NODE, "Primary node"},
    {ARRAY_ACCESS, "Array access"},
    {RECORD_ACCESS, "Record access"},
    {SUMMAND, "Summand"},
    {FACTOR, "Factor"},
    {SIMPLE, "Simple"},
    {RELATION, "Relation"},
    {EXPRESSION, "Expression"},
    {TYPE_DECLARATION, "Type declaration"},
    {ARRAY_TYPE, "Array type"},
    {RECORD_TYPE, "Record type"},
    {VARIABLE_DECLARATIONS, "Variable Declarations"},
    {STATEMENT, "Statement"},
    {ITERATION_STATEMENT, "Iteration statement"},
    {WHILE_STATEMENT, "While statement"},
    {BODY, "Body"},
    {FOR_STATEMENT, "For statement"},
    {RANGE_EX, "Range"},
    {RANGE_REVERSE, "Range reverse"},
    {ASSIGN_STATEMENT, "Assignment statement"},
    {IF_STATEMENT, "if statement"},
    {IF_STATEMENT_ELSE, "if and else statement"},
    {JUMP_STATEMENT, "Jump Statement"},
    {RETURN_EX, "Return"},
    {CONTINUE_EX, "Continue"},
    {BREAK_EX, "Break"},
    {Routine_Call, "Routine Call"},
    {Argument_Expression_List, "Arguments Expression List"},
    {PARAMETER_DECLERATION, "Parameter Decleration"},
    {PARAMETERS_EXPRESSION_LIST, "Parameters Expression List"},
    {ROUTINE_DECLERATION, "Routine Decleration"}};



void print_ast_helper(AST_Node *node, int indent,FILE * output_file)
{
    if (!node)
    {
        return;
    }

    for (int i = 0; i < indent; i++)
    {
        fprintf(output_file, "  ");
    }
    if (type_map.find(node->type) != type_map.end())
    {
        fprintf(output_file, "%s\n", type_map.at(node->type).c_str());
    }
    else
    {
        switch (node->type)
        {
        case IDENTIFIER_NODE_TYPE:
        {
            Identifier_Node *Identifier_node = static_cast<Identifier_Node *>(node);
            fprintf(output_file, "Identifier: %s\n", Identifier_node->identifier_name.c_str());
            break;
        }
        case TYPE_NODE:
        {
            Type_Node *type_node = static_cast<Type_Node *>(node);
            fprintf(output_file, "Type: %s\n", type_node->type_name.c_str());
            break;
        }
        case BOOLEAN_NODE:
        {
            Boolean_Node *boolean_node = static_cast<Boolean_Node *>(node);
            fprintf(output_file, "Boolean: %s\n", (boolean_node->val ? "true" : "false")); 
            break;
        }
        case INTEGER_NODE:
        {
            Integer_Node *integer_node = static_cast<Integer_Node *>(node);
            fprintf(output_file, "Integer: %d\n", integer_node->val); 
            break;
        }
        case REAL_NODE:
        {
            Real_Node *real_node = static_cast<Real_Node *>(node);
            fprintf(output_file, "Real: %f\n", real_node->val); 
            break;
        }
        case OPERATOR:
        {
            Operator *op_node = static_cast<Operator *>(node);
            fprintf(output_file, "Operator: %s\n", op_node->operation_name.c_str());
            break;
        }
        default:
            fprintf(output_file, "Unknown Node Type\n");
            break;
        }
    }
    for (const auto &child : node->children)
    {
        print_ast_helper(child, indent + 1, output_file); 
    }
}

void print_ast(AST_Node* node, int indent, const std::string& file_name) {
    FILE* file = fopen(file_name.c_str(), "w");
    print_ast_helper(node, indent, file);
    fclose(file);
}


bool check_return(AST_Node *node, bool inside_function)
{
    if (node->type == RETURN_EX && !inside_function)
    {
        return 0;
    }
    bool cur_inside = inside_function;
    if (node->type == ROUTINE_DECLERATION)
    {
        cur_inside = 1;
    }
    bool ans = 1;
    for (const auto &child : node->children)
    {
        ans &= check_return(child, cur_inside);
    }
    return ans;
}
bool check_continue(AST_Node *node, bool inside_loop)
{
    if (node->type == CONTINUE_EX && !inside_loop)
    {
        return 0;
    }
    bool cur_inside = inside_loop;
    if (node->type == ITERATION_STATEMENT)
    {
        cur_inside = 1;
    }
    bool ans = 1;
    for (const auto &child : node->children)
    {
        ans &= check_continue(child, cur_inside);
    }
    return ans;
}
bool check_break(AST_Node *node, bool inside_loop)
{
    if (node->type == BREAK_EX && !inside_loop)
    {
        return 0;
    }
    bool cur_inside = inside_loop;
    if (node->type == ITERATION_STATEMENT)
    {
        cur_inside = 1;
    }
    bool ans = 1;
    for (const auto &child : node->children)
    {
        ans &= check_break(child, cur_inside);
    }
    return ans;
}
void Semantic_Analysis_Checks(AST_Node *root)
{
    std::unordered_set<std::string> declaredVariableNames;
    std::unordered_set<std::string> declaredRoutineNames;
    if (!check_return(root, 0))
    {
        printf("Return statement exist outside of a function\n");
        return;
    }
    if (!check_continue(root, 0))
    {
        printf("Continue statement exist outside of a loop\n");
        return;
    }
    if (!check_break(root, 0))
    {
        printf( "Break statement exist outside of a loop\n");
        return;
    }
    if (!checkVariableDeclarations(root, declaredVariableNames))
    {
        printf("varible is not deaclerd \n");
        return;
    }
    if (!checkRoutineDeclarations(root, declaredRoutineNames))
    {
        printf("function is not deaclerd \n");
        return;
    }
}

void remove_unreachable_code(AST_Node *node)
{
    if (!node)
    {
        return;
    }
    int cnt = 1e9;
    for (int i = 0; i < (node->children).size(); i++)
    {
        if ((node->children)[i]->type == STATEMENT &&
            ((node->children)[i]->children).size() > 0 &&
            (node->children)[i]->children[0]->type == JUMP_STATEMENT)
        {
            cnt = i;
            break;
        }
    }
    cnt++;
    while ((node->children).size() > cnt)
    {
        (node->children).pop_back();
    }
    for (const auto &child : node->children)
    {
        remove_unreachable_code(child);
    }
}


Identifier_Node *getIdentifierNode(AST_Node *node)
{
    if (!node)
        return nullptr;

    if (!node->children.empty() && node->children[0]->type == IDENTIFIER_NODE_TYPE)
    {
        return static_cast<Identifier_Node *>(node->children[0]);
    }
    return nullptr;
}

bool checkRoutineDeclarations(AST_Node *node, std::unordered_set<std::string> &declaredRoutineNames)
{
    if (node->type == ROUTINE_DECLERATION)
    {
        Identifier_Node *identifierNode = getIdentifierNode(node);
        if (identifierNode)
        {
            declaredRoutineNames.insert(identifierNode->identifier_name);
        }
    }
    else if (node->type == Routine_Call)
    {
        if (!node->children.empty() && node->children[0]->type == IDENTIFIER_NODE_TYPE)
        {
            Identifier_Node *identifierNode = static_cast<Identifier_Node *>(node->children[0]);
            return declaredRoutineNames.count(identifierNode->identifier_name) > 0;
        }
    }

    for (AST_Node *child : node->children)
    {
        if (!checkRoutineDeclarations(child, declaredRoutineNames))
        {
            return false;
        }
    }

    return true;
}

bool checkVariableDeclarations(AST_Node *node, std::unordered_set<std::string> &declaredVariableNames)
{
    // todo ....
    return true;
}


std::string get_name(AST_Node* node){
  AST_Node* child= node->children[0];
  Identifier_Node* Identifier_node = static_cast<Identifier_Node*>(child);
  return Identifier_node->identifier_name.c_str();
}
std::string get_name_id(AST_Node* node){
  Identifier_Node* Identifier_node = static_cast<Identifier_Node*>(node);
  return Identifier_node->identifier_name.c_str();
}
bool used_routine(AST_Node* node, std::string function_name){
    if(node&&node->type==Routine_Call&&get_name(node)==function_name)return 1;
    bool ans=false;
    for (const auto& child : node->children) {
        ans|=used_routine(child,function_name);
    }
    return ans;
}
void remove_unused_routines(AST_Node* node){
   if (!node)return ;
   int childrenNumber=node->children.size();
   std::vector<AST_Node*> curChildren ;
   for(int i=0;i<childrenNumber;i++){
      AST_Node* child = node->children[i];
      if (child->type!=ROUTINE_DECLERATION){
        curChildren.push_back(child);
        continue;
      }
      bool add=false; 
      std::string routine_name=get_name(child);
      for(int j=i+1;j<childrenNumber;j++){
        if(used_routine(node->children[j],routine_name))add=true;
      }
      if(add){
        curChildren.push_back(child);
      }
   }
   node->children.clear();
   if(curChildren.size()>0){
      node->children=curChildren;
   }
   for (const auto& child : node->children) {
        remove_unused_routines(child);
    }
}
bool used_var(AST_Node* node, std::string var_name, bool inside_expression){
    if(!node)return false;
    if (node->type==IDENTIFIER_NODE_TYPE){
       return (get_name_id(node)==var_name&&inside_expression);
    }
    if (node->type==SIMPLE_DECLARATION){
        AST_Node* child=node->children[0];
        if(child->type==VARIABLE_DECLARATION&&get_name(child)==var_name)
            return used_var(child->children[2],var_name,true);
    }
    if (node->type==ROUTINE_DECLERATION){
      if (get_name(node)==var_name)return 0;
      AST_Node* params_node=node->children[1];
      for (const auto& param: params_node->children){
         if(get_name(param)==var_name)return 0;
      }
    }
    if (node->type==FOR_STATEMENT&&get_name(node)==var_name)return 0; 
    bool ans=false;
    if (node->type==EXPRESSION)inside_expression=true;
    for (const auto& child : node->children) {
        ans |= used_var(child,var_name,inside_expression);
    }
    return ans;
}
void remove_unused_varible(AST_Node* node){
    if (!node)return ;
    int childrenNumber=node->children.size();
    std::vector<AST_Node*> curChildren ;
    for(int i=0;i<childrenNumber;i++){
        AST_Node* child=node->children[i];
        if(child->type!=SIMPLE_DECLARATION){
            curChildren.push_back(child);
            continue;
        }
        AST_Node* grand= child->children[0];
        if(grand->type!=VARIABLE_DECLARATION){
            curChildren.push_back(child);
            continue;
        }
        bool add =false ;
        std::string var_name=get_name(grand);
        for(int j=i+1;j<childrenNumber;j++){
            add |= used_var(node->children[j],var_name,false);
        }
        if(add)curChildren.push_back(child);
    }
    node->children.clear();
    if(curChildren.size()>0){
       node->children=curChildren;
    }
    for (const auto &child : node->children)
    {
        remove_unused_varible(child);
    }
}

std::string get_type_name(AST_Node* node){
    Type_Node *type_node = static_cast<Type_Node *>(node);
    return type_node->type_name.c_str();
}
bool used_type(AST_Node* node, std::string type_name){
   if (!node)return false;
   if (node->type==TYPE_NODE){
      return (get_type_name(node)==type_name);
   }
   bool ans=false;
   for (const auto& child : node->children) {
      ans |= used_type(child,type_name);
   }
   return ans;
}
void remove_unused_types(AST_Node* node){
    if (!node)return ;
    int childrenNumber=node->children.size();
    std::vector<AST_Node*> curChildren ;
    for(int i=0;i<childrenNumber;i++){
        AST_Node* child=node->children[i];  
        if(child->type!=SIMPLE_DECLARATION){
            curChildren.push_back(child);
            continue;
        }
        AST_Node* grand= child->children[0];
        if(grand->type!=TYPE_DECLARATION){
            curChildren.push_back(child);
            continue;
        }      
        bool add =false ;
        std::string type_name=get_name(grand);
        for(int j=i+1;j<childrenNumber;j++){
            add |= used_type(node->children[j],type_name);
        }
        if(add)curChildren.push_back(child);
    }
    node->children.clear();
    if(curChildren.size()>0){
       node->children=curChildren;
    }
    for (const auto &child : node->children)
    {
        remove_unused_types(child);
    }
}
void remove_unused(AST_Node *root)
{
    remove_unused_routines(root);
    remove_unused_varible(root);
    remove_unused_types(root);
}
void optimize(AST_Node *root)
{
    remove_unreachable_code(root);
    remove_unused(root);
}