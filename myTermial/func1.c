#include"myheader.h"
void getpromt(char* usid){
 	char hostname[500];
	char cwd[PATH_MAX];
	gethostname(hostname, 500);
	char *temp =getlogin();		
	strcpy(usid, temp);
	strcat(usid,"@");
	strcat(usid, hostname);
	getcwd(cwd, sizeof(cwd));
	strcat(usid, " :~");
	strcat(usid, cwd);
	strcat(usid, "$ ");
}
