#include "exptree.hpp"
#include <iostream>

namespace ExpTree
{
    Variable::Variable(const char *_name)
        : name{_name}
    {
        this->name = (std::string)_name;
    }

    void Variable::operator=(double val)
    {
        this->value = val;
    }

    Variable::operator double() const
    {
        return double(this->value);
    }

    VarNode::VarNode(const char *_name)
        : name{_name}
    {
        this->name = (std::string)_name;
    }

    double VarNode::evaluate(const Variable *vars, int numVars) const
    {
        for (int i = 0; i < numVars; i++)
        {
            if (this->name == (std::string)vars[i].name)
            {
                return (double)vars[i];
            }
        }
        return 0;
    }

    Node *VarNode::clone() const
    {

        return new VarNode(*this);
    }

    ////-----SumNode------>

    SumNode::~SumNode()
    {
        delete this->children[0];
        delete this->children[1];
    }

    SumNode::SumNode(Node *lhs, Node *rhs)
        : children{lhs, rhs}
    {
        this->children[0] = lhs;
        this->children[1] = rhs;
    }

    SumNode::SumNode(const Node &lhs, const Node &rhs)
    {
        this->children[0] = lhs.clone();
        this->children[1] = rhs.clone();
    }

    Node *SumNode::clone() const
    {
        return new SumNode(this->children[0]->clone(), this->children[1]->clone());
    }

    double SumNode::evaluate(const Variable *vars, int numVars) const
    {
        return this->children[0]->evaluate(vars, numVars) + this->children[1]->evaluate(vars, numVars);
    }

    //--------MulNode------>

    MulNode::~MulNode()
    {
        delete this->children[0];
        delete this->children[1];
    }

    MulNode::MulNode(Node *lhs, Node *rhs)
        : children{lhs, rhs}
    {
        this->children[0] = lhs;
        this->children[1] = rhs;
    }

    MulNode::MulNode(const Node &lhs, const Node &rhs)
    {
        this->children[0] = lhs.clone();
        this->children[1] = rhs.clone();
    }

    Node *MulNode::clone() const
    {
        return new MulNode(this->children[0]->clone(), this->children[1]->clone());
    }

    double MulNode::evaluate(const Variable *vars, int numVars) const
    {
        return this->children[0]->evaluate(vars, numVars) * this->children[1]->evaluate(vars, numVars);
    }

}

//Bearbeitet bei Abdelhalim Abdelhalim, Abdelrahman Abdelhalim, Mahadik Hannan Javed und Moayad Okal