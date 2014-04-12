// Magic Trick
// 6pt
// correct answer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _array {
	int data[16];
	int length;
} array;

const array nullarray = {{},0};

array newarray(int *p, int n)
{
	array result = {{},0};
	for (int i=0; i < n; i++)
		result.data[result.length++] = p[i];
	return result;
}

// return array or const array ?
array intersect(array a, array b)
{
	array intersect = {{},0};
	for (int i=0; i < a.length; i++)
		for (int j=0; j <b.length; j++)
		{
			if (a.data[i] == b.data[j]) 
			{
				intersect.data[intersect.length++] = a.data[i];
				break;
			}
		}
	return intersect;
}

// read grid 4x4
void read_grid16(int grid[][4])
{
	int i,j;
	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
			scanf("%d", &grid[i][j]);
}

array first, second, result;
int main()
{
	int T, test_case;
	int right_line, grid[4][4];
//	array first = nullarray, second = nullarray;//, result = nullarray;
	

	/*
	   If you remove the statement below, your program's output may not be rocorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		scanf("%d", &right_line);
		read_grid16(grid);
		first = newarray(grid[right_line-1], 4);
   
	        scanf("%d", &right_line);
                read_grid16(grid);
                second = newarray(grid[right_line-1], 4);

		result = intersect(first, second);
		if (result.length > 1) printf("Case #%d: Bad magician!\n", test_case+1);
		else if (result.length == 0) printf("Case #%d: Volunteer cheated!\n", test_case+1);
		else printf("Case #%d: %d\n", test_case+1, result.data[0]);
	}

	return 0;//Your program should return 0 on normal termination.
}

