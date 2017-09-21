shell: shell.c 
	gcc -Wall -o shell.exe shell.c -L/usr/local/lib -I/usr/local/include -lreadline
