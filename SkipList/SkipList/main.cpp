// SkipList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SkipList.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
	vector<int> numbersToInsert = { 2, 5, 19, 14, 16, 40, 26, 35, 60 };
	vector<int> numbersToSearch = { 1, 19, 16, 42, 35 };
	vector<int> numbersToDelete = { 19, 35 };
	SkipList sl(100);
	
	for (int i = 0; i < numbersToInsert.size(); ++i) {
		if (sl.insert(numbersToInsert[i])) {
			cout << "Successfully inserted " << numbersToInsert[i] << endl;
		}

		else
			cout << "Could not insert " << numbersToInsert[i] << endl;
	}

	sl.display();

	for (int i = 0; i < numbersToSearch.size(); ++i) {
		if (sl.search(numbersToSearch[i])) {
			cout << "Successfully found " << numbersToSearch[i] << endl;
		}

		else
			cout << "Could not find " << numbersToSearch[i] << endl;
	}

	for (int i = 0; i < numbersToDelete.size(); ++i) {
		if (sl.remove(numbersToDelete[i])) {
			cout << "Successfully removed " << numbersToDelete[i] << endl;
		}

		else
			cout << "Could not remove " << numbersToDelete[i] << endl;
	}

	sl.display();

	cin.get();

    return 0;
}

