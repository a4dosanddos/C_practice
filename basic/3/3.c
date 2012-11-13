#include <stdio.h>
#define ENTER 13
#define BS 8

void main(void)
{
	char c[80];
	int result;
	int i = 0;
	int i2;
	//result = getch();
	//printf("%d",result);
	//return;
	
	memset(c, 0, 80);
	
	while((result=getch()) != ENTER) {
		if(result == BS) {
		    printf("\r");
		    for(i2=0;i2<i;i2++) {
		       printf(" "); 
		    }
			c[--i] = '\0';
		} else {
		  c[i++] = result;
		}
		printf("\r");		
		for(i2=0;i2<i;i2++) {
		   printf("*"); 
		}
	}
	printf("%s",c);
}
