/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Server
*/

#include "Server.hpp"
#include "Factory.hpp"

Server::Server() : resolver(io_service), socket(io_service) {}

int Server::connect_server(const std::string& port, const std::string& host)
{
    try {
        tcp::resolver::query query(host, port);
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
        boost::asio::connect(socket, endpoint_iterator);
        std::cout << "Connecté au serveur!" << std::endl;
        send_data("GRAPHIC\n");
    } catch (const boost::system::system_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

void Server::stop()
{
    io_service.stop();
}

void Server::send_data(const std::string& data)
{
    try {
        boost::asio::write(socket, boost::asio::buffer(data));
    } catch (const boost::system::system_error& e) {
        std::cerr << "Send failed: " << e.what() << std::endl;
    }
}

std::string Server::receive_data()
{
    try {
        // Lire jusqu'au délimiteur '\n'
        size_t bytes_transferred = boost::asio::read_until(socket, buffer, '\n');
        
        // Créer un std::string à partir du buffer jusqu'à 'bytes_transferred'
        std::string response(
            boost::asio::buffers_begin(buffer.data()),
            boost::asio::buffers_begin(buffer.data()) + bytes_transferred
        );
        
        // Consommer les données lues du buffer
        buffer.consume(bytes_transferred);
        
        return response;
    } catch (const boost::system::system_error& e) {
        std::cerr << "Receive failed: " << e.what() << std::endl;
        return "";
    }
}

void Server::listening()
{
    while (true)
    {

        std::string response = receive_data();
        std::cout << "Data received from server: " << response << std::endl;
        if (response != "ko" && response != "WELCOME\n") {
            std::string prefix = response.substr(0, 3);
            ICommand* command = CommandFactory::getInstance()->getCommand(prefix);
            if (command) {
                std::cout << "Executing command: " << command << std::endl;
                command->execute(response);
            } else {
                std::cout << "Unknown message type: " << response << std::endl;
            }
        }
    }
}
