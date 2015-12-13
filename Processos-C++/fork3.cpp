// g++ fork3.cpp -o fork3

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <wait.h>

using namespace std;

int global = 2;

int main() {

  int pid = fork();

  if(pid > 1) {
    // When fork() returns a positive number, we are in the parent process
    // and the return value is the PID of the newly created child process.
    // PID 1 is reserved to init process, so the child's PID must be greater than 1.
    cout << "Parent: " << getpid() << endl;
    cout << "First Parent global = " << global << endl;
    global = 3;
    while (true) {
      cout << "Parent global = " << global << endl;
      sleep(1);
      //wait(NULL);
    }
  } else if(pid == 0) {
    // At child process
    cout << "Child: " << getpid() << endl;
    cout << "First Child global = " << global << endl;
    global = 4;
    while (true) {
      cout << "Child global = " << global << endl;
      sleep(1);
      wait(NULL);
    }
    _exit(1); // exit() is unreliable here, so _exit() must be used
  } else {
    // When fork() returns -1, an error happened.
    cerr << "Could not fork!" << endl;
    exit(-1);
  }

  exit(0);

}
