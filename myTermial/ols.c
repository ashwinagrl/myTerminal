#include"myheader.h"

int isDir(const char* );


void ols(char * source_file,char* dest_file)
{
	
	FILE *source, *destination;
	int read_count;
	unsigned char buffer[1024];

	
	
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
	destination = fopen(dest_file, "wb");
	if(destination == NULL)
	{
		strcat(dest_file,"/");
		strcat(dest_file,source_file);
		destination = fopen(dest_file, "wb");
		if(destination== NULL)
		{
		fclose(source);
		
		exit(0);
		
		}
	}
	while((read_count = fread(buffer, 1, sizeof(buffer), source))>0)
	{
		fwrite(buffer, 1, read_count, destination);
	}
	fclose(source);
	fclose(destination);

	


}

