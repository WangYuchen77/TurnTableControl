
#include "Communication.h"

Communication::Communication()
{
    sp = new boost::asio::serial_port(iosev);
}
Communication::~Communication()
{

}


int Communication::openPort(std::string portName)
{   
    sp->open(portName, ec);
    if (ec)
    {
        return 0;
    }
    sp->set_option(boost::asio::serial_port::baud_rate(115200));
    sp->set_option(boost::asio::serial_port::flow_control(boost::asio::serial_port::flow_control::none));
    sp->set_option(boost::asio::serial_port::parity(boost::asio::serial_port::parity::none));
    sp->set_option(boost::asio::serial_port::stop_bits(boost::asio::serial_port::stop_bits::one));
    sp->set_option(boost::asio::serial_port::character_size(8));
    return 1;
}
std::string Communication::readBuffer(){
    std::string readBuffer;
    boost::asio::streambuf content_sb;
    int bytes = 0;
    // Read one character at a time
    bytes+=boost::asio::read(*sp, content_sb, boost::asio::transfer_exactly(1), ec); 
    boost::asio::streambuf::const_buffers_type cont_bufs = content_sb.data(); 
    readBuffer = std::string(boost::asio::buffers_begin(cont_bufs), boost::asio::buffers_end(cont_bufs)); 
    return readBuffer;
}
void Communication::writeBuffer(std::string input){
    boost::asio::write(*sp, boost::asio::buffer(input));
}
