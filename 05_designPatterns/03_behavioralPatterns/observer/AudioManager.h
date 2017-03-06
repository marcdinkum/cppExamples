#include <iostream>
#include "Effect.h"
#include "Delay.h"
#include "Subject.h"

class AudioManager {
public:
  AudioManager(Subject* subject);
  ~AudioManager();

  //example test method (instead of proper using audio callback)
  void audioCallback();

private:
  static int constexpr numEffects = 1;
  //TODO change into vector & create seperate vector example
  Effect* effectChain[numEffects];
};
