#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Driver{
  private:
    string file;
    double *numbers;
    int numbersSize;

    // int maxSize;
    // int added;

  public:
    Driver(string fileName){
      file = fileName;
    }

    //processes the file for commands, puts them into an array
    void processFile(){
      ifstream myfile (file);
      if(myfile.fail()){
        cout << "your file wasn't found. please enter a valid file name." << endl;
        exit(EXIT_FAILURE);
      }
      string line;
      if(myfile.is_open()){
        getline(myfile, line);
        numbersSize = stoi(line);
        numbers = new double[numbersSize]{};
        int curr = 0;
        while(getline(myfile, line)){
          // cout << line << endl;
          numbers[curr] = stod(line);
          curr ++;
        }
        myfile.close();
      }
    }

    //quicksort, merge sort, selection sort, insertion sort, bubble sort
    void printOG(){
      cout << "[";
      for(int i = 0; i < numbersSize; ++i){
        cout << numbers[i];
      }
      cout << "]" << endl;
    }

    void swap(double* a, double* b){
      double temp = *a;
      *a = *b;
      *b = temp;
    }

//quicksort

    void runQuicksort(){
      double *sorted = new double[numbersSize]{};
      for(int i = 0; i < numbersSize; ++i){
        sorted[i] = numbers[i];
      }
      quicksort(sorted, 0, numbersSize-1);
      cout << "[";
      for(int i = 0; i < numbersSize; ++i){
        cout << sorted[i];
      }
      cout << "]" << endl;
      delete sorted;
    }

    int partition(double *sorted, int low, int high){
      int piv = sorted[high];
      int indexSmall = low;
      for(int i = low; i < high; ++i){
        if(sorted[i] <= piv){
          swap(&sorted[i], &sorted[indexSmall]);
          indexSmall++;
        }
      }
      swap(&sorted[indexSmall], &sorted[high]);
      return indexSmall;
    }

    void quicksort(double *sorted, int low, int high){
      if(low < high){
        int lowEnd = partition(sorted, low, high);
        quicksort(sorted, low, lowEnd - 1);
        quicksort(sorted, lowEnd + 1, high);
      }
    }

  // void mergesort(){
  //
  // }
  //

//selection sort

    void selectionsort(){
      double *sorted = new double[numbersSize]{};
      for(int i = 0; i < numbersSize; ++i){
        sorted[i] = numbers[i];
      }
      for(int i = 0; i <= numbersSize-1; ++i){
        for(int j=i+1; j < numbersSize; ++j){
          if(sorted[i] > sorted[j])
          {
            int t = sorted[i];
            sorted[i] = sorted[j];
            sorted[j] = t;
          }
        }
      }
      cout << "[";
      for(int i = 0; i < numbersSize; ++i){
        cout << sorted[i];
      }
      cout << "]" << endl;
      delete sorted;
    }

  //
  // void insertionsort(){
  //
  // }
  //
  // void bubblesort(){
  //
  // }
};
