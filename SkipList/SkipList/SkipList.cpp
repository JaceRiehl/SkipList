#include "SkipList.h"
#include "stdafx.h"

SkipList::SkipList(int maxLevel) {
	_maxLevel = maxLevel;
	_level = 0;

	_header = new Node(-1, _maxLevel);
}

Node* SkipList::createNode(int key, int level) {
	return new Node(key, level);
}

bool SkipList::insert(int key) {
	// Set the current node to the top level header
	Node* current = _header;
	
	// Create a new array which is the updated array 
	Node** update = new Node*[_maxLevel];

	// Starting from the top, search from the left to the right
	// for the highest element that is lower that the key being inserted.
	// Then, move down a level and continue the search. When we reach the bottom,
	// we have found where to insert the key.
	for (int i = _level; i >= 0; --i) {
		while (current->forward[i] && current->forward[i]->getKey() < key) {
			current = current->forward[i];
		}

		update[i] = current;
	}

	// We have reached the bottom level and the place right before the
	// place to insert the key. We make the target the value after the highest
	// key below the key to insert.
	current = current->forward[0];

	if (current == nullptr || current->getKey() != key) {
		int rLevel = getRandomLevel();

		if (rLevel > _level) {
			for (int i = _level + 1; i < rLevel + 1; ++i) {
				update[i] = _header;
			}

			_level = rLevel;
		}

		Node* n = createNode(key, rLevel);

		for (int i = 0; i <= rLevel; ++i) {
			n->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = n;
		}

		return true;
	}

	return false;
}

bool SkipList::remove(int key) {
	// Set the current node to the top level header
	Node* current = _header;

	// Create a new array which is the updated array 
	Node** update = new Node*[_maxLevel];

	// Starting from the top, search from the left to the right
	// for the highest element that is lower that the key being removed.
	// Then, move down a level and continue the search. When we reach the bottom,
	// we have found where to remove the key.
	for (int i = _level; i >= 0; --i) {
		while (current->forward[i] && current->forward[i]->getKey() < key) {
			current = current->forward[i];
		}

		update[i] = current;
	}

	// We have reached the bottom level and the place right before the
	// place to remove the key. We make the target the value after the highest
	// key below the key to remove.
	current = current->forward[0];

	if (current && current->getKey() == key) {
		for (int i = 0; i <= _level; ++i) {
			if (update[i]->forward[i] != current)
				break;

			update[i]->forward[i] = current->forward[i];
		}

		while (_level > 0 && _header->forward[_level] == 0) {
			_level--;
		}

		return true;
	}

	return false;
}

bool SkipList::search(int key) {
	Node* current = _header;

	for (int i = _level; i >= 0; --i) {
		while (current->forward[i] && current->forward[i]->getKey() < key) {
			current = current->forward[i];
		}
	}

	current = current->forward[0];

	if (current && current->getKey() == key) {
		return true;
	}

	return false;
}

int SkipList::getRandomLevel() const {
	float r = (float)rand() / RAND_MAX;
	int level = 0;
	while (r > 0.5f && level < _maxLevel) {
		++level;
		r = (float)rand() / RAND_MAX;
	}

	return level;
}

void SkipList::display() const {
	cout << endl << "*****Skip List*****" << endl;
	for (int i = _level; i >= 0; --i)
	{
		Node *node = _header->forward[i];
		cout << "Level " << i << ": ";
		while (node != nullptr)
		{
			cout << node->getKey() << " ";
			node = node->forward[i];
		}
		cout << endl;
	}
}