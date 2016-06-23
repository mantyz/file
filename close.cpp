#include <iostream>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int fd;
	if (argc < 2)
	{
		cerr << "Too few arguments" << endl;
		return 1;
	}

	fd = open (argv[1], O_WRONLY | O_CREAT | O_EXCL, 0644);
	if (fd == -1)
	{
		cerr << "Cannot create file (" << argv[1] << ")" << endl;
		return 2;
	}
	
	if (close (fd) == -1)
	{
		cerr << "Cannot close file with descriptor = " << fd << endl;
		return 3;
	}

	if (close (fd) == -1)
	{
		cerr << "Cannot close file with descriptor = " << fd << endl;
		return 4;
	}
	return 0;
}
