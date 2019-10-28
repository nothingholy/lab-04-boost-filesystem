// Copyright 2018 Your Name <your_email>

#include <header.hpp>

int main(int argc,char *argv[]){
    bf::path ftp_path;
    if(argc<2)
        ftp_path = "../";
    else
        ftp_path=string(argv[1]);

    if(out.is_open()){
        if(bf::is_directory(ftp_path)){
            fillup(ftp_path);
            out << "\n\tOverall:\n";
            if(!brokers.empty()){
                for_each(brokers.begin(),brokers.end(),[](auto &i){
                    for(auto j:i.second)
                        out << "broker: " << i.first << " account: " << j.first << " files: "
                        << j.second.second << " lastdate: " << j.second.first << endl;
                });
            }
            else
                cout << endl << "Empty!" << endl;
        }
    }

    brokers.clear();
    out.clear();
}