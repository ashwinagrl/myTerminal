#include "myheader.h"

void getpromt(char *);

void call_ls(char *, char *, char *);
void call_cp_mv(char *inputarr1[]);
void call_grep(char *inputarr1[]);
void call_ps(char *inputarr1[]);

int ops();
int opsa();
int opsd();
int opse();
int opsf();

int main()
{

	// for path name
	while (1)
	{
		char usid[100];
		char *input = (char *)malloc(500 * sizeof(char));
		getpromt(usid);
		input = readline(usid);
		add_history(input);

		if (strcmp(input, "exit") == 0)
		{
			break;
		}

		char *inputarr[200];
		for (int noi = 0; noi < 200; noi++)
		{
			inputarr[noi] = NULL;
		}
		char *a;
		int i = 0;
		a = strtok(input, " ");

		while (a != NULL)
		{
			inputarr[i] = a;
			i++;
			a = strtok(NULL, " ");
		}

		if (inputarr[0] != NULL)
		{
			call_ls(inputarr[0], inputarr[1], inputarr[2]);

			call_cp_mv(inputarr);

			call_grep(inputarr);

			call_ps(inputarr);
		}
	}
	printf("Shell Terminated\n");

	return 0;
}
