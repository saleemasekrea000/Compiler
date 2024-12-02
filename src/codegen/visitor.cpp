class Visitor {
public:
    virtual void visit(Identifier_Node *node) = 0;
    virtual void visit(Type_Node *node) = 0;
    virtual void visit(Integer_Node *node) = 0;
    virtual void visit(Real_Node *node) = 0;
    virtual void visit(Boolean_Node *node) = 0;
    virtual void visit(BinaryOp_Node *node) = 0;
    virtual void visit(VariableDecl_Node *node) = 0;
    virtual void visit(Assign_Node *node) = 0;
    virtual void visit(If_Node *node) = 0;
    virtual void visit(While_Node *node) = 0;
    virtual void visit(For_Node *node) = 0;
        virtual ~Visitor() = default;
};
