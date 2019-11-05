// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header.hpp>

TEST(Example, EmptyTest) {
    std::string ftp_path = "../";
    fillup(ftp_path);
    EXPECT_EQ(brokers.size(), 3);

    brokers.clear();
    ftp_path = "../result/";
    fillup(ftp_path);
    EXPECT_EQ(brokers.size(), 0);
}