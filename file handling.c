#include <stdio.h>
main()
{
	FILE *fp,*fp1;
	int i=0,k;
	char ch,str[50];
	
	fp=fopen("newfile.txt","w");
	printf("Input to the reverse function : ");
	gets(str);
	fputs(str,fp);
	fclose(fp);
	
	fp=fopen("newfile.txt","r");
	fp1=fopen("output.txt","w");
	if(fp==NULL)
	{
		printf("The file does not exist.\n");	
	}
	fseek(fp,0,SEEK_END);
	k=ftell(fp);
	printf("Output : ");
	while(i<k)
	{
		i++;
		fseek(fp,-i,SEEK_END);
		ch=fgetc(fp);
		printf("%c",ch);
		putc(ch,fp1);
	}
	fclose(fp);
	fclose(fp1);
}
