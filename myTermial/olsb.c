#include"myheader.h"

int isDir(const char* );

int exists(const char *);
void olsb(char * source_file,char* dest_file)
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
		
	}	
	int a=0;
	if(exists(dest_file)==1)
	{
            char aux[150];
            strcpy(aux,dest_file);
            strcat(aux,"~");
            FILE* backup;
            backup = fopen(aux,"wb");
			destination = fopen(dest_file, "rb");
			if(destination== NULL)
			{
			fclose(source);
            fclose(backup);
			exit(0);
			}
			while((read_count = fread(buffer, 1, sizeof(buffer), destination))>0)
			{
				fwrite(buffer, 1, read_count, backup);
			}
			fclose(destination);
            destination = fopen(dest_file,"wb");
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
	

}

