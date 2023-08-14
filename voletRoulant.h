/*
  VoletRoulant.h - Library pour commander des volets roulants électriques
  Created by Nicolas Moine, January 26th, 2020.
*/
#ifndef voletRoulant_h
  #define voletRoulant_h

  #include <Arduino.h>

  class VoletRoulant
  {
    public:
        VoletRoulant(int pinUp,int pinDown);
        void init();
        void monte();
        void descend();
        void stop();
        void testTimer();

      private:
        int _pinUp;
        int _pinDown; 
        uint8_t _desactive = HIGH;
        uint8_t _active = LOW;
        long _time;
        long _dureeTimer;
        void startTimer();

  };

#endif