#include "engine.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
  Engine* eInstance = new Engine();

  //if(!eInstance->init())
    //return -1;
  eInstance->init();

  eInstance->run();

  return 0;
}
