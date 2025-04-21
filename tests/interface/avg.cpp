#include <gtest/gtest.h>
#include "interface.h"
#include "comunication.h"
#include "vector.h"

TEST(average, general) {
    comunication comm;
    vector<int> v{{1, 2, 3, 4, 5}, 5};
    comm.argument = &v;

    average(&comm);

    int result = *(reinterpret_cast<int*>(comm.result));
    EXPECT_EQ(result, 3);
}

TEST(average, zero) {
    comunication comm;
    vector<int> v{{}, 0};
    comm.argument = &v;

    EXPECT_EQ(average(&comm), 1);
}

TEST(average, generalThread) {
    comunication comm;
    vector<int> v{{1, 2, 3, 4, 5}, 5};
    comm.argument = &v;

    DWORD min_max_id;
    HANDLE min_max_thread = CreateThread(NULL, 0, average, &comm, NULL, &min_max_id);

    if (min_max_thread == NULL) {
        FAIL() << "Error creating min_max_thread: " << GetLastError() << '\n';
    }

    WaitForSingleObject(min_max_thread, INFINITE);

    int result = *(reinterpret_cast<int*>(comm.result));
    EXPECT_EQ(result, 3);
}

TEST(average, fullEmpty) {
    EXPECT_EQ(average(NULL), 2);
}

TEST(average, argumentEmpty) {
    comunication comm;
    EXPECT_EQ(average(&comm), 2);
}