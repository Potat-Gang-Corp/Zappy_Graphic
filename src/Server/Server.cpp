/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Server
*/

#include "Server.hpp"

Server::Server() : resolver(io_context), socket(io_context) {}

int Server::connect_server(const std::string& port, const std::string& host)
{
    try {
        tcp::resolver::results_type endpoints = resolver.resolve(host, port);
        boost::asio::async_connect(socket, endpoints,
            [this](const boost::system::error_code& error, const tcp::endpoint&) {
                handle_connect(error);
            });
        std::cout << "Connecting to server..." << std::endl;
        net_thread = std::thread([this]() { io_context.run(); });
    } catch (const boost::system::system_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

void Server::stop()
{
    io_context.stop();
    if (net_thread.joinable()) {
        net_thread.join();
    }
}

void Server::send_data(const std::string& data)
{
    boost::asio::post(io_context, [this, data]() {
        bool write_in_progress = !write_msgs_.empty();
        write_msgs_.push_back(data);
        if (!write_in_progress) {
            do_write();
        }
    });
}

void Server::start_receive()
{
    boost::asio::async_read_until(socket, buffer, '\n',
        [this](const boost::system::error_code& error, std::size_t bytes_transferred) {
            handle_read(error, bytes_transferred);
        });
}

void Server::handle_connect(const boost::system::error_code& error)
{
    if (!error) {
        std::cout << "Connected to server" << std::endl;
        send_data("GRAPHIC\n");
        start_receive();
    } else {
        std::cerr << "Connect failed: " << error.message() << std::endl;
    }
}

void Server::do_write()
{
    boost::asio::async_write(socket,
        boost::asio::buffer(write_msgs_.front()),
        [this](const boost::system::error_code& error, std::size_t bytes_transferred) {
            if (!error) {
                write_msgs_.pop_front();
                if (!write_msgs_.empty()) {
                    do_write();
                }
            } else {
                std::cerr << "Send failed: " << error.message() << std::endl;
            }
        });
}

void Server::handle_read(const boost::system::error_code& error, std::size_t bytes_transferred)
{
    if (!error || error == boost::asio::error::eof) {
        std::string response(boost::asio::buffers_begin(buffer.data()), boost::asio::buffers_begin(buffer.data()) + bytes_transferred);
        buffer.consume(bytes_transferred);
        if (on_receive) {
            on_receive(response);
        }
        start_receive();
    } else {
        std::cerr << "Receive failed: " << error.message() << std::endl;
    }
}

void Server::listening()
{
    std::unordered_map<std::string, std::function<void(const std::string&)>> dispatcher = {
        {"msz", handle_msz},
        {"bct", handle_bct},
        {"tna", handle_tna}
    };

    on_receive = [&dispatcher](const std::string& data) {
        std::string prefix = data.substr(0, 3);
        auto it = dispatcher.find(prefix);
        if (it != dispatcher.end())
            it->second(data);
        else
            std::cout << "Unknown message type: " << data << std::endl;
    };
}
