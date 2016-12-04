/*

Four kids sat in a circle like around a carrom board. Between them there is an image.
Each will get a chance to throw the coin which contains L, R

If coin shows L, The image is rotated anticlockwise direction i.e, -90 deg
If coin shows R, The image is rotated clockwise direction i.e, +90 deg

Input is the 2-D Array where each integer represents each pixel of an image,

All the coin throws are given in form of string like "LLRLLRRLR" (case insensitive)

How would the image look after applying all the rotations ?

Example: If the string is "LL",

Then after one rotation .

1	2	3				3	6	9
4	5	6    ---->			2	5	8
7	8	9				1	4	7

Another one left rotation

3	6	9				9	8	7
2	5	8	----->			6	5	4
1	4	7				3	2	1

So final answer after applying "LL" rotations is

1	2	3	  o/p			9	8	7
4	5	6    ---->			6	5	4
7	8	9				3	2	1

NOTES:
1. Dice throws is case insensitive ex: "lRrL"
2. Given 2-D array is square array.
3. Order of matrix can be < 500.
4. No need to return anything. Manipulate input array itself.
5. Len is the number of rows/cols of the 2d array.

Constraints :
0<=len<=500
0<=strlen(seq)<=500
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 500
void rotateArray(int **arr, int len, char *seq)
{
	if (len >= 0 && len <= 500 && strlen(seq) >= 0 && strlen(seq) <= 500)
	{
		for (int i = 0; i < strlen(seq); i++)
		{
			if (seq[i] == 'l' || seq[i] == 'L')
			{
				rotatel(arr);
			}
			if (seq[i] == 'r' || seq[i] == 'R')
			{
				rotater(arr);
			}
		}
	}
	
	else
	{
		printf("exception");
	}
	
}
void rotatel(int **mat)
{
	// Consider all squares one by one
	for (int x = 0; x < N / 2; x++)
	{
		// Consider elements in group of 4 in 
		// current square
		for (int y = x; y < N - x - 1; y++)
		{
			// store current cell in temp variable
			int temp = mat[x][y];

			// move values from right to top
			mat[x][y] = mat[y][N - 1 - x];

			// move values from bottom to right
			mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];

			// move values from left to bottom
			mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];

			// assign temp to left
			mat[N - 1 - y][x] = temp;
		}
	}
}
void rotater(int **mat)
{
	// Consider all squares one by one
	for (int x = 0; x < N / 2; x++)
	{
		// Consider elements in group of 4 in 
		// current square
		for (int y = x; y < N - x - 1; y++)
		{
			// store current cell in temp variable
			int temp = mat[x][y];

			// move values from right to top
			mat[x][y] = mat[N - 1 - y][x];

			// move values from bottom to right
			mat[N - 1 - y][x] = mat[N - 1 - x][N - 1 - y];

			// move values from left to bottom
			mat[N - 1 - x][N - 1 - y] = mat[y][N - 1 - x];

			// assign temp to left
			mat[N - 1 - y][x] = temp;
		}
	}
}