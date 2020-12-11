#include "Driver.h"

//main file runs a simulation upon valid input
int main(int argc, char **argv){
  if(argc != 2){
    cout << "command line requires a file input" << endl;
    cout << "example: " << endl;
    cout << "'./assignment4.exe sequences.txt'" << endl;
  }
  else{
    Driver *d = new Driver(argv[1]);
    d->processFile();
    d->selectionsort();
    d->runQuicksort();
    d->printOG();
    delete d;
  }
}
