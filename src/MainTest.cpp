/*
Mock Test 2
Make Sure you submit well before time .
And dont repeteadtly submit ,as it will cause sync issues , Try to submit alteast with
5-10mins gap between each submit .
Make sure your files are uploaded to GoogleDrive before Time Expires.

95% of times ,The last minute Code changes wont fetch you any more marks .It might even
decrease or become 0 , If it leads to a Project Build Failure .
*/

#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeaders.h"

int main(){
	char *name = (char *)malloc(100*sizeof(char));
    name="Manoj iammanoj@gmail.com";
	int validmail = isValidEmail(name);
	int **arr = (int**)malloc(2*sizeof(int*));
	for (int i = 0; i < 2; i++)
	{
		arr[i] = (int*)malloc(2*sizeof(int));
		for (int j = 0; j < 2; j++)
			arr[i][j] = i * 2 + j + 1;
	}

	rotateArray(arr, 2, "LRR");
}