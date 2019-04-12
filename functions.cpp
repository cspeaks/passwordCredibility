#include <stdexcept>
#include <fstream>
#include <sstream>
#include <math.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <dirent.h>

bool tryParse(std::string& input, int& output ) {
  try {
    output = std::stoi(input);
  }
  catch (std::invalid_argument) {
    return false;
  }

  return true;
}

int checkFile(std::string fileName, std::string password) {
  int total = -1;
  std::string line, sub;
  std::ifstream file;
  file.open("data/" + fileName);
  if(file.is_open()) {
    while(std::getline(file,line)) {
      std::string cmp;
      for( int i = 8; i < static_cast<int>(line.size()); i++) {
        cmp += line[i];
	if(cmp[0] != line[8]) break;
      }
      if((cmp.compare(password)) == 0) {
        for(int i =  0; i <= 7; i++) {
          if(line[i] != ' ') {
	    sub += line[i];
          }
        }
      total = std::stoi(sub);
      break;
      }
    }
    file.close();
  }
  return total;
}

int getPasswordIter(std::string password) {
  int total = 0;
  std::vector<std::string> files;
  struct dirent *entry;
  DIR *dir = opendir("data/");

  if(dir == NULL) return -1;
  files.reserve(6);
  while((entry = readdir(dir)) != NULL) {
    if((entry->d_name)[0] != '.')
      files.emplace_back(entry->d_name);
  }
  closedir(dir);

  for(auto it = files.begin(); it != files.end(); it++) {
    total += checkFile(*it, password);
  }
  return total;
}

