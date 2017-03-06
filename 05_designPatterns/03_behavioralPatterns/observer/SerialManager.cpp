#include "SerialManager.h"

void SerialManager::demoValuesChanged() {
  std::cout <<  "\n_____ SerialManager - demoValueChanged - "<<
                "* Please provide new values. \n" <<
                "• delayDryWet ";
  std::cin >> _effectValues.delayDryWet;
  std::cout << "\n• delayTimeMS ";
  std::cin >> _effectValues.delayTimeMS;
  std::cout << "\n• delayAmp ";
  std::cin >> _effectValues.delayAmp;
  std::cout << "\nValuesChanged -> calling notify method!";
  notify();
}

float SerialManager::getValues(EffectValueTypes effectValueType) {
  switch(effectValueType) {
    case EffectValueTypes::DelayDryWet: return _effectValues.delayDryWet;
    case EffectValueTypes::DelayTimeMS: return _effectValues.delayTimeMS;
    case EffectValueTypes::DelayAmp: return _effectValues.delayAmp;
    default: break;
  };
}
