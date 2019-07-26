#include <iostream>
#include <cstdio>

using namespace std;

#include "Person.h"

int main()
{
	Person p1;
	p1.SetPerson((char*)"홍길동",20,true);
	p1.ShowPerson();

	return 0;
}

