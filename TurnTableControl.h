#ifndef __TURNTABLECONTROL_H__
#define __TURNTABLECONTROL_H__

#include "Communication.h"

enum TurnTableStatus
{
    STOP,
    MOVE
};

class TurnTableControl
{
    public:
        TurnTableControl();
        ~TurnTableControl();

        int connect(std::string portName);
        void turnAngle(double angle);
        int receiveKeyMessage(std::string key);

        int readStart;
        std::string receiveBuffer;

        Communication cmu;
        TurnTableStatus status;
};

#endif