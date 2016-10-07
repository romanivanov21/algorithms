//
// Created by roman on 19.05.16.
//

#ifndef _LIST_H_
#define _LIST_H_

namespace struct_data
{
    template<class T>
    class list
    {
    public:
        list();
        ~list();

        void push_back(T value);
        void push_front(T value);

        T pop_back();
        T pop_front();

        void print_list()const;

    private:

        struct node
        {
            node(T value, node *next, node *previus) : next_(next), previus_(previus), value_(value) { }
            node() : next_(NULL), previus_(NULL), value_(0) { }

            node *next_;
            node *previus_;
            T value_;

        };

        node *head_;
        node *tail_;
    };
}

#include "list_impl.h"

#endif //_LIST_H_
