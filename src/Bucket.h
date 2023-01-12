/**
 * @author Daniel Gleaves
*/
#ifndef BUCKET_H
#define BUCKET_H
#include "LLNode.h"
#include <pthread.h>
#include <queue>

class Bucket {
    public:
        pthread_mutex_t lock;
        pthread_cond_t cond;
        int queueHead;
        int queueTail;
        Bucket();
        bool insert(int key, std::string value);
        bool del(int key);
        std::string lookup(int key);

    private:
        llNode * head;
};


#endif
