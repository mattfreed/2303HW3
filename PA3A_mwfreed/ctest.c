#include <stdio.h>
#include <string.h>
// string.h covers the C-style string functions.
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 * Add your own @author line below.
 * @author Matt Freed
 */

const int MAX_CHARS = 20; // Maximum number of characters in array

int main()
{
	char a1[MAX_CHARS + 1]; // Character array--initially empty
	char a2[] = "Hello"; // Character array--unsized but initialized
	char a3[MAX_CHARS + 1]; // Character array--we will underfill it
	char* p1 = "Hello"; // Pointer to constant string
	char* p2 = NULL;           // Will be a pointer to dynamically-allocated string
	char* p3 = "Hi"; // Pointer to another constant string
	int copy_limit;     // Maximum characters to copy.

	strcpy(a3, "Hello, one more time."); // Initialize underfilled character array

	/* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
	 */
	printf("Initial state:\n");
	printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
	printf("          p1 = %p p2 = %p\n", p1, p2);

	strcpy(a1, p3); // Initialize character array

	printf("a1 = %s\n", a1);
	printf("a2 = %s\n", a2);
	printf("a3 = %s\n", a3);

	// Note that strlen() returns size_t, which is typedef'd to
	//   unsigned long, so we need to print it with %ld instead of just %d.
	printf("For string /%s/, strlen() returns %ld\n", p1, strlen(p1));

//part 2

	printf("For string /%s/, mystrlen1() returns %ld\n", p1, mystrlen1(p1));
	printf("For string /%s/, mystrlen2() returns %ld\n", p1, mystrlen2(p1));

	// Duplicate a string, using strdup(), then print
	printf("\nBefore calling strdup(), pointer a2 = %p, contents = %s\n", a2, a2);
	p2 = strdup(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Duplicate a string, using my function, then print
	printf("\nBefore calling mystrdup1(), pointer a2 = %p, contents = %s\n", a2, a2);
	p2 = mystrdup1(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);


	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';

	// Concatenate two character arrays, then print.
	strcpy(a1, p3); // Reset character array
	strcat(a1, a2);
	printf("Using strcat() to concatenate a2 to the end of a1\n");
	printf("a1 = %s\n", a1);

	// Concatenate two character arrays safely, then print.
	strcpy(a1, p3); // Reset character array
	a1[MAX_CHARS] = 'A'; // Remove terminator, to prove strncat() puts it back in.
	copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
	printf("Using strncat() to concatenate to the end of a1, with copy_limit = %d\n",
			copy_limit);
	if (copy_limit > 0) strncat(a1, a3, copy_limit);
	printf("a1 = %s\n", a1);

//Part 3 and 4

	// Concatenate two character arrays, then print.
	mystrcpy(a1, p3); // Reset character array
	mystrcat(a1, a2);
	printf("Using mystrcpy and mystrcat() to concatenate a2 to the end of a1\n");
	printf("a1 = %s\n", a1);

	// Concatenate two character arrays safely, then print.
	mystrcpy(a1, p3); // Reset character array
	a1[MAX_CHARS] = 'A'; // Remove terminator, to prove strncat() puts it back in.
	copy_limit = MAX_CHARS - mystrlen1(a1); // How much space is left?
	printf("Using mystrncat() to concatenate to the end of a1, with copy_limit = %d\n",
			copy_limit);
	if (copy_limit > 0) mystrncat(a1, a3, copy_limit);
	printf("a1 = %s\n", a1);


//Part 5

	// Copy a string with a limit of 4, test mystrncpy()
		strncpy(a1, p1, 4); // copy p1 into a1 with 4 character limit using original strncpy
		printf("copy p1 into a1 with 4 character limit using original strncpy. print hell \n");
		printf("a1 = %s\n", a1);

		mystrncpy(a1, p1, 4); // copy p1 into a1 with 4 character limit using new mystrncpy
		printf("copy p1 into a1 with 4 character limit using new mystrncpy \n");
		printf("a1 = %s\n", a1);

		// Duplicate a string, using strndup(), then print. test against mystrndup with limit of 4
		printf("\nBefore calling strndup(), pointer a2 = %p, contents = %s\n", a2, a2);
		p2 = strndup(a2,4);
		printf("Duplicated string: \n");
		printf("Pointer p2 = %p, contents = %s\n", p2, p2);

		// Duplicate a string, using mystrndup(), then print
		printf("\nBefore calling mystrndup(), pointer a2 = %p, contents = %s\n", a2, a2);
		p2 = mystrndup(a2,4);
		printf("Duplicated string: \n");
		printf("Pointer p2 = %p, contents = %s\n", p2, p2);








	return 0;
}
