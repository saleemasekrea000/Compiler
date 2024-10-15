#include <string>
#include <vector>

using namespace std;

class Node
{
public:
  virtual ~Node() {}
};

class ExpressionNode : public Node
{
public:
  virtual ~ExpressionNode() {}
};

class StatementNode : public Node
{
public:
  virtual ~StatementNode() {}
};

class IdentifierNode : public ExpressionNode
{
public:
  std::string value;
  IdentifierNode(const std::string &value) : value(value) {}
};

class IntegerLiteralNode : public ExpressionNode
{
public:
  int value;
  IntegerLiteralNode(int value) : value(value) {}
};

class BinaryOperationNode : public ExpressionNode
{
public:
  ExpressionNode *left;
  ExpressionNode *right;
  std::string op;
  BinaryOperationNode(ExpressionNode *left, const std::string &op, ExpressionNode *right) : left(left), op(op), right(right) {}
};

class AssignmentNode : public StatementNode
{
public:
  std::string id;
  ExpressionNode *expression;
  AssignmentNode(const std::string &id, ExpressionNode *expression) : id(id), expression(expression) {}
};

class BlockNode : public StatementNode
{
public:
  std::vector<StatementNode *> statements;
  void add_statement(StatementNode *statement)
  {
    statements.push_back(statement);
  }
};

class WhileNode : public StatementNode
{
public:
  ExpressionNode *condition;
  BlockNode *body;
  WhileNode(ExpressionNode *condition, BlockNode *body) : condition(condition), body(body) {}
};

class ReturnNode : public StatementNode
{
public:
  ExpressionNode *expression;
  ReturnNode(ExpressionNode *expression) : expression(expression) {}
};

class FunctionCallNode : public StatementNode
{
public:
  std::string id;
  std::vector<ExpressionNode *> arguments;
  FunctionCallNode(const std::string &id, const std::vector<ExpressionNode *> &arguments) : id(id), arguments(arguments) {}
};

class VariableDeclarationNode : public StatementNode
{
public:
  std::string id;
  std::string type;
  VariableDeclarationNode(const std::string &id, const std::string &type) : id(id), type(type) {}
};

class RoutineNode : public Node
{
public:
  std::string id;
  std::vector<VariableDeclarationNode *> parameters;
  BlockNode *body;
  RoutineNode(const std::string &id, const std::vector<VariableDeclarationNode *> &parameters, BlockNode *body) : id(id), parameters(parameters), body(body) {}
};

class ProgramNode : public Node
{
public:
  RoutineNode *routine;
  ProgramNode(RoutineNode *routine) : routine(routine) {}
};