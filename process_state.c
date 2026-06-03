#include <stdio.h>
#include<conio.h>             //for kbhit()
#include <unistd.h>          //for sleep() 

// here a pseudo process is working and program help us to determine current state of program and advantage of program is 
// that here process does not stop while giving the output as actual os works

enum State {
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

void showstate(enum State s){
    printf("\n current state of process is ");
     switch(s) {
        case NEW:        printf("NEW");        break;
        case READY:      printf("READY");      break;
        case RUNNING:    printf("RUNNING");    break;
        case WAITING:    printf("WAITING");    break;
        case TERMINATED: printf("TERMINATED"); break;
    }

}

int main() {
    printf("PROCESS HAS STARTED");
    enum State currentState = NEW;   // start at NEW
    
    while (1){
        currentState = NEW;
        sleep(3);                 // sleep function helps to reduce the reading speed of program and input is in second
        if(kbhit()){
            getch();
           showstate(currentState);
        }

        currentState = READY;
        sleep(3);
          if(kbhit()){              // here main function is kbhit() it checks the any value key is pressed, which is stored in the buffer
            getch();                // to empty buffer space we have used getch()
            showstate(currentState);
        }

        currentState = RUNNING;
        sleep(3);
          if(kbhit()){
            getch();
            showstate(currentState);
        }

        currentState = WAITING;
        sleep(3); 
         if(kbhit()){
            getch();
            showstate(currentState);
        }

        currentState = TERMINATED;
        sleep(3);
          if(kbhit()){
            getch();
            showstate(currentState);
        }
        printf("\n PROCESS HAS COMPLETED");
        break;
    }
    return 0;
}

