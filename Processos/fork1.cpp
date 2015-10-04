// g++ fork1.cpp -o fork1

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <wait.h>

using namespace std;

int main() {

  cout << "Before fork() : " << getpid() << endl;

  int pid = fork();

  cout << "After fork() : " << getpid() << endl;

  if(pid > 1) {
    // When fork() returns a positive number, we are in the parent process
    // and the return value is the PID of the newly created child process.
    // PID 1 is reserved to init process, so the child's PID must be greater than 1.
    cout << "Parent PID: " << getpid() << endl;
    cout << "Parent PPID: " << getppid() << endl;
    for(int i = 0; i < 100; i++) cout << "loop\n";
    //sleep(1);
  } else if(pid == 0) {
    // At child process
    cout << "Child PID: " << getpid() << endl;
    cout << "Child PPID: " << getppid() << endl;
    _exit(0); // exit() is unreliable here, so _exit() must be used
  } else {
    // When fork() returns -1, an error happened.
    cerr << "Could not fork!" << endl;
    exit(1);
  }

  exit(0);

}
