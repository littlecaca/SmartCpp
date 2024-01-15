#include <stdio.h>

int main(int argc, char const *argv[])
{
	/*
		Ctrl + D on terminal in Unix-like OS
	 
	 	A program like cat reads from its standard input like this:
	
	 		n = read(0, buffer, 512);
	 	
	 	which asks for 512 bytes. n is the number of bytes actually read, or -1 if there's an error.
		If you did this repeatedly with an ordinary file, you'd get a bunch of 512-byte reads, 
		then a somewhat shorter read at the tail end of the file, then 0 if you tried to read past 
		the end of the file. So, cat will run until n is <= 0.
	 	
	 	Ctrl+D (despite being called the eof character) doesn't actually mean end-of-file: 
	 	it means “send the pending input to the application now”. This is actually close to the
	 	meaning of Ctrl+M (eol), which sends the pending input plus a newline. When you press 
	 	Ctrl+D immediately after a Ctrl+M (i.e. at the beginning of a line) or after another Ctrl+D,
	 	the pending input is empty. Thus the application receives 0 bytes of input. In a read call, 
	 	reading 0 bytes signals the end of the file.
	 */
	int i1, i2;

	int r1 = scanf("%d", &i1);
	int r2 = scanf("%d", &i2);

	printf("success\n");

	return 0;
}