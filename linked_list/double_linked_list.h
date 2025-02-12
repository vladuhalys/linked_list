#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>
#include "DoubleNode.h"
#include "value.h"
#include "linked_list_abstraction.h"

class DoubleLinkedList : public BaseDoubleLinkedList
{
public:
    void push_back(IElement *value) override
    {
        DoubleNode * new_node = new DoubleNode(value);
        is_head_null() ? set_head_and_tail_both(new_node) : set_tail_next_and_prev(new_node);
        increment_size();
    }
    void push_front(IElement* value) override
    {
        DoubleNode * new_node = new DoubleNode(value);
        is_head_null() ? set_head_and_tail_both(new_node) : set_head_next_and_prev(new_node);
        increment_size();
    }
    void pop_back() override
    {
        if (is_head_null()) return;
        if (head_equals_tail())
        {
            delete_head();
            set_head_and_tail_null();
        }
        else
        {
            DoubleNode * node = dynamic_cast<DoubleNode*>(get_tail());
            set_tail(node->get_prev());
            set_tail_next(nullptr);
            delete node;
        }
        decrement_size();
    }
    void pop_front() override
    {
        if (is_head_null()) return;
        if (head_equals_tail())
        {
            delete_head();
            set_head_and_tail_null();
        }
        else
        {
            DoubleNode * node = dynamic_cast<DoubleNode*>(get_head());
            set_head(node->get_next());
            set_head_prev(nullptr);
            delete node;
        }
        decrement_size();
    }
    void insert(size_t index, IElement *value) override
    {
        if (index < 0 || index > size_) return;
        if (index == 0) this->push_front(value);
        else if (index == size_) this->push_back(value);
        else {
            INode * node = get_head();
            for (size_t i = 0; i < index - 1; i++) {
                node = node->get_next();
            }
            DoubleNode *new_elem = new DoubleNode(value);
            new_elem->set_next(node->get_next());
            new_elem->set_prev(node);
        }
        increment_size();
    }
    void remove(size_t index) override
    {
        if (index < 0 || index >= size_) return;
        if (index == 0) this->pop_front();
        else if (index == size_ - 1) this->pop_back();
        else {
            INode * node = get_head();
            for (size_t i = 0; i < index - 1; i++) {
                node = node->get_next();
            }
            DoubleNode *temp = dynamic_cast<DoubleNode*>(node->get_next());
            node->set_next(temp->get_next());
            delete temp;
        }
        decrement_size();
    }
    void remove(IElement *value, bool (*equil)(IElement first, IElement second)) override
    {
        INode * node = get_head();
        size_t index = 0;
        while (node != nullptr)
        {
            if (equil(node->get_value(), *value))
            {
                remove(index);
                return;
            }
            node = node->get_next();
            index++;
        }
    }
    DoubleLinkedList(): BaseDoubleLinkedList() {}
    ~DoubleLinkedList() override
    {
        while (!is_head_null())
        {
            pop_front();
        }
    }
    
};
#endif // DOUBLE_LINKED_LIST_H
