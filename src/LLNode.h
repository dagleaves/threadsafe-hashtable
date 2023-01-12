/**
 * @author Daniel Gleaves
*/
#ifndef LLNODE_H
#define LLNODE_H
#include <string>

struct llNode {
    int key;
    std::string data;
    llNode * next = nullptr;
};

#endif