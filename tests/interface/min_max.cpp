#include <gtest/gtest.h>
#include "interface.h"
#include "comunication.h"
#include "vector.h"

TEST(MinMaxTest, GeneralNonThread) {
    comunication comm;
    vector<int> v{{1, 2, 3, 4, 5}, 5};
    comm.argument = &v;

    min_max(&comm);

    vector<int> result = *(reinterpret_cast<vector<int>*>(comm.result));
    EXPECT_EQ(result.v[0], 1);
    EXPECT_EQ(result.v[1], 5);
}

TEST(MinMaxTest, Zero) {
    comunication comm;
    vector<int> v{{0}, 0};
    comm.argument = &v;

    DWORD min_max_id;
    HANDLE min_max_thread = CreateThread(NULL, 0, min_max, &comm, NULL, &min_max_id);

    if (min_max_thread == NULL) {
        FAIL() << "Error creating min_max_thread: " << GetLastError() << '\n';
    }

    WaitForSingleObject(min_max_thread, INFINITE);
    DWORD q = 0;
    GetExitCodeThread(min_max_thread, &q);
    EXPECT_EQ(q, 1);
}

TEST(MinMaxTest, GeneralThread) {
    comunication comm;
    vector<int> v{{1, 2, 3, 4, 5}, 5};
    comm.argument = &v;

    DWORD min_max_id;
    HANDLE min_max_thread = CreateThread(NULL, 0, min_max, &comm, NULL, &min_max_id);

    if (min_max_thread == NULL) {
        FAIL() << "Error creating min_max_thread: " << GetLastError() << '\n';
    }

    WaitForSingleObject(min_max_thread, INFINITE);

    vector<int> result = *(reinterpret_cast<vector<int>*>(comm.result));
    EXPECT_EQ(result.v[0], 1);
    EXPECT_EQ(result.v[1], 5);
}