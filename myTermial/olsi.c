#include"myheader.h"

int isDir(const char* );

int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}
void olsi(char * source_file,char* dest_file)
{
	//printf("hgffgfyhgvjh\n");
	FILE *source, *destination;
	//char source_file[100], dest_file[100];
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
		
	}	
	int a=0;
	if(exists(dest_file)==1)
	{
		char x;
		printf("cp: overwrite \'%s\'?\n",dest_file);
		scanf("%c" , &x);
		while(getchar() != '\n');
		if((x=='y')||(x=='Y'))
		{
			destination = fopen(dest_file, "wb");
			if(destination== NULL)
			{
			fclose(source);
			exit(0);
			}
			while((read_count = fread(buffer, 1, sizeof(buffer), source))>0)
			{
				fwrite(buffer, 1, read_count, destination);
			}
			fclose(destination);
		}
		else{	
		}
	}
	else{
			destination = fopen(dest_file, "wb");
			if(destination== NULL)
			{
			fclose(source);
			exit(0);
			}
			while((read_count = fread(buffer, 1, sizeof(buffer), source))>0)
			{
				fwrite(buffer, 1, read_count, destination);
			}
			fclose(destination);
	}
	fclose(source);
	//fclose(destination);
	//return 0;


}

