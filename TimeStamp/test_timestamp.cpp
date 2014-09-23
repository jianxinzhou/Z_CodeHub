#include "Timestamp.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Timestamp now = Timestamp::now();

	cout << now.toString() << endl;
	cout << now.toFormatString() << endl;
	return 0;
}
