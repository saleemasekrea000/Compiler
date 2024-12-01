
#include "semantic.hpp"

std::string GetTypeName(AST_Node *node)
{
    Type_Node *type_node = static_cast<Type_Node *>(node);
    return type_node->type_name.c_str();
}

std::string GetName(AST_Node *node)
{
    AST_Node *child = node->children[0];
    Identifier_Node *Identifier_node = static_cast<Identifier_Node *>(child);
    return Identifier_node->identifier_name.c_str();
}
std::string GetNameID(AST_Node *node)
{
    if (node->type != IDENTIFIER_NODE_TYPE)
        return "";
    Identifier_Node *Identifier_node = static_cast<Identifier_Node *>(node);
    return Identifier_node->identifier_name.c_str();
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

bool checkVariableDeclarations(AST_Node *node, std::unordered_set<std::string> declaredVariableNames)
{
    if (!node)
        return true;
    if (node->type == IDENTIFIER_NODE_TYPE)
    {
        if (declaredVariableNames.size() == 0)
        {
            return 0;
        }
        if (declaredVariableNames.find(GetNameID(node)) == declaredVariableNames.end())
        {
            return false;
        }
    }
    bool ans = true;
    for (int i = 0; i < node->children.size(); i++)
    {
        AST_Node *child = node->children[i];
        if (child->type == SIMPLE_DECLARATION && child->children[0]->type == VARIABLE_DECLARATION)
        {
            AST_Node *grand = child->children[0];
            if (grand->children.size() >= 3)
                ans &= checkVariableDeclarations(grand->children[2], declaredVariableNames);
            declaredVariableNames.insert(GetName(grand));
            continue;
        }
        if (child->type == SIMPLE_DECLARATION && child->children[0]->type == TYPE_DECLARATION)
        {
            AST_Node *grand = child->children[0];
            if (grand->children.size() >= 3)
                ans &= checkVariableDeclarations(grand->children[2], declaredVariableNames);
            continue;
        }
        if (child->type == ROUTINE_DECLERATION)
        {
            AST_Node *grand = child->children[1];
            // printf("%s\n", type_map.at(child->type).c_str());
            for (int j = 0; j < grand->children.size(); j++)
            {
                declaredVariableNames.insert(GetName(grand->children[j]));
            }
            ans &= checkVariableDeclarations(child->children[2], declaredVariableNames);
            continue;
        }
        if (child->type == Routine_Call)
        {
            ans &= checkVariableDeclarations(child->children[1], declaredVariableNames);
            continue;
        }
        if (child->type == FOR_STATEMENT)
        {
            declaredVariableNames.insert(GetNameID(child->children[0]));
            ans &= checkVariableDeclarations(child->children[1], declaredVariableNames);
            ans &= checkVariableDeclarations(child->children[2], declaredVariableNames);
            continue;
        }
        ans &= checkVariableDeclarations(child, declaredVariableNames);
    }
    return ans;
}

bool checkTypeDeclarations(AST_Node *node, std::unordered_set<std::string> declaredTypeNames)
{
    if (!node)
        return true;
    if (node->type == TYPE_NODE && node->children.size() > 0 && node->children[0]->type == IDENTIFIER_NODE_TYPE)
    {
        if (declaredTypeNames.size() == 0)
        {
            return false;
        }
        if (declaredTypeNames.find(GetNameID(node->children[0])) == declaredTypeNames.end())
        {
            return false;
        }
    }
    bool ans = true;
    for (int i = 0; i < node->children.size(); i++)
    {
        AST_Node *child = node->children[i];
        if (child->type == SIMPLE_DECLARATION && child->children[0]->type == TYPE_DECLARATION)
        {
            AST_Node *grand = child->children[0];
            declaredTypeNames.insert(GetNameID(grand->children[0]));
            continue;
        }
        ans &= checkTypeDeclarations(child, declaredTypeNames);
    }
    return ans;
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

void Semantic_Analysis::Semantic_Analysis_Checks(AST_Node *root)
{
    std::unordered_set<std::string> declaredVariableNames;
    std::unordered_set<std::string> declaredRoutineNames;
    std::unordered_set<std::string> declaredTypesNames;
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
        printf("Break statement exist outside of a loop\n");
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
    if (!checkTypeDeclarations(root, declaredTypesNames))
    {
        printf("A type is not deaclerd\n");
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

bool used_routine(AST_Node *node, std::string function_name)
{
    if (node && node->type == Routine_Call && GetName(node) == function_name)
        return 1;
    bool ans = false;
    for (const auto &child : node->children)
    {
        ans |= used_routine(child, function_name);
    }
    return ans;
}
void remove_unused_routines(AST_Node *node)
{
    if (!node)
        return;
    int childrenNumber = node->children.size();
    std::vector<AST_Node *> curChildren;
    for (int i = 0; i < childrenNumber; i++)
    {
        AST_Node *child = node->children[i];
        if (child->type != ROUTINE_DECLERATION)
        {
            curChildren.push_back(child);
            continue;
        }
        bool add = false;
        std::string routine_name = GetName(child);
        for (int j = i + 1; j < childrenNumber; j++)
        {
            if (used_routine(node->children[j], routine_name))
                add = true;
        }
        if (add)
        {
            curChildren.push_back(child);
        }
    }
    node->children.clear();
    if (curChildren.size() > 0)
    {
        node->children = curChildren;
    }
    for (const auto &child : node->children)
    {
        remove_unused_routines(child);
    }
}
bool used_var(AST_Node *node, std::string var_name, bool inside_expression)
{
    if (!node)
        return false;
    if (node->type == IDENTIFIER_NODE_TYPE)
    {
        return (GetNameID(node) == var_name && inside_expression);
    }
    if (node->type == SIMPLE_DECLARATION)
    {
        AST_Node *child = node->children[0];
        if (child->type == VARIABLE_DECLARATION && GetName(child) == var_name)
            return used_var(child->children[2], var_name, true);
    }
    if (node->type == ROUTINE_DECLERATION)
    {
        if (GetName(node) == var_name)
            return 0;
        AST_Node *params_node = node->children[1];
        for (const auto &param : params_node->children)
        {
            if (GetName(param) == var_name)
                return 0;
        }
    }
    if (node->type == FOR_STATEMENT && GetName(node) == var_name)
        return 0;
    bool ans = false;
    if (node->type == EXPRESSION)
        inside_expression = true;
    for (const auto &child : node->children)
    {
        ans |= used_var(child, var_name, inside_expression);
    }
    return ans;
}
std::string get_name_assign(AST_Node *node)
{
    if (node->type != ASSIGN_STATEMENT)
        return "";
    AST_Node *primary_node = node->children[0];
    if (primary_node->type != PRIMARY_NODE)
        return "";
    AST_Node *primary_exp_node = primary_node->children[0];
    if (primary_exp_node->type != PRIMARY_EXPRESSION)
        return "";
    AST_Node *id_node = primary_exp_node->children[0];
    if (id_node->type != IDENTIFIER_NODE_TYPE)
        return "";
    return GetNameID(id_node);
}
void remove_assignment(AST_Node *node, std::string var_name)
{
    if (!node)
        return;
    if (node->type == VARIABLE_DECLARATION && GetName(node) == var_name)
        return;
    int childrenNumber = node->children.size();
    std::vector<AST_Node *> curChildren;
    for (int i = 0; i < childrenNumber; i++)
    {
        AST_Node *child = node->children[i];
        if (child->type != STATEMENT)
        {
            curChildren.push_back(child);
            continue;
        }
        AST_Node *grand = child->children[0];
        if (grand->type != ASSIGN_STATEMENT)
        {
            curChildren.push_back(child);
            continue;
        }
        if (get_name_assign(grand) != var_name)
        {
            curChildren.push_back(child);
        }
    }
    node->children.clear();
    if (curChildren.size() > 0)
    {
        node->children = curChildren;
    }
    for (const auto &child : node->children)
    {
        remove_assignment(child, var_name);
    }
}
void remove_unused_varible(AST_Node *node)
{
    if (!node)
        return;
    int childrenNumber = node->children.size();
    std::vector<AST_Node *> curChildren;
    for (int i = 0; i < childrenNumber; i++)
    {
        AST_Node *child = node->children[i];
        if (child->type != SIMPLE_DECLARATION)
        {
            curChildren.push_back(child);
            continue;
        }
        AST_Node *grand = child->children[0];
        if (grand->type != VARIABLE_DECLARATION)
        {
            curChildren.push_back(child);
            continue;
        }
        bool add = false;
        std::string var_name = GetName(grand);
        for (int j = i + 1; j < childrenNumber; j++)
        {
            add |= used_var(node->children[j], var_name, false);
        }
        if (add)
            curChildren.push_back(child);
        else
        {
            for (int j = i + 1; j < childrenNumber; j++)
            {
                /// remove_assignment(node->children[j],var_name);
            }
        }
    }
    node->children.clear();
    if (curChildren.size() > 0)
    {
        node->children = curChildren;
    }
    for (const auto &child : node->children)
    {
        remove_unused_varible(child);
    }
}

bool used_type(AST_Node *node, std::string type_name)
{
    if (!node)
        return false;
    if (node->type == TYPE_NODE)
    {
        return (GetTypeName(node) == type_name);
    }
    bool ans = false;
    for (const auto &child : node->children)
    {
        ans |= used_type(child, type_name);
    }
    return ans;
}
void remove_unused_types(AST_Node *node)
{
    if (!node)
        return;
    int childrenNumber = node->children.size();
    std::vector<AST_Node *> curChildren;
    for (int i = 0; i < childrenNumber; i++)
    {
        AST_Node *child = node->children[i];
        if (child->type != SIMPLE_DECLARATION)
        {
            curChildren.push_back(child);
            continue;
        }
        AST_Node *grand = child->children[0];
        if (grand->type != TYPE_DECLARATION)
        {
            curChildren.push_back(child);
            continue;
        }
        bool add = false;
        std::string type_name = GetName(grand);
        for (int j = i + 1; j < childrenNumber; j++)
        {
            add |= used_type(node->children[j], type_name);
        }
        if (add)
            curChildren.push_back(child);
    }
    node->children.clear();
    if (curChildren.size() > 0)
    {
        node->children = curChildren;
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
void Semantic_Analysis::optimize(AST_Node *root)
{
    remove_unreachable_code(root);
    remove_unused(root);
}
