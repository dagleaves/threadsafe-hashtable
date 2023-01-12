/**
 * @author Daniel Gleaves
*/
#include "Bucket.h"


Bucket::Bucket() {
    this->lock = PTHREAD_MUTEX_INITIALIZER;
    this->cond = PTHREAD_COND_INITIALIZER;
    this->queueHead = this->queueTail = 0;
    this->head = nullptr;
}


bool Bucket::insert(int key, std::string value) {
    if (this->head == nullptr) {
        this->head = new llNode;
        this->head->key = key;
        this->head->data = value;
        return true;
    }

    // std::cout << "Bucket inserting\n";
    llNode * current = this->head;
    while (current->next != nullptr) {
        if (current->key == key) {
            return false;
        }
        current = current->next;
    }
    current->next = new llNode;
    current->next->key = key;
    current->next->data = value;
    return true;
}


bool Bucket::del(int key) {
    if (this->head == nullptr) return false;
    llNode * parent = nullptr;
    llNode * current = this->head;

    while (current->next != nullptr && current->key != key) {
        parent = current;
        current = current->next;
    }

    // Did not find
    if (current->key != key) return false;

    // Still at root
    if (parent == nullptr) {
        llNode * temp = this->head;
        this->head = this->head->next;
        delete temp;
        return true;
    }

    // Not at the root
    llNode * temp = current;
    parent->next = current->next;
    delete temp;
    return true;
}


std::string Bucket::lookup(int key) {
    std::string ret;
    if (this->head == nullptr) return "";
    llNode * current = this->head;

    while (current->next != nullptr && current->key != key) {
        current = current->next;
    }

    // Did not find
    if (current->key != key) return "";
    return current->data;
}