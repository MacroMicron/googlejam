// Cookie Cliker Alpha
// 8pt && 11pt
// correct answer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double C, F, X, t, pre_k;
long long k;

int main()
{
	int T, test_case;

	/*
	   If you remove the statement below, your program's output may not be rocorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		scanf("%lf %lf %lf", &C, &F, &X);
		pre_k = X/C - 1 - 2/F;
		k = pre_k>0 ? (long long)pre_k + 1 : 0;
		t = X/(F*k + 2);
		for (int i=0; i < k; i++)
			t+= C/(F*i + 2);
		printf("Case #%d: %.9lf\n", test_case+1, t);
	}

	return 0;//Your program should return 0 on normal termination.
}

