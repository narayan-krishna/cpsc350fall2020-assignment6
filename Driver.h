#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

//Driver class implements sorting algorithms, and runs them with a timer
//holds file name, the input numbers in a double array, and the array size

class Driver{
  private:
    string file;
    double *numbers;
    int numbersSize;

    // int maxSize;
    // int added;

  public:
    //constructor takes in file name
    Driver(string fileName){
      file = fileName;
    }

    //destructor
    ~Driver(){
      delete numbers;
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

    //print the original test file
    void printOG(){
      cout << "[";
      for(int i = 0; i < numbersSize; ++i){
        cout << numbers[i];
      }
      cout << "]" << endl;
    }

    //swap two doubles pointers
    void swap(double* a, double* b){
      double temp = *a;
      *a = *b;
      *b = temp;
    }

//1 quicksort

    void runQuicksort(){
      double *sorted = new double[numbersSize]{};
      for(int i = 0; i < numbersSize; ++i){
        sorted[i] = numbers[i];
      }
      quicksort(sorted, 0, numbersSize-1);
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

//2 merge sort
    void runMergesort(){
      double *sorted = new double[numbersSize]{};
      for(int i = 0; i < numbersSize; ++i){
        sorted[i] = numbers[i];
      }
      mergesort(sorted, 0, numbersSize-1);
      delete sorted;
    }

    void merge(double *sorted, int left, int mid, int right){
      int sizeLeft = mid-left+1;
      int sizeRight = right-mid;
      double leftSorted[sizeLeft];
      double rightSorted[sizeRight];
      int i, j;
      for(i = 0; i < sizeLeft; ++i){
        leftSorted[i] = sorted[left + i];
      }
      for(j = 0; j<sizeRight; ++j){
        rightSorted[j] = sorted[mid+1+j];
      }
      i = 0;
      j = 0;
      int k = left;
      while(i < sizeLeft && j < sizeRight){
        if(leftSorted[i] <= rightSorted[j]){
          sorted[k] = leftSorted[i];
          i++;
        }else{
          sorted[k] = rightSorted[j];
          j ++;
        }
        k ++;
      }
      while(i < sizeLeft){
        sorted[k] = leftSorted[i];
        i ++;
        k ++;
      }
      while(i < sizeRight){
        sorted[k] = rightSorted[j];
        j ++;
        k ++;
      }
    }

    void mergesort(double *sorted, int left, int right){
      int mid;
      if(left < right){
        mid = left+(right-left)/2;
        mergesort(sorted, left, mid);
        mergesort(sorted, mid + 1, right);
        merge(sorted, left, mid, right);
      }
    }


//3 selection sort

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
      delete sorted;
    }

//4 insertion sort

    void insertionsort(){
      double *sorted = new double[numbersSize]{};
      for(int i = 0; i < numbersSize; ++i){
        sorted[i] = numbers[i];
      }
      int key;
      int j;
      for (int i = 0; i < numbersSize; ++ i){
        key = sorted[i];
        j = i;
        while( j > 0 && sorted[j-1]>key){
          sorted[j] = sorted[j-1];
          j--;
        }
        sorted[j] = key;
      }
      delete sorted;
    }


//5 bubble sort

  void bubblesort(){
    double *sorted = new double[numbersSize]{};
    for(int i = 0; i < numbersSize; ++i){
      sorted[i] = numbers[i];
    }
    bool hasSwapped;
    for (int i =0; i < numbersSize; ++i){
      hasSwapped = false;
      for (int j = 0; j < numbersSize-i-1; j ++){
        if (sorted[j] > sorted[j+1]){
          swap(&sorted[j], &sorted[j+1]);
          hasSwapped = true;
        }
      }
      if (hasSwapped == false){
        break;
      }
    }
    delete sorted;
  }

//time each function individually with custom output

  void timeQuicksort(){
    cout << "QUICK SORT ... " << endl;
    clock_t start = clock();
    cout << " ... start time -> " << ((double)(start))/CLOCKS_PER_SEC << " seconds" << endl;
    runQuicksort();
    clock_t end = clock();
    cout << " ... end time -> " << ((double)(end))/CLOCKS_PER_SEC << " seconds" << endl;
    double timeTaken = ((double)(end-start))/CLOCKS_PER_SEC;
    cout << " ... total execution time -> " << timeTaken << " seconds" << endl;
  }

  void timeMergesort(){
    cout << "MERGE SORT ... " << endl;
    clock_t start = clock();
    cout << " ... start time -> " << ((double)(start))/CLOCKS_PER_SEC << " seconds" << endl;
    runMergesort();
    clock_t end = clock();
    cout << " ... end time -> " << ((double)(end))/CLOCKS_PER_SEC << " seconds" << endl;
    double timeTaken = ((double)(end-start))/CLOCKS_PER_SEC;
    cout << " ... total execution time -> " << timeTaken << " seconds" << endl;
  }

  void timeSelectionsort(){
    cout << "SELECTION SORT ... " << endl;
    clock_t start = clock();
    cout << " ... start time -> " << ((double)(start))/CLOCKS_PER_SEC << " seconds" << endl;
    selectionsort();
    clock_t end = clock();
    cout << " ... end time -> " << ((double)(end))/CLOCKS_PER_SEC << " seconds" << endl;
    double timeTaken = ((double)(end-start))/CLOCKS_PER_SEC;
    cout << " ... total execution time -> " << timeTaken << " seconds" << endl;
  }

  void timeInsertionsort(){
    cout << "INSERTION SORT ... " << endl;
    clock_t start = clock();
    cout << " ... start time -> " << ((double)(start))/CLOCKS_PER_SEC << " seconds" << endl;
    insertionsort();
    clock_t end = clock();
    cout << " ... end time -> " << ((double)(end))/CLOCKS_PER_SEC << " seconds" << endl;
    double timeTaken = ((double)(end-start))/CLOCKS_PER_SEC;
    cout << " ... total execution time -> " << timeTaken << " seconds" << endl;
  }

  void timeBubblesort(){
    cout << "BUBBLE SORT ... " << endl;
    clock_t start = clock();
    cout << " ... start time -> " << ((double)(start))/CLOCKS_PER_SEC << " seconds" << endl;
    bubblesort();
    clock_t end = clock();
    cout << " ... end time -> " << ((double)(end))/CLOCKS_PER_SEC << " seconds" << endl;
    double timeTaken = ((double)(end-start))/CLOCKS_PER_SEC;
    cout << " ... total execution time -> " << timeTaken << " seconds" << endl;
  }

  //timing everything, adding some output formatting

  void timeAll(){
    cout << endl;
    cout << "--------ALGORITHM EXECUTION TIMES (" << numbersSize << " items)--------" << endl;
    cout << endl;
    timeQuicksort();
    cout << endl;
    timeMergesort();
    cout << endl;
    timeSelectionsort();
    cout << endl;
    timeInsertionsort();
    cout << endl;
    timeBubblesort();
    cout << endl;
    // cout << "-----------------------------------------" << endl;
  }
};
