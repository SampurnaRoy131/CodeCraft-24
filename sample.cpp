//Name: Pranav Raghu
//Email: myfakeemail@gmail.com

#include "header.h"

FileParser::FileParser(std::string &&filename, char delimiter) {
  std::ifstream fin(filename);

  if (!fin) {
    std::cerr << "Error opening file" << std::endl;
    exit(0);
  }

//Let's go ahead and complete this!
