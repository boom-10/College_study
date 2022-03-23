#include<stdio.h>
#include<string>
#include<malloc.h>
void prefix_table(char *pattern, int *prefix, int n) {
	prefix[0] = 0;
	int i = 1;
	int len = 0;
	while (i < n) {
		if (pattern[i] == pattern[len]) {
			len++;
			prefix[i] = len;
			i++;
		}
		else {
			if (len > 0) {
				len = prefix[len - 1];
			}
			else {
				prefix[i] = 0;
				i++;
			}
		}
	}
}
void move_prefix_table(int *prefix, int n) {
	for (int i = n-1; i >0 ; i--)
	{
		prefix[i] = prefix[i - 1];
	}
	prefix[0] = -1;
}
void kmp_search(char* text, char* pattern, int* prefix,  int m, int n) {
	int j = 0;
	int i = 0;
	int count = 0;
	while (j<m)
	{
		if (i == n - 1 && text[j] == pattern[i]) {
			printf("查找成功！第%d次出现的位置为：%d\n", ++count, j - i);
			i = prefix[i];
		}
		if (text[j] == pattern[i]) {
			j++;
			i++;
		}
		else
		{
			i = prefix[i];
			if (i == -1) {
				i++;
				j++;
			}
		}
	}
}
void main() {
	int prefix[3];
	char pattern[] = "aba";
	char text[] = "ababababcabaab";
	int n = strlen(pattern);
	int m = strlen(text);
	prefix_table(pattern, prefix, n);
	move_prefix_table(prefix, n);
	kmp_search(text, pattern, prefix, m, n);
}