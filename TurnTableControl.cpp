#include "TurnTableControl.h"

TurnTableControl::TurnTableControl()
{
    receiveBuffer = "";
    readStart = 0;
    status = STOP;
}

TurnTableControl::~TurnTableControl()
{

}

int TurnTableControl::connect(std::string portName)
{
    return cmu.openPort(portName);
}

void TurnTableControl::turnAngle(double angle)
{
    double success = false;
    while(!success){
        if ( status == STOP && receiveKeyMessage("Please input angle to turn") == 1)
        {
            std::string s=std::to_string(angle);
            s = s+"\r\n";
            cmu.writeBuffer(s);
            status = MOVE; 
        }
        if ( status == MOVE && receiveKeyMessage("Turn over! Success!") == 1)
        {
            success = true;
            status = STOP;
        }
    }
}


int TurnTableControl::receiveKeyMessage(std::string key)
{
    std::string readBuffer = cmu.readBuffer();
    receiveBuffer = receiveBuffer+readBuffer;
    if ( receiveBuffer.find(key) != std::string::npos)
    {
        std::cout<<receiveBuffer<<std::endl;
        receiveBuffer = "";
        readStart = readBuffer.length();
        return 1;
    }
    else
    {
        return 0;
    }
}
