#include <windows.h>
#include <iostream>
#include "interface.h"
#include "comunication.h"
#include "vector.h"

void errorHandler(HANDLE thread_handle) {
    if (thread_handle == NULL) {
        std::cerr << "Error creating min_max_thread: " << GetLastError() << '\n';
        exit(GetLastError());
    }
}

int main() {
    size_t size;
    std::cout << "enter size of array: ";
    std::cin >> size; // handle error

    std::vector<int> vec(size);

    std::cout << "enter it's elements: ";
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> vec[i];
    }

    vector<int> v{vec, size};
    
    comunication min_max_comm, avg_comm;
    min_max_comm.argument = &v;
    avg_comm.argument = &v;

    LPTHREAD_START_ROUTINE mmif = min_max;
    DWORD min_max_id;
    HANDLE min_max_thread = CreateThread(NULL, 0, mmif, &min_max_comm, NULL, &min_max_id);
    errorHandler(min_max_thread);

    DWORD avg_id;
    HANDLE avg_thread = CreateThread(NULL, 0, average, &avg_comm, NULL, &avg_id);
    errorHandler(avg_thread);

    WaitForSingleObject(min_max_thread, INFINITE);
    WaitForSingleObject(avg_thread, INFINITE);

    int avg = *(reinterpret_cast<int*>(avg_comm.result));
    int min = (reinterpret_cast<vector<int>*>(min_max_comm.result))->v[0];
    int max = (reinterpret_cast<vector<int>*>(min_max_comm.result))->v[1];
    std::cout << "vector: ";
    for (int& i : vec) {
        if (i == min || i == max) {
            i = avg;
        }
        std::cout << i << ", ";
    }
    std::cout << '\n';


    return 0;
}