# 2303HW3
HW3 for CS2303 Systems Programming

Matthew Freed
Assignment 3


Program Summary:
	Part A: This program recreates standard library functions, such as copying strings or concatenating them.
	
Running the Program:
	Eclipse: import into Eclipse. Build project. Run as a c/c++ 
	Terminal: build the code using the 'make' command
	
	
Problems encountered:
	
	None

Loop Invariants:
	mystrncat():
		 i>=0, i<n
   
   
 Program Summary:

Part B: This program contains many functions for creating and printing structs of type epmployees. Functions created include: generating a random struct of type employee, creating an array of random struct employees, creating random strings and characters, etc.
	
Running the Program:
	Eclipse: import into Eclipse. Build project. Run as a c/c++ 
	Terminal: build the code using the 'make' command
	
Problems encountered:
	
	None

Loop Invariants:
	randString():
		i>=0, i<length, string[i] = randChar()
	employeePointers():
		i>=0, i<pointeramount
	printEmployees():
		i>=0, i<count
	arraycopy():
		i>=0, i< count
	freeAll():
		i>=0, i<count
