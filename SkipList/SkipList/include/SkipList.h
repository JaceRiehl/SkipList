#pragma once

#include "Node.h"

class SkipList {
	public:
		SkipList(int);
		void insert(int);
		void remove(int);
		void search(int);
		void display();

	private:
		int getRandomLevel();
		Node* createNode(int, int);

		int _maxLevel;
		int _level;
		Node* _header;
};