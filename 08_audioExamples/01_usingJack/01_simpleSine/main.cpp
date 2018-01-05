#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "unistd.h"



JackModule jack;

int main(int argc,char **argv)
{

  jack.init(argv[0]); // use program name as JACK client name
  jack.autoConnect();

  double samplerate=jack.getSamplerate();
  std::cerr << "Samplerate: " << samplerate << std::endl;

  bool running = true;
  while (running)
  {
      switch (std::cin.get())
      {
          case 'q': running = false; break;
          jack.end();
      }
  }

  return 0;
} // main()
