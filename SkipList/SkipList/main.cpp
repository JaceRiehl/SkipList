// SkipList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SkipList.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <chrono>


using std::clock_t;
using std::clock;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

double getAverage(vector<double>);

int main()
{
	// initialize skiplist
	int maxNumber = 10000;
	int timesToRun = 100;
	int insertionStart = 25;
	int insertionStep = 10;
	int insertCurrent = insertionStart;
	vector<int> numbersToInsert;
	for (int i = 0; i < timesToRun; ++i) {
		numbersToInsert.push_back(insertCurrent);
		insertCurrent += insertionStep;
	}

	int step = 2;
	SkipList sl(100);
	for (int i = 0; i < maxNumber; i += step) {
		sl.insert(i);
	}

	cout << "Number of elements in list: " << maxNumber / step << endl;

	vector<double> avgInsertionTime;
	vector<double> avgSearchTime;
	vector<double> avgRemoveTime;
 
	for (int i = 0; i < timesToRun; ++i) {
		auto start = std::chrono::system_clock::now();
		sl.insert(numbersToInsert[i]);
		auto finish = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsedTime = finish - start;
		avgInsertionTime.push_back(elapsedTime.count());
	}

	cout << "Insertion of " << timesToRun << " times took an average of " << getAverage(avgInsertionTime) << " seconds." << endl;
	//sl.display();

	for (int i = 0; i < timesToRun; ++i) {
		auto start = std::chrono::system_clock::now();
		sl.search(numbersToInsert[i]);
		auto finish = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsedTime = finish - start;
		avgSearchTime.push_back(elapsedTime.count());
	}

	cout << "Searching of " << timesToRun << " times took an average of " << getAverage(avgSearchTime) << " seconds." << endl;

	for (int i = 0; i < timesToRun; ++i) {
		auto start = std::chrono::system_clock::now();
		sl.remove(numbersToInsert[i]);
		auto finish = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsedTime = finish - start;
		avgRemoveTime.push_back(elapsedTime.count());
	}

	cout << "Deletion of " << timesToRun << " times took an average of " << getAverage(avgRemoveTime) << " seconds." << endl;
	cin.get();

    return 0;
}

double getAverage(vector<double> v) {
	double sum = 0;
	for (int i = 0; i < v.size(); ++i) {
		sum += v[i];
	}

	return sum / v.size();

}