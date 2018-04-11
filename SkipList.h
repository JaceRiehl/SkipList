#ifndef SKIPLIST_H
#define SKIPLIST_H
#include "Node.h"
class SkipList{
public:
    SkipList(int MAX_LEVELS, float probability): MAX_LEVEL{MAX_LEVELS}, probability{probability}{}
    ~SkipList(){}
    bool insert(int);
    bool search(int);
    void delete(int);
    void print();

private:
    int randomLevel();
    int MAX_LEVELS; 
    float probability; 
    int level = 0;
    Node* head; 
};
#endif