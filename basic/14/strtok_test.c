#include <stdio.h>
#include <sys/types.h>
#include <windows.h>

//bool flg = 0;

void thread1(void)
{
	char s[80] = "Hello,World,!";
	char *p;
	p = strtok(s, ",");
	printf("%s\n", p);
	Sleep(2000);
	p = strtok(NULL, ",");
	printf("%s\n", p);

}

void thread2(void)
{
	char s[80] = "Good,Morning,!";
	char *p;
	p = strtok(s, ",");
	printf("%s\n", p);
	Sleep(5000);
}

void main(void)
{
	HANDLE t1, t2;
	
	t1 = (HANDLE)_beginthread(thread1, 0, NULL);
	Sleep(1000);
	t2 = (HANDLE)_beginthread(thread2, 0, NULL);
	
	WaitForSingleObject(t1, INFINITE);
	WaitForSingleObject(t2, INFINITE);
}