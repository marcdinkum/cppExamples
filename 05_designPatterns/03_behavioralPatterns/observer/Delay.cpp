#include "Delay.h"

void Delay::process(/*float* buffer, int numFrames*/) {
  std::cout << "\n_____ Delay - inside process";
}

void Delay::setDelayTimeMS(float delayTimeMS) {
  /*NOTE - audio callback runs on a different thread, this is only example code.
   * In a real project be aware of possibles issues related to multiple threads,
   * when altering 'delayInSamples' value.
   */
   std::cout << "\n_____ Delay - inside setDelayTimesMS - " << std::endl <<
                "* passed delay time in ms. = " <<
                delayTimeMS << std::endl;

  //check if delay time does not exceed max delay time
  if(delayTimeMS < maxDelayTimeMS) {
    //NOTE - lazy example: floor value instead of rounding - <int>
    delayInSamples = static_cast<int> (delayTimeMS / 1000.0 * SAMPLERATE);
    std::cout <<  "* new delay time in Samples = " <<
                  delayInSamples << std::endl;
  }

}

void Delay::update(Subject* subject) {
  //cast subject to EffectValuesSubject type
  EffectValuesSubject* effectValuesSubject = static_cast<EffectValuesSubject*>(subject);
  dryWet = effectValuesSubject->getValues(EffectValueTypes::DelayDryWet);
  setDelayTimeMS(effectValuesSubject->getValues(EffectValueTypes::DelayDryWet));
  amp = effectValuesSubject->getValues(EffectValueTypes::DelayAmp);
}
