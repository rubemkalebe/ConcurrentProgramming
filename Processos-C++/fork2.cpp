// g++ fork2.cpp -o fork2

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <wait.h>

using namespace std;

int main() {

  int pid = fork();

  if(pid > 1) {
    // When fork() returns a positive number, we are in the parent process
    // and the return value is the PID of the newly created child process.
    // PID 1 is reserved to init process, so the child's PID must be greater than 1.
    cout << "Parent: " << getpid() << endl;
    int status;
    //wait(&status);
    waitpid(pid, &status, 0);
    /*for(int i = 0; i < 10; i++) {
      cout << "Loop\n";
      sleep(2);
    }*/
    cout << "Child returned: " << WEXITSTATUS(status) << endl;
  } else if(pid == 0) {
    // At child process
    cout << "Child: " << getpid() << endl;
    for(int i = 0; i < 10; i++) {
      cout << "Loop\n";
      sleep(2);
    }
    _exit(1); // exit() is unreliable here, so _exit() must be used
  } else {
    // When fork() returns -1, an error happened.
    cerr << "Could not fork!" << endl;
    exit(-1);
  }

  exit(0);

}
