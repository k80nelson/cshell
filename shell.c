#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

#define BUFFER_SIZE = 1<<16
#define ARR_SIZE = 1<<16

int main(int argc, char** argv, char** envp){
    char* user = getenv("USER");
    strcat(user, " $ ");
    while(1){
        char* line = readline(user);
        if (strlen(line)>0) add_history(line);
	else continue;

        if (!strcmp(line, "exit")) exit(0);

    }
    return 0;
}
