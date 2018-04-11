#pragma once

class Node {
	public:
		Node(int, int);
		int getKey() const;

		Node** forward;
	private:
		int _key;
};