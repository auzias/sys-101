/*
** main.c for main in /home/vincent/Documents/TP_bash/c
**
** Made by Vincent Davoust
** <vincent.davoust@gmail.com>
**
** Started on Wed Mar 2 11:53:51 2016 Vincent Davoust
** Last update Thu Mar 17 09:26:45 2016 Vincent Davoust
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>


void sig_handler(int signo, int zomb) {
  printf("zomb : %d\n", zomb);
  if (signo == zomb) {
    printf("received signal (ok) %d\n", signo);
    exit(0);
  }
  printf("received signal %d\n", signo);
}

void sig_0(int signo) { sig_handler(signo, 2); }
void sig_1(int signo) { sig_handler(signo, 9); }
void sig_2(int signo) { sig_handler(signo, 15); }


void (*sig_handl[3])(int) = {sig_0, sig_1, sig_2};

# define MINUTES 1

int wrongArgs();
int createSon(int *pid);
int childMain();


int wrongArgs() {
    printf("Wrong args \n");
    return (1);
}

int main(int argc, char** argv) {
    int i;
    int nbfils;
    int msg;

    if (argc != 2) {
        return wrongArgs();
    }

   nbfils = 0;
    for (i=0; i < argv[1][i]!='\0' && i < 256; i++) {
        if (argv[1][i] >'9' || argv[1][i] < '0')
            return wrongArgs();

        nbfils *= 10;
        nbfils += argv[1][i] - '0';
    }

    int pids[nbfils];
    for (i=0; i < nbfils; i++) {
        createSon(pids + i);
    }


	for (i=0; i<60*MINUTES; i++) {
		wait(0);
	}
	exit(0);
}

int createSon(int *pid) {

    if ((*pid = fork()) != 0)
        return 0;
    childMain();
}

int childMain() {
  pid_t child_pid;

  srandom(time(NULL));
  //  int zombieType = 2;//random()%3;
   /* Create child*/
  child_pid = fork ();
  if (child_pid > 0) {
    int zombieType = child_pid%3;
    //      fork ();
    /* Parent process */
    signal(SIGKILL, sig_handl[zombieType]);
    signal(SIGTERM, sig_handl[zombieType]);
    signal(SIGSTOP, sig_handl[zombieType]);
    sleep (60*MINUTES);
  }
  else {

    /*Child process. Exit immediately. */
    exit (0);
  }
  return 0;
}

