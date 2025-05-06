#include <iostream>

#include "../include/GamingCafe.h"

int main(int argc, char * argv[])
{
  if (argc > 1)
  {
    GamingCafe gamingCafe;
    gamingCafe.ReadInputFile(argv[1]);
  }
  else
  {
    std::cout << "You didn't pass file name" << std::endl;
  }
  return 0;
}
