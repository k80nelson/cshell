#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

#define BUFFER_SIZE 1<<16
#define ARR_SIZE 1<<16

void parse_args(char* buff, char** args, 
		size_t args_len, size_t *nargs)
{
    char* buffer[args_len];
    char** ptr;
    char* input;
    size_t i, j;

    input = buff;
    buffer[0] = buff;
    args[0] = buff;

    for (ptr=buffer; (*ptr=strsep(&input, " \n\t"))!=NULL;){
	if ((*ptr != '\0') && (++ptr >= &buffer[args_len]))
	    break;
    }

    for (j=i=0; buffer[i]!=NULL; i++){
        if(strlen(buffer[i])>0)
	    args[j++] = buffer[i];
    }
    *nargs=j;
    args[j]=NULL;
}

static void handler(int signum){
    while(waitpid((pid_t)(-1), 0, WNOHANG) > 0){} 
}

int main(int argc, char** argv, char** envp){
    char* user = getenv("USER");
    strcat(user, " $ ");

    char* args[ARR_SIZE];
    size_t nargs;
    
    while(1){
        char* line = readline(user);
	parse_args(line, args, ARR_SIZE, &nargs);
        if (nargs>0) add_history(line);
	else continue;
        if (!strcmp(args[0], "exit")) exit(0);
    }
    return 0;
}
