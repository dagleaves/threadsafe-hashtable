/**
 * @author Daniel Gleaves
*/
#include "HashTable.h"
#include <cmath>


HashTable::HashTable() {
    this->size = std::pow(2, 22);
    this->array = new Bucket[this->size];
}


// Hash function from https://stackoverflow.com/questions/17239649/writing-a-robust-integer-hash-function
unsigned int HashTable::hash(int key) {
   unsigned int hashval = key;
   hashval = ((hashval >> 16) ^ hashval) * 0x45d9f3b;
   hashval = ((hashval >> 16) ^ hashval) * 0x45d9f3b;
   hashval = ((hashval >> 16) ^ hashval);
   return hashval % this->size;
}


bool HashTable::insert(int id, int key, std::string value) {
    bool ret;
    int index = this->hash(key);
    pthread_mutex_lock(&this->array[index].lock);
    while (this->array[index].queueHead != id) {
        pthread_cond_wait(&this->array[index].cond, &this->array[index].lock);
    }
    ret = this->array[index].insert(key, value);
    this->array[index].queueHead++;
    pthread_cond_broadcast(&this->array[index].cond);
    pthread_mutex_unlock(&this->array[index].lock);
    return ret;
}


bool HashTable::deleteNode(int id, int key) {
    int index = this->hash(key);
    bool ret;
    pthread_mutex_lock(&this->array[index].lock);
    while (this->array[index].queueHead != id) {
        pthread_cond_wait(&this->array[index].cond, &this->array[index].lock);
    }
    ret = this->array[index].del(key);
    this->array[index].queueHead++;
    pthread_cond_broadcast(&this->array[index].cond);
    pthread_mutex_unlock(&this->array[index].lock);
    return ret;
}


std::string HashTable::lookup(int id, int key) {
    std::string ret;
    int index = this->hash(key);
    pthread_mutex_lock(&this->array[index].lock);
    while (this->array[index].queueHead != id) {
        pthread_cond_wait(&this->array[index].cond, &this->array[index].lock);
    }
    ret = this->array[index].lookup(key);
    this->array[index].queueHead++;
    pthread_cond_broadcast(&this->array[index].cond);
    pthread_mutex_unlock(&this->array[index].lock);
    return ret;
}