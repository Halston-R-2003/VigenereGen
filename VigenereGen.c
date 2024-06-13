#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORD_LEN 100

void generate_vigenere_table(char table[][26], const char* keyword)
{
	int len = strlen(keyword);

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			table[i][j] = (char)(((toupper(keyword[i]) - 'A' + j) % 26) + 'A');
		}
	}
}

void print_vigenere_table(char table[][26], const char* keyword)
{
	// Print head
	printf("    ");

	for (char c = 'A'; c <= 'Z'; c++)
		printf("%c ", c);

	printf("\n");

	for (int i = 0; i < 4 + 2 * 26; i++)
		printf("-");

	printf("\n");

	// Print rows
	int len = strlen(keyword);

	for (int i = 0; i < len; i++)
	{
		printf("%c | ", toupper(keyword[i]));

		for (int j = 0; j < 26; j++)
			printf("%c ", table[i][j]);

		printf("\n");
	}
}

int main()
{
	char keyword[MAX_KEYWORD_LEN];
	char table[MAX_KEYWORD_LEN][26];

	printf("Enter Keyword: ");
	scanf("%s", keyword);

	generate_vigenere_table(table, keyword);
	print_vigenere_table(table, keyword);

	return 0;
}
