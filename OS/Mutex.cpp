#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int count = 0;

void task() {
    mtx.lock(); // Equivalent to lock.acquire()
    for (int i = 0; i < 1000000; ++i) {
        count += 1;
    }
    mtx.unlock(); // Equivalent to lock.release()
}

int main() {
    std::thread t1(task);
    std::thread t2(task);

    t1.join();
    t2.join();

    std::cout << count << std::endl;

    return 0;
}

// ----------------------------------------------------------------------------
// OR


#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int count = 0;

void task() {
    std::lock_guard<std::mutex> lock(mtx); // Automatically locks here & unlocks at scope end
    for (int i = 0; i < 1000000; ++i) {
        count += 1;
    }
}

int main() {
    std::thread t1(task);
    std::thread t2(task);

    t1.join();
    t2.join();

    std::cout << count << std::endl;

    return 0;
}