#ifndef AST_HPP
#define AST_HPP

#include <string>
#include <vector>
#include <memory>

enum class NodeType
{
  Program,
  Routine,
  Variable,
  FunctionCall,
  Assignment,
  Return,
  Parameters
};

struct Node
{
  NodeType type;
  std::string name;
  std::vector<std::shared_ptr<Node>> children;
};

std::shared_ptr<Node> make_program(std::vector<std::shared_ptr<Node>> children);
std::shared_ptr<Node> make_routine(std::string name, std::vector<std::shared_ptr<Node>> children);
std::shared_ptr<Node> make_variable(std::string name);
std::shared_ptr<Node> make_function_call(std::string name, std::vector<std::shared_ptr<Node>> arguments);
std::shared_ptr<Node> make_assignment(std::string name, std::shared_ptr<Node> value);
std::shared_ptr<Node> make_return(std::shared_ptr<Node> value);
std::shared_ptr<Node> make_parameters(std::string name, std::shared_ptr<Node> next);

#endif // AST_HPP