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