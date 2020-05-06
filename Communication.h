#ifndef __COMMUNICATION_H__
#define __COMMUNICATION_H__

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <string>


class Communication
{
    public:
        Communication();
        ~Communication();
        int openPort(std::string portName);
        std::string readBuffer();
        void writeBuffer(std::string input);
        

        boost::asio::io_service iosev;
        boost::system::error_code ec;
        boost::asio::serial_port *sp;
};
 

#endif