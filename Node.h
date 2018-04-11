#ifndef NODE_H
#define NODE_H

class Node{
public:
    Node(){}
    Node(int keyValue, int level)
    {
        this->key = keyValue;

        // Allocate memory for forward 
        forward = new Node*[level + 1];

        // Fill forward array with 0
        for (int i = 0; i < level + 1; i++)
        {
            forward[i] = 0;
        }
    }

    int key;
    Node **forward;
};

#endif