#include <stdio.h>
	
void main(void)
{
	char in1[80], in2[80], in3[80], in4[80];
	int length1, length2, length3;
	int i1, i3, j1, wk;
	int i2 = 0;
	
	gets(in1);
	gets(in2);
	gets(in3);
	
	length1 = strlen(in1);
	length2 = strlen(in2);
	length3 = strlen(in3);
	
	strcpy(in4, in1);
	
	for(i1 = 0; i1 < length1; i1++) {
		if(in4[i1] == in2[i2]) {
			for(i2 = 1; i2 < length2; i2++) {
				if(in4[i1+i2] != in2[i2]) {
					break;
				}
			}
			if(length2 == i2) {
				if(length2 == length3) {
					for(i3 = 0; in3[i3]; i3++) {
						in4[i1+i3] = in3[i3];
					}
				} else if(length2 < length3) {
					wk = length3 - length2;
					// in4[] �� wk ���v�f�����ɂ��炷
					for(j1 = length1; j1 > i1; j1--) {
						in4[j1+wk] = in4[j1];
					}
					// ���炵����͒u��
					for(i3 = 0; in3[i3]; i3++) {
						in4[i1+i3] = in3[i3];
					}
					// ���炵���̂ŗv�f���X�V
					length1 = strlen(in4);
				} else {
					wk = length2 - length3;
					// in4[] �� wk ���v�f��O�ɂ��炷
					for(j1 = i1; in4[j1]; j1++) {
						in4[j1] = in4[j1+1];
					}
					// ���炵����͒u��
					for(i3 = 0; in3[i3]; i3++) {
						in4[i1+i3] = in3[i3];
					}
					// ���炵���̂ŗv�f���X�V
					length1 = strlen(in4);
				}
			}
		}
		i2 = 0;
	}
	
	printf("���͕�����     : %s\n", in1);
	printf("�u���Ώە����� : %s\n", in2);
	printf("�u��������     : %s\n", in3);
	printf("�u���㕶����   : %s\n", in4);
}