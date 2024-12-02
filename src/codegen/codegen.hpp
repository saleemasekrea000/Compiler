#ifndef CODEGEN_HPP
#define CODEGEN_HPP

#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/Value.h"
#include <llvm/IR/IntrinsicInst.h>
#include "../parser/ast.hpp"

class Codegen {
public:
    AST_Node *root;

    Codegen(AST_Node *rootNode) : root(rootNode) {}

    void start_llvm(AST_Node *root);
};

#endif
