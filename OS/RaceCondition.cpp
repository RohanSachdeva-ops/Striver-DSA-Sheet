
// THIS CODE IS THE IMPLEMENTATION OF RACE CONDITION IN WHICH DIFFERENT THREADS ARE TRYING TO CHANGE THE CRITICAL SECTION AT A TIME
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// Global mutex (lock) and counter
mutex mtx;
int count = 0;

void task() {
    // mtx.lock();
    for (int i = 0; i < 1000000; ++i) {
        count++;
    }
    // mtx.unlock();
}

int main() {
    // Create and start threads
    // FUNCTION THREAD() IS USED TO CREATE A THREAD AND CALL THE FUNCTION WHICH WE WANT TO EXECUTE IN THAT THREAD
    thread t1(task);
    thread t2(task);

    // Wait for both threads to finish execution
    // FUNCTION JOIN() IS USED TO WAIT FOR THE THREAD TO FINISH EXECUTION

    t1.join();
    t2.join();

    // Print the final count
    cout << count << endl;

    return 0;
}