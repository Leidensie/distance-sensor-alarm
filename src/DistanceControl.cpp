#include "DistanceControl.h"

DistanceControl::DistanceControl(){

    m_trigpin = 5;
    m_echopin = 18;
    pinMode(m_trigpin, OUTPUT);
    pinMode(m_echopin, INPUT);

}

float DistanceControl::CalDistance(){

    digitalWrite(m_trigpin,LOW);
    delayMicroseconds(2);
    digitalWrite(m_trigpin,HIGH);
    delayMicroseconds(10);
    digitalWrite(m_trigpin,LOW);

    float distance = pulseIn(m_echopin, HIGH) * 0.034 / 2;

    return  distance;
    

}