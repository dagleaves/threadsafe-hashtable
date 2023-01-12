/**
 * @author Daniel Gleaves
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Bucket.h"


class HashTable {
    public:
        Bucket * array;
        unsigned int hash(int key);
        HashTable();
        bool insert(int id, int key, std::string value);
        bool deleteNode(int id, int key);
        std::string lookup(int id, int key);
    
    private:
        int size;
};


#endif
