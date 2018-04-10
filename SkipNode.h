#ifndef SKIP_NODE_H
#define SKIP_NODE_H

class SkipNode
{
public:

	// default skiplist constuctor
	SkipNode() {};

	// SkipNode constuctor
	SkipNode(int key, int level)
	{
		this->key = key;

		// Allocate memory for forward 
		forward = new SkipNode*[level + 1];

		// Fill forward array with 0
		for (int i = 0; i < level + 1; i++)
		{
			forward[i] = 0;
		}
	}

	int key;

	// array that stores pointers to forward nodes
	SkipNode **forward;
};

#endif