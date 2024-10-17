// ast.cpp

#include "ast.hpp"

std::shared_ptr<Node> make_program(std::vector<std::shared_ptr<Node>> children)
{
  return std::make_shared<Node>(Node{NodeType::Program, "", std::move(children)});
}

std::shared_ptr<Node> make_routine(const std::string &name, std::vector<std::shared_ptr<Node>> children)
{
  return std::make_shared<Node>(Node{NodeType::Routine, name, std::move(children)});
}

std::shared_ptr<Node> make_variable(const std::string &name)
{
  return std::make_shared<Node>(Node{NodeType::Variable, name, {}});
}

std::shared_ptr<Node> make_function_call(const std::string &name, std::vector<std::shared_ptr<Node>> arguments)
{
  return std::make_shared<Node>(Node{NodeType::FunctionCall, name, std::move(arguments)});
}

std::shared_ptr<Node> make_assignment(const std::string &name, std::shared_ptr<Node> value)
{
  return std::make_shared<Node>(Node{NodeType::Assignment, name, {std::move(value)}});
}

std::shared_ptr<Node> make_return(std::shared_ptr<Node> value)
{
  return std::make_shared<Node>(Node{NodeType::Return, "", {std::move(value)}});
}

std::shared_ptr<Node> make_parameters(const std::string &name, std::shared_ptr<Node> next)
{
  return std::make_shared<Node>(Node{NodeType::Parameters, name, {std::move(next)}});
}