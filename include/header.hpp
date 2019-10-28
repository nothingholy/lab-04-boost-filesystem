// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>
#include <boost/filesystem.hpp>
using namespace std;

#define bf boost::filesystem

map<string,map<int,pair<int,int>>> brokers;
ofstream out("../result/res.txt");

void fillup(const bf::path &path){
    for(bf::directory_entry &x : bf::directory_iterator(path)){
        //Директория или символьная ссылка
        if(bf::is_directory(x) || bf::is_symlink(x))
            fillup(x.path());

        if(!bf::is_regular_file(x))
            continue;

        string file_name=x.path().filename().string();
        string extension=x.path().extension().string();

        if(file_name.find("balance_")!=0)
            continue;

        if(extension!=".txt")
            continue;

        int account;
        int date;
        try{
            account=stoi(file_name.substr(8,8));
            date=stoi(file_name.substr(17,8));
        }
        catch(exception &e){
            continue;
        }

        string broker_name=x.path().parent_path().filename().string();
        out << broker_name << " " << file_name << endl;
        brokers[broker_name][account].first=max(brokers[broker_name][account].first,date);
        brokers[broker_name][account].second++;
    }
}

#endif // INCLUDE_HEADER_HPP_
