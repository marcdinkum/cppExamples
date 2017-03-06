#include <iostream>
#include "AudioManager.h"
#include "SerialManager.h"
int main() {
  std::cout << "\nCreating a SerialManager object.\n";
  //create SerialManager
  SerialManager serialManager;

  std::cout << "\nCreating an AudioManager object.\n";
  //create AudioManager object, pass address serialManager =^ subject 
  AudioManager audioManager(&serialManager);

  std::cout << "\nCalling audioManager demoValuesChanged method.\n";
  //call the demoValuesChangedaudioManager method
  audioManager.demoValuesChanged();


  //end program
  std::cout << std::endl;
  return 0;
}
