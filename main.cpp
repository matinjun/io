#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

/**
 * @brief 生成随机数
 * 
 * @return double [0, 1) 
 */
double myrand();

int main(int argc, char** argv) {
    if(2 != argc) {
        std::cerr << "usage: io.exe [file]" <<std::endl;
        exit(1);
    }

    int len;
    char * buf;
    int select;
    char table[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
    std::ofstream out(argv[1], std::ios::binary | std::ios::out);
    
    srand((unsigned )time(NULL));

    len = myrand() * 1000000;
    // printf("len  = %d\n", len);
    buf = new char[len + 1];
    for(int i =0; i < len; i++) {
        select = rand() % 53;
        buf[i] = table[select];
    }
    out.write(buf, len);

    out.close();
    delete []buf;

    return 0;
    
}

double myrand() {
    return (double)rand() / (double)RAND_MAX;
}
