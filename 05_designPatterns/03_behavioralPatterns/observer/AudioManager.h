#include <iostream>
#include "Effect.h"
#include "Delay.h"
#include "Subject.h"

class AudioManager {
public:
  AudioManager(Subject* subject);
  ~AudioManager();

  //NOTE - this is an example, code below should not be public ofcourse
  static int constexpr numEffects = 1;
  Effect* effectChain[numEffects];
};
