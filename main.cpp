
#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/plot.hpp>
#include <opencv2/imgproc.hpp>
#include <stdio.h>

#include <string>
#include "Communication.h"
#include "TurnTableControl.h"

int main( int argc, char** argv )
{
    int turn_times;
 

    turn_times = 0;
    TurnTableControl ttc;
    
    if (ttc.connect("/dev/tty.usbserial-1420"))
    {
        while( turn_times < 10)
        {
            ttc.turnAngle(25);
            sleep(1);
            turn_times++;
            std::cout<<"turn times:"<<turn_times<<std::endl;
           
        }
        return 1;
    }
    else
    {
        std::cout<<"Open port failed! Check port"<<std::endl;
        return 0;
    }
    
}