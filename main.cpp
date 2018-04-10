#include "SkipList.h"
#include <time.h>
using namespace std;

int main()
{
	srand((unsigned)time(0));
	int end;

	SkipList list(1000,0.3);

	for (int i = 0; i < 100; i++)
	{
		list.insert((int)rand());
	}

	//list.printList();
	cin >> end;


}