#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void infiniteLoop() {
    for (;;);
}

int main() {
    
    unsigned int numCores = thread::hardware_concurrency();
    vector<thread> threads;

    for (unsigned int i = 0; i < numCores; ++i) {
        threads.emplace_back(thread(infiniteLoop));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
