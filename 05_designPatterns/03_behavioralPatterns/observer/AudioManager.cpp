#include "AudioManager.h"


AudioManager::AudioManager(Subject* subject) {
  //create effects and add these to effectChain
  effectChain[0] = new Delay();
  subject->attach(effectChain[0]);
}


AudioManager::~AudioManager() {
  delete effectChain[0];
  effectChain[0] = nullptr;
}
