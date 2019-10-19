// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "header.hpp"

TEST(Example, EmptyTest) {
    std::string ftp_path = "../";
    filer(ftp_path);
    EXPECT_EQ(Brokers.size(), 3);

    Brokers.clear();
    ftp_path = "../results/";
    filer(ftp_path);
    EXPECT_EQ(Brokers.size(), 0);
}
