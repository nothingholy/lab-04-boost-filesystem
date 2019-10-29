// Copyright 2018 Your Name panda_canniball@mail.ru/martyshkashlushka@gmail.com

#include <header.hpp>


int main(int argc, char *argv[]) {
    bf::path ftp_path;
    if (argc < 2)
        ftp_path = "../";
    else
        ftp_path = std::string(argv[1]);

    if (out.is_open())
        if (bf::is_directory(ftp_path)) {
            filer(ftp_path);
            out << "\n\tOverall:\n";
            if (!Brokers.empty()) {
                std::for_each(Brokers.begin(), Brokers.end(),
                              [](auto &i) {
                                  for (const auto &j : i.second)
                                      out << "broker: " << i.first << " account: " << j.first << " files: "
                                          << j.second.second << " lastdate: " << j.second.first << std::endl;
                              });
            } else
                std::cout << "\n!Empty!\n";

        }

    Brokers.clear();
    out.clear();

    return 0;
}
