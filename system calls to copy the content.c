#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *ftpr1,*ftpr2;
	char filename[100],c;
	printf("Enter the filename to open for reading \n");
	scanf("%s",filename);
	fptr1 = fopen(filename,"r");
	if (ftpr1 == NULL)
	{
		printf("Cannot open file %s \n",filename);
		exit (0);
	}
	printf("Enter the filename to open for writing \n");
	scanf("%s",filename);
	ftpr2 = fopen(filename,"w");
	if (ftpr2 == NULL)
	{
		printf("Cannot open file %s \n",filename);
		exit (0);
	}
	c = fgetc(ftpr1);
	while (c!=EOF)
	{
		fputc(c,ftpr2);
		c = fgetc(ftpr1);
	}
	printf("\n Contents copied to %s",filename);
	fclose(fptr1);
	fclose(fptr2);
}
