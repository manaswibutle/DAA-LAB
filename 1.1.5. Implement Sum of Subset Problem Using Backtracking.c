#include <stdio.h>

int a[25], subset[25];
int n, sum;
int ans[1000][25];
int len[1000] ;
int cnt = 0 ;

void backtrack(int index, int currentSum, int k) {
if (currentSum == sum) {
	len[cnt] = k;
	for (int i = 0; i < k; i++)
		ans[cnt][i] = subset[i];
	cnt++;
	return;
}

	if (index == n || currentSum > sum)
		return;
	subset[k] = a[index];
	backtrack(index + 1, currentSum + a[index], k + 1);
	backtrack(index + 1, currentSum, k);
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	scanf("%d", &sum);

	backtrack(0, 0, 0);

if (cnt == 0) {
	printf("-1");
} else {
	for (int i = cnt - 1; i >= 0; i--) {
		for (int j = 0; j < len[i]; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
}
	return 0;
}
