#pragma once

#include "Node.h"
#include <iostream>

using std::endl;
using std::cout;

class SkipList {
	public:
		SkipList(int);
		bool insert(int);
		bool remove(int);
		bool search(int);
		void display() const;

	private:
		int getRandomLevel() const;
		Node* createNode(int, int);

		int _maxLevel;
		int _level;
		Node* _header;
};
