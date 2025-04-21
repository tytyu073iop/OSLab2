#include "interface.h"
#include "comunication.h"
#include "vector.h"
#include <vector>
#include <iostream>

// template<typename T>
DWORD WINAPI min_max(LPVOID communicati)
{
    if (communicati == NULL || communicati == nullptr) {
        return 2;
    }
    comunication* comm = reinterpret_cast<comunication*>(communicati);
    
    if (comm->argument == nullptr) {
        return 2;
    }

    const vector<int>* v = reinterpret_cast<const vector<int>*>(comm->argument);

    if (v->size == 0) {
        return 1;
    }

    int min = v->v[0];
    int max = v->v[0];

    for (size_t i = 1; i < v->size; i++)
    {
        if (v->v[i] > max) {
            max = v->v[i];
        }
        Sleep(7);
        if (v->v[i] < min) {
            min = v->v[i];
        }
        Sleep(7);
    }

    vector<int>* result = new vector<int>{std::vector<int>{min, max}, 2};
    comm->result = result;

    std::cout << "min is: " << min << ", max is: " << max << '\n';
    
    return 0;
}

DWORD WINAPI average(LPVOID communicati)
{
    if (communicati == NULL || communicati == nullptr) {
        return 2;
    }
    comunication* comm = reinterpret_cast<comunication*>(communicati);

    if (comm->argument == nullptr) {
        return 2;
    }

    const vector<int>* v = reinterpret_cast<const vector<int>*>(comm->argument);

    if (v->size <= 0) {
        return 1;
    }

    int sum = 0;
    size_t si = v->size;

    for (size_t i = 0; i < si; i++)
    {
        sum += v->v[i];
        Sleep(12);
    }


    comm->result = new int(sum/si);

    std::cout << "avg is: " << *(reinterpret_cast<int*>(comm->result)) << '\n';
    
    return 0;
}