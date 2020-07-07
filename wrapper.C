#include "Ab3P.h"
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>

extern "C" void get_abbrevs_cpp(char *text, char *output_buffer, size_t *output_buffer_size) {
    Ab3P ab3p;
    vector<AbbrOut> abbrs;
    string abbrevs;

    ab3p.get_abbrs(text, abbrs); // call main algorithm
    for (size_t i = 0; i < abbrs.size(); ++i) {
        string line = abbrs[i].sf + "|" + abbrs[i].lf + "\n";
        abbrevs.append(line);
    }
    
    size_t output_size = abbrevs.length();
    
    if (output_size > *output_buffer_size) {
        *output_buffer_size = output_size;
    } else {
        strcpy(output_buffer, abbrevs.c_str()); // Copy result into provided buffer
    }
}

