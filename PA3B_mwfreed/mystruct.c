/** mystruct.c
 * @author Mike Ciaraldi
 * edited by Matt Freed
*/


#include <string.h>
#include <stdlib.h>
#include "mystruct.h"
#include <stdio.h>

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the emploee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {
	struct Employee *e = (struct Employee*) malloc(sizeof(struct Employee));//allocates memory for struct of type employee
	e->birth_year=birth;//sets the struct parameter birth year = birth
	e->start_year=start; // sets the struct parameter start year = start
	strcpy((e->name),name); //sets the struct parameter name = name

	return e; // Replace this with a pointer to the allocated struct
}

/** prints the information of the Employee given the struct
 *@param struct Employee *e the employee struct being passed in

 */
void printEmployee(struct Employee *e) {
	printf("Birth Year: %d\n", e->birth_year); //prints the birth year
	printf("Start Year: %d\n", e->start_year ); //prints the start year
	printf("Name: %s\n", e->name); //prints the string name
}
/** creates random number between 0-2019
 *@return r random number between 0-2010
 */
int randStart(){
	int r = rand()%2019;//random number between 0-2019
	return r;
}
/** creates random birth year, taking in a max year for when someone could be born
 *@param max year The maximum year someone could be born
 *@return return the random birth year
 */
int randBirth(int maxYear){
	int r = rand()%maxYear;//random number between 0-2019
	return r;
}
/** creates random character between a-z
 *@return c the random character
 */
char randChar(){
	int c=0;// initialize the letter
	while(c<97){//loop through numbers 0-122, any number between 97-122 is an a-z character get out of loop if you achieve one of these characters.
		c =rand()%123;//random number between 0-122
	}
	return c;
}

/** creates random character array
 *@param length the length of the string you wish to create
 *@return string the character string
 */
char* randString(int length){

	int totalLength=length+1;//total length of the string to include the null terminator
	int i;//initial count
	char *string = (char*) malloc(sizeof(char)*totalLength);//allocate the required memory for the string
	if (string == 0) return (char *) 0;  // If no memory was available, return null pointer immediately

	for(i=0;i<length; i++){//populate the string with random charaters
		string[i]=randChar();
	}
	//loop invariants: i>=0, i<length, string[i] = randChar();
	string[length] = '\0';// sets last part of string memory to null terminator
	return string;
}
/** creates random employee
 *@return a randomly filled struct of type Employee
 */
struct Employee* randomEmployee(){
	struct Employee *e = (struct Employee*) malloc(sizeof(struct Employee));//allocate memory for the struct
	int start = randStart();// set the start value to a random value
	e->birth_year=randBirth(start);//set the birth year = a random year = or < the start year
	e->start_year=start;//sets start year
	strcpy((e->name),randString(10));// copy the random character array name into the struct

	return e; // Replace this with a pointer to the allocated struct
}
/** creates random Array of pinters for struct Employees
 *@param pointerAmount the amount of pointers the array should hold
 *@return Array of pointers to structs of type Employee
 */
struct Employee** employeePointers(int pointerAmount){
	struct Employee** arrayPointers = malloc(sizeof(struct Employee)*pointerAmount);// allocate memory for the 2d array
	for (int i=0;i<pointerAmount;i++){// loop through the amount of pointers requested, adding the pointer of the random employee to the new array
		arrayPointers[i]=randomEmployee();
	}
	//loop invariant: i>=0, i<pointeramount;
	return arrayPointers;
}
/** prints the list of employees
 *@param e takes the array of employees
 *@param count takes the amount of employees in the array
 */
void printEmployees(struct Employee** e, int count){
	for(int i=0;i<count;i++){//loop through the array of employees and print the employees information
		printf("employee %d: \n",i+1);//print the employee number
		printEmployee(e[i]);//print the employee
	}
	//loop invariants: i>=0, i<count
}
/** copies the array of pointers to struct employees to a new array
 *@param e array of pointerse to struct employee
 *@param count the amount of employees to copy
 *@return new array
 */
struct Employee** arrayCopy(struct Employee** e,int count){
	struct Employee** new= malloc(sizeof(struct Employee)*count);//allocates mempry for a new array
	for (int i = 0; i<count; i++){//copies the old array into the new array until it reaches count
		new[i]=e[i];
	}
	//loop invariants: i>=0, i< count
	return new;
}
/** frees all unnecesarry memory allocations
 *@param e array of pointers to struct employees
 *@param count amount of employees to deallocation
 */
void freeAll(struct Employee** e,int count){
	for(int i=0;i<count;i++){//loops through the array of employees, checking if they are null
		if(e[i]!=NULL){//if employee is not null, free it
			free(e[i]);
		}
	}
	//loop invariant: i>=0, i<count
}
