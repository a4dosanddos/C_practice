#include <stdio.h>

int func(const void * a, const void * b);

void main(void)
{
	// ポインタ配列の宣言
	// fruit[0] は、"orange" の先頭アドレスとなる
	char *fruit[] = {"orange", "apple", "melon", "mango", "pineapple", "strawberry", "peach", "kiwi", "pear", "cherry"};
	int length;
	int i;

	length = sizeof fruit / sizeof fruit[0];

	// ポインタのサイズは 4 バイト ( ただし、処理系に依存する )
	qsort(fruit, length, sizeof(char *), func);

	for(i = 0; i < length; i++) {
		printf("%s ", fruit[i]);
	}
}

int func(const void * a, const void * b)
{
	// ** ポインタを指すポインタ
	return strcmp( * (char **) a, * (char **) b);
}