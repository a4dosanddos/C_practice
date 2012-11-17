#include <stdio.h>
#include <sys/types.h>
#include <windows.h>

void thread1(void)
{
	int i;
	
	for(i = 1; i <= 30; i++) {
		Sleep(1);
		printf("%d", i);
	}
}

void thread2(void)
{
	char c[] = "abcdefghijklmnopqrstuvwxyz";
	int i;
	
	for(i = 0; c[i]; i++) {
		Sleep(1);
		printf("%c", c[i]);
	}
}

void main(void)
{
	HANDLE t1, t2;
	
	t1 = (HANDLE)_beginthread(thread1, 0, NULL);
	t2 = (HANDLE)_beginthread(thread2, 0, NULL);
	
	WaitForSingleObject(t1, INFINITE);
	WaitForSingleObject(t2, INFINITE);
}