#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <fstream>

using std::cerr;
using std::endl;
using std::ofstream;

#define BUF_SIZE 4096
char buffer[BUF_SIZE];

int main(int argc, char const *argv[])
{
	ssize_t bytes;
	int ifd, i;
	ofstream outfile;
	if (argc < 3)
	{
		cerr << "Too few arguments" << endl;
		return 1;
	}

	ifd = open (argv[1], O_RDONLY);
	if (ifd == -1)
	{
		cerr << "Cannot open file (" << argv[1] << ")" << endl;
		return 1;
	}

	outfile.open(argv[2]);
		if(!outfile.is_open())
		{
			cerr << "Cannot open file (" << argv[2] << ")" << endl;
			return 1;
		}

	while ((bytes = read (ifd, buffer, BUF_SIZE)) > 0)
	{
		for (i = 0; i < bytes; i++)
		{
			outfile << buffer[i];
		}
	}

	if (close (ifd) == -1)
	{
		cerr << "Cannot close file with descriptor = " << ifd << endl;
		return 1;
	}
	outfile.close();

	return 0; //iss53 iss53_2
}
