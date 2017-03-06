#include  "Subject.h"
#ifndef EFFECTVALUESSUBJECT_H
#define EFFECTVALUESSUBJECT_H


enum class EffectValueTypes { DelayDryWet, DelayAmp, DelayTimeMS};

class EffectValuesSubject : public Subject {
public:
  virtual ~EffectValuesSubject(){};
  virtual float getValues(EffectValueTypes effectValueType) = 0;
};

#endif
