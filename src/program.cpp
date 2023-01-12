/**
 * @author Daniel Gleaves
*/
#ifndef PROGRAM
#define PROGRAM
#include "LinkedList.h"
#include "HashTable.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <thread>
#include <vector>
#include <algorithm>


std::ifstream verifyInput(std::string IN_FILE) {
    std::ifstream input(IN_FILE);
    if (!input) {
        std::cerr << "File not found: " << IN_FILE << std::endl;
        throw std::exception();
    }
    return input;
}

std::string getKey(std::string command) {
    return command.substr(2, command.find(' ', 2) - 2);
}


void runCommand(int id, HashTable& bst, std::string command, llNode * output) {
    char operation = command[0];
    std::string key = getKey(command);

    switch(operation) {
        case 'I': {
            
            std::size_t valueBegin = command.find("\"");
            std::size_t valueEnd = command.find("\"", valueBegin + 1);
            std::string value = command.substr(valueBegin, valueEnd);
            value.erase(std::remove(value.begin(), value.end(), '"'), value.end());

            bool valid = bst.insert(id, std::stoi(key), value);
            if (valid) {
                output->data = "OK";
            }
            else{
                output->data = "Fail";            
            }
            break;
        }
        case 'D': {
            bool valid = bst.deleteNode(id, std::stoi(key));
            if (valid) {
                output->data = "OK";
            }
            else{
                output->data = "Fail";
            }
            break;
        }
        case 'L': {
            std::string match = bst.lookup(id, std::stoi(key));
            if (match == "") {
                output->data = "No " + key;
            }
            else{
                output->data = match;
            }
            break;
        }
        default:
            output->data = "Invalid BST command: " + operation + '\n';  
    }
}


void processOutputs(LinkedList& outputs, std::ofstream& oStream) {
    while (outputs.outputReady()) {
        std::string output = outputs.pop();
        oStream << output << std::endl;
    }
}
   

void run(std::string inputFile, std::string outputFile) {
    std::ifstream input;
    try {
        input = verifyInput(inputFile);
    } 
    catch (std::exception &ex) {
        exit(EXIT_FAILURE);
    }

    std::ofstream oStream(outputFile);

    // Ensure valid file format providing number of threads
    std::string threadsString;
    std::getline(input, threadsString);
    assert((threadsString[0] == 'N') && "Invalid file format");

    std::string strThreads = threadsString.substr(2);
    int numThreads = std::stoi(strThreads);
    oStream << "Using " << numThreads << " threads\n";

    HashTable bst = HashTable();
    LinkedList outputs = LinkedList();
    std::vector<std::thread> threads;
    std::string currentCommand;

    while (input.peek() != EOF) {
        for (int i = 0; i < numThreads; i++) {
            if (input.peek() == EOF) break;
            llNode * output = outputs.enq();
            std::getline(input, currentCommand);
            int key = std::stoi(getKey(currentCommand));
            std::thread newThread = std::thread(&runCommand, bst.array[bst.hash(key)].queueTail++, std::ref(bst), currentCommand, output);
            threads.emplace_back(std::move(newThread));
        }
        for (auto& thread : threads) {
            thread.join();
        }
        threads.clear();
        processOutputs(outputs, oStream);
    }
    threads.clear();
    processOutputs(outputs, oStream);
}

#endif
