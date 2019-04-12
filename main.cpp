#include <iostream>
#include <string>
#include "functions.h"

int main(int argc, char * argv[]) {
  std::string input;
  int arg;
  if(argc > 1 && (*(argv[1])) == 'h') {
    //summary of what the application can do
    exit(1);
  }
  
  std::cout << "If you would like to enter a password press 1. Press 2 for more options." << std::endl; 
  getline(std::cin, input);

  while(!tryParse(input, arg)) {
    std::cout << "Invalid input, please try again" << std::endl;
    getline(std::cin, input);
  }

  if(arg == 1){
    std::cout << "Please enter a password" << std::endl;
    getline(std::cin, input);
    int result = getPasswordIter(input);

    std::cout << "Your password was found " << result << " times." << std::endl;
  }

  return 1;



}
