#include "Node.h"
#include "stdafx.h"

Node::Node(int key, int level) {
	_key = key;

	forward = new Node*[level + 1];

	for (int i = 0; i < level; ++i) {
		forward[i] = 0;
	}
}

int Node::getKey() const {
	return _key;
}