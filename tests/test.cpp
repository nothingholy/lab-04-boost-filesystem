// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header.hpp>

TEST(Example, EmptyTest) {
    std::string ftp_path = "../misc/ftp/";
    fillup(ftp_path);
    EXPECT_EQ(brokers.size(), 3);
    
}