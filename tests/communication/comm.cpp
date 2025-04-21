#include <gtest/gtest.h>
#include "comunication.h"

TEST(Communication, correctNullingAndDeletion) {
    comunication comm;
    EXPECT_EQ(comm.argument, nullptr);
    EXPECT_EQ(comm.result, nullptr);
    // if returns well. don't deletes
}

TEST(Communication, correctArgumentsHandling) {
    comunication comm;
    int i = 5;
    comm.argument = &i;
    comm.result = new int(4); //WARNING: communication deletes object by itself
    EXPECT_EQ(*(reinterpret_cast<const int*>(comm.argument)), 5);
    EXPECT_EQ(*(reinterpret_cast<int*>(comm.result)), 4);
    // should delete after that
}