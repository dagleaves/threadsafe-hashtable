/**
 * @author Daniel Gleaves
*/
#include "LinkedList.h"
#include <iostream>
#include <vector>


LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}


llNode * LinkedList::enq() {
    llNode * nodeP = new llNode();
    nodeP->next = nullptr;
    nodeP->data = "";

    if (this->head == nullptr) {
        this->head = nodeP;
        this->tail = nodeP;
    }
    else {
        this->tail->next = nodeP;
        this->tail = nodeP;
    }
    return nodeP;
}


bool LinkedList::outputReady() {
    if (this->head == nullptr) {
        return false;
    }
    return this->head->data != "";
}


std::string LinkedList::pop() {
    if (this->head == nullptr) {
        return "No outputs left";
    }

    llNode * temp = this->head;
    this->head = this->head->next;
    std::string tempData = temp->data;
    delete temp;
    return tempData;
}