#include <string>

/* An expression is a sequence of operators and operands that specifies a computation.
 * It can be organised in form of a tree, where nodes are operators and leaves
 * are values or variables.
 * TODO: * complete Variable
 *       * make use of inheritance to organize the nodes
 *       * implement functionality of the node types
 */

namespace ExpTree
{

    // Stores the value of a named variable.
    // This class is used to subtitute values for the variables represented by the VarNodes
    // in the expression tree.
    class Variable
    {
    public:
        // Constructs a variable with the given name.
        Variable(const char *_name);

        // Store the name as a std::string for easy comparison
        std::string name; //const

        // TODO: Implement an assignment operator to set and a conversion operator
        // to double to get the value.
        void operator=(double val);
        operator double() const;

    private:
        double value;
    };

    // The (abstract) base class of nodes the expression tree is built of.
    class Node
    {
    public:
        /**
     * This function calculates the value of the term the (sub)tree represents
     * with the current variable values. Something is missing though ...
     *
     * @param vars An array of Variables
     * @param numVars The length of vars.
     * TODO: Implement this function for all node types.
     *       Make sure that the right one is called when operating with Node*.
     */
        explicit Node() {}

        virtual ~Node() {}
        virtual double evaluate(const Variable *vars, int numVars) const = 0;
        virtual Node *clone() const = 0;
    };

    // A base class for binary operators.
    // TODO: Use this class to correctly delete subnodes on destruction.
    class BinOpNode : public Node
    {
        //virtual ~BinOpNode();
    };

    // Calculates the sum of the two operands.
    class SumNode : public Node
    {
    public:
        ~SumNode() override;
        SumNode(Node *lhs, Node *rhs);
        SumNode(const Node &lhs, const Node &rhs);
        virtual double evaluate(const Variable *vars, int numVars) const override;
        virtual Node *clone() const override;

    private:
        Node *children[2];
    };

    // Calculates the product of the two operands.
    class MulNode : public Node
    {
    public:
        ~MulNode() override;
        MulNode(Node *lhs, Node *rhs);
        MulNode(const Node &lhs, const Node &rhs);
        virtual double evaluate(const Variable *vars, int numVars) const override;
        virtual Node *clone() const override;

    private:
        Node *children[2];
    };

    // Represents a variable in the tree.
    class VarNode : public Node
    {
    public:
        explicit VarNode(const char *_name);
        virtual double evaluate(const Variable *vars, int numVars) const override;

        virtual Node *clone() const override;

    private:
        std::string name;
        double value;
    };

}

//Bearbeitet bei Abdelhalim Abdelhalim, Abdelrahman Abdelhalim, Mahadik Hannan Javed und Moayad Okal