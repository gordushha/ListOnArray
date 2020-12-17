#include "List.h"

int main()
{
	List<int> A(5);
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);

	cout << A << endl;
}