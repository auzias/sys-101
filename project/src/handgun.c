/*
** handgun.c for handgun in /home/vincent/Documents/TP_bash/c/zombie
** 
** Made by Vincent Davoust
** <vincent.davoust@gmail.com>
** 
** Started on  Thu Mar 17 09:31:44 2016 Vincent Davoust
** Last update Thu Mar 17 09:59:20 2016 Vincent Davoust
*/


#include <stdlib.h>
#include <stdio.h>

int wrongArgs() {
    printf("Wrong args \n");
    return (1);
}

int main(int argc, char** argv) {
    int i;

    char string[15] = "kill -2  ";

    if (argc != 2) {
        return wrongArgs();
    }

    for (i=0; i < argv[1][i]!='\0' && i < 256; i++) {
        if (argv[1][i] >'9' || argv[1][i] < '0')
            return wrongArgs();
	string[i+9] = argv[1][i];
    }
    string[i+9] = '\0';
    system(string);
    printf("Shot with a pistol ! \n Did it work ? \n");
}
