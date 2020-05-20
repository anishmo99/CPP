#include <iostream>
#include <cstdio>
using namespace std; 

/* Swaps strings by swapping pointers */
void swap1(char **str1_ptr, char **str2_ptr) 
{ 
char *temp = *str1_ptr; 
*str1_ptr = *str2_ptr; 
*str2_ptr = temp; 
} 

int main() 
{ 
char *str1 = "geeks"; 
char *str2 = "forgeeks"; 
swap1(&str1, &str2); 
cout<<str1<<endl<<str2;
return 0; 
} 
