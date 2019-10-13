// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <boost/filesystem.hpp>

#define bf boost::filesystem

// Имя Брокера, Номер Счёта, Дата, Кол-во
std::map<std::string, std::map<std::string, std::pair<int, int>>> Brokers;
std::ofstream out("C:/Users/panda/CLionProjects/lab-04-boost-filesystem/results/result.txt");


void filer(const bf::path &path) {
    for (bf::directory_entry &x : bf::directory_iterator(path)) {
        // Директория или Символьная ссылка
        if (bf::is_directory(x) || bf::is_symlink(x))
            filer(x.path());
        // Проверка на обычность
        if (!bf::is_regular_file(x))
            continue;

        std::string file_name = x.path().filename().string(),
                extension = x.path().extension().string();

        // Проверка типа файла
        if (file_name.find("balance_") != 0)
            continue;

        // Проверка спец. символа между номером счета и датой
        if (file_name[16] != '_')
            continue;

        // Проверка разрешения
        if (extension != ".txt")
            continue;

        // Проверка актуальности
        if (file_name.size() != 29)
            continue;

        std::string account = file_name.substr(8, 8);
        int date = stoi(file_name.substr(17, 8));
        std::string broker_name = x.path().parent_path().filename().string();

        out << broker_name << " " << file_name << std::endl;
        Brokers[broker_name][account].first = std::max(Brokers[broker_name][account].first, date);
        Brokers[broker_name][account].second++;
    }
}

#endif // INCLUDE_HEADER_HPP_
