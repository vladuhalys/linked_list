#ifndef DOUBLENODE_H
#define DOUBLENODE_H
#include "node_abstraction.h"

class DoubleNode : public INode
{
private:
    IElement* value_ = nullptr;
    INode* next_ = nullptr;
    INode* prev_ = nullptr;
public:
    void set_prev(INode *node)
    {
        this->prev_ = node;
    }
    void set_next(INode *node) override
    {
        this->next_ = node;
    }
    INode *get_next() override
    {
        return this->next_;
    }
    INode *get_prev() const
    {
        return this->prev_;
    }
    IElement& get_value() override
    {
        return *this->value_;
    }
    DoubleNode() = default;
    DoubleNode(IElement* value) : value_(value) {}
    ~DoubleNode() override
    {
        delete value_;
    }
};

#endif // DOUBLENODE_H
