#include <stdio.h>

int func(const void * a, const void * b);

void main(void)
{
	// �|�C���^�z��̐錾
	// fruit[0] �́A"orange" �̐擪�A�h���X�ƂȂ�
	char *fruit[] = {"orange", "apple", "melon", "mango", "pineapple", "strawberry", "peach", "kiwi", "pear", "cherry"};
	int length;
	int i;

	length = sizeof fruit / sizeof fruit[0];

	// �|�C���^�̃T�C�Y�� 4 �o�C�g ( �������A�����n�Ɉˑ����� )
	qsort(fruit, length, sizeof(char *), func);

	for(i = 0; i < length; i++) {
		printf("%s ", fruit[i]);
	}
}

int func(const void * a, const void * b)
{
	// ** �|�C���^���w���|�C���^
	return strcmp( * (char **) a, * (char **) b);
}