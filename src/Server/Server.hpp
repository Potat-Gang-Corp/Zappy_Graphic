#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Server {
public:
    Server();
    int connect_server(const std::string& port, const std::string& host);
    void stop();
    void send_data(const std::string& data);
    std::string receive_data();
    void listening();
    std::function<void(const std::string&)> on_receive;

private:
    boost::asio::io_service io_service;
    tcp::resolver resolver;
    tcp::socket socket;
    boost::asio::streambuf buffer;
};

#endif // SERVER_HPP
