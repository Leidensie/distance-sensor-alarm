#ifndef DISTANCECONTROL_H
#define DISTANCECONTROL_H

#include <Arduino.h>

class DistanceControl{

private:

    int m_trigpin, m_echopin;

public:

    DistanceControl();

    float CalDistance();

    



};

#endif 
