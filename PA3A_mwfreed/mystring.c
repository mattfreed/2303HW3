/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
 * Edited by Matt Freed
 *
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup1(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen1(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup2(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen2(src) + 1;  // Leave space  the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/** Determines the length of a given string. Increments using array indexes.
 @param const char *s takes a pointer to the wanted string length
 @return the number of characters excluding null-terminator in the array
*/
size_t mystrlen1 (const char *s){
	size_t length = 0;// initialize size to 0
	int i = 0;//set the count = 0
	while(s[i]!='\0'){//while the null terminator has not been reached, increase the length by 1
		length++;
		i++;
	}
	return length;
}
/** Determines the length of a given string. Increments using pointers.
 @param const char *s takes a pointer to the wanted string length
 @return the number of characters excluding null-terminator in the array
*/
size_t mystrlen2 (const char *s){
	size_t length = 0;//sets size of string to 0
	while(*s !='\0'){//while the null terminator has not been reached, increase the size of length by 1 per loop
		length++;
		s++;//increase pointer by 1 position
	}
	return length;
}
/** Copies a given string to a new string
 @param dest The destination array for the given string
 @param src The src array containing the string to get copied
 @return the copied array
*/
char *mystrcpy (char *restrict dest, const char *restrict src){
	char *cpy = dest;//creates pointer to array
	while(*src){
		*dest++ = *src++;//add the value in src to the same position in dest
	}
	*dest = 0;//reset dest to position 0
	return cpy;
}
/** Concatenates 2 strings together
 @param dest The string being added to
 @param src The string getting added
 @return the concatenated string
*/
char *mystrcat (char *restrict dest, const char *restrict src){
	int i = mystrlen1(dest);// get the string length of char array dest
	int j;//initialize j to use as the position to add to the end of dest

	for (j=0;src[j]!='\0'; j++){// for posiion 0 of the source array, loop through until it reaches the null  terminator
		dest[i+j]=src[j];//add that posional character to the position of the allocated new array
	}
	//loop invariant: j<strlen(src)

	dest[i+j]='\0';//add the null terminator to the end of the string
	return dest;
}
/** Concatenates 2 strings together.  It will use at most n bytes from src and
 *src does not need to be null-terminated if it  contains  n  or  more bytes.
 *
 @param dest The string being added to
 @param src The string getting added
 @param n the amount of bytes from src
 @return the concatenated string
*/
char *mystrncat (char *restrict dest, const char *restrict src, size_t n){
	size_t dest_len = mystrlen1(dest);// finds the size of dest and sets it to a variable
	size_t i;//initializes i to be used as a counter

	for (i = 0 ; i < n && src[i] != '\0' ; i++){//loop through src, adding characters up to position n in src to dest
		dest[dest_len + i] = src[i];
	}
	//loop invariants: i>=0, i<n
	dest[dest_len + i] = '\0';//set the last position to the null terminator

	return dest;

}
/** Copies a given string to a new string, limiting the amount of the string it copies to n length
 @param dest The string being added to
 @param src The string getting added
 @param the amount of bytes from src
 @return the concatenated string
*/
char *mystrncpy (char *restrict dest, const char *restrict src, size_t n){
	char *cpy = dest;//creates pointer to array
	int i=0;//initialize the position count to 0
	while(*src&&i<n){//while the array src is not at the null terminator position, or is not at the nth position, add src value to dest position
		*dest++ = *src++;//add the src value to the corresponding dest position
		i++;
	}

	return cpy;
}
/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @param n the amount of bytes from src
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrndup(const char* src,  size_t n) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = n + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // cast new string

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  mystrncpy(newstr, src, n);
  return newstr;
}

