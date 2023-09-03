#include"myheader.h"

int isDir(const char* );


void olsn(char * source_file,char* dest_file)
{
	//printf("hgffgfyhgvjh\n");
	FILE *source, *destination;
	//char source_file[100], dest_file[100];
	int read_count;
	unsigned char buffer[1024];

	///scanf("%s", source_file);
	//scanf("%s", dest_file);
	
	source = fopen(source_file,"rb");
	if(source== NULL)
	{
		printf("invalid source file\n");
		exit(0);
	}
	if(isDir(source_file)==0)
	{
	printf("this is a directory use -r option\n");
	exit(0);
	}
	int a=0;
	if((destination=fopen(dest_file,"rb"))==NULL)
	{
		fclose(destination);
		a=1;
		
	}
	if(a==0)
	{
	destination = fopen(dest_file, "wb");
	if(destination == NULL)
	{
		strcat(dest_file,"/");
		strcat(dest_file,source_file);
		destination = fopen(dest_file, "wb");
		if(destination== NULL)
		{
		fclose(source);
		//printf("abc\n");
		exit(0);
		//return 0;
		}
	}
	while((read_count = fread(buffer, 1, sizeof(buffer), source))>0)
	{
		fwrite(buffer, 1, read_count, destination);
	}
	fclose(source);
	fclose(destination);
	}
	//return 0;


}

