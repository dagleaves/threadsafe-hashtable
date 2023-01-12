/**
 * @author Daniel Gleaves
*/
#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include "LLNode.h"
#include <vector>


class LinkedList {
    public:
        LinkedList();
        llNode * enq();
        bool outputReady();
        std::string pop();

    private:
        struct llNode * head;
        struct llNode * tail;
};

#endif