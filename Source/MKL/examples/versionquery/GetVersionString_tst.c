#include<stdio.h>

void main(void)	{
   int len=80;
   char buf[80];
   MKLGetVersionString(buf, len);
   printf("%s\n",buf);
   printf("\n");
   return;
}