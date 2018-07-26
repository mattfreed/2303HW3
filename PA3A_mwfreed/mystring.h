/** mystring.h
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

// Function prototype(s):
char* mystrdup1(const char* src);
size_t mystrlen1 (const char *s);
size_t mystrlen2 (const char *s);
char *mystrcpy (char *restrict dest, const char *restrict src);
char *mystrcat (char *__restrict __dest, const char *__restrict __src);
char *mystrncat (char *restrict dest, const char *restrict src, size_t n);
char *mystrncpy (char *restrict dest, const char *restrict src, size_t n);
char* mystrndup(const char* src, size_t n);
