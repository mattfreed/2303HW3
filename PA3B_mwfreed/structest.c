#include <stdio.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {
	struct Employee *e;//struct initializations
	struct Employee *d;
	struct Employee *f;

	//struct creations part 2
	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	d = makeEmployee(1900, 2000, "D");
	f = makeEmployee(1500, 1600, "f");

	printEmployee(e);
	printEmployee(d);
	printEmployee(f);

	//part 3
	printf("random number between 0-2018: %d\n",randStart());
	printf("random number between 0-2018: %d\n",randStart());
	printf("random number between 0-2018: %d\n",randStart());


	printf("random char: %c\n",randChar());
	printf("random char: %c\n",randChar());
	printf("random char: %c\n",randChar());

	printf("random string: %s\n",randString(11));
	printf("random string: %d\n",'a');
	printf("random string: %d\n",'z');

	//part 4
	struct Employee** a1=employeePointers(5);
	printEmployees(a1, 5);

	//part5
	struct Employee** a2 =arrayCopy(a1,5);
	printEmployees(a2, 5);

	//part 6
	freeAll(a1,5);
	freeAll(a2,5);
	return 0;
}
