#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	struct stat sb;

	i = stat(av[1], &sb);
	if (i != 0)
	{
		printf("file or directory does not exist\n");
		return 0;
	}
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
	{
		printf("this is a directory\n");
		return 0;
	}
	else if ((sb.st_mode & S_IFMT) == S_IFREG)
		printf("this is a regular file\n");
	if (sb.st_mode & S_IXUSR) 
	{
		printf("this is an executable file\n");
		if (access(av[1], X_OK) < 0);
			printf("this is an executable file\n");
	}	 
	else
		printf("permission denied\n");
	return 0;
}