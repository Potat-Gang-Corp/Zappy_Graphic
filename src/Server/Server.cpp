/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Server
*/

#include "Server.hpp"

using boost::asio::ip::tcp;

int Server::connect_server(const std::string& host, const std::string& port)
{
        try {
        boost::asio::io_context io_context;

        tcp::socket socket(io_context);
        tcp::resolver resolver(io_context);

        std::cout << "Connecting to host: " << host << ", port: " << port << std::endl;

        boost::asio::connect(socket, resolver.resolve(host, port));
        if (!socket.is_open()) {
            std::cerr << "Connection failed" << std::endl;
            return 1;
        }

        std::string data{"some client data ..."};
        auto result = boost::asio::write(socket, boost::asio::buffer(data));

        std::cout << "Data sent: " << data.length() << '/' << result << std::endl;

        boost::asio::streambuf buffer;
        boost::system::error_code error;
        std::size_t len = boost::asio::read_until(socket, buffer, '\n', error);

        if (error && error != boost::asio::error::eof) {
            std::cerr << "Receive failed: " << error.message() << std::endl;
            return 1;
        }

        std::string response(boost::asio::buffers_begin(buffer.data()), boost::asio::buffers_begin(buffer.data()) + len);
        std::cout << "Response received: " << response << std::endl;

        boost::system::error_code ec;
        socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
        socket.close();

    } catch (const boost::system::system_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}