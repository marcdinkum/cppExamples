#include  "Subject.h"
#ifndef EFFECTVALUESSUBJECT_H
#define EFFECTVALUESSUBJECT_H


enum class EffectValueTypes { DelayDryWet, DelayTimeMS, DelayAmp};

class EffectValuesSubject : public Subject {
public:
  virtual ~EffectValuesSubject(){};
  virtual float getValues(EffectValueTypes effectValueType) = 0;
};

#endif
