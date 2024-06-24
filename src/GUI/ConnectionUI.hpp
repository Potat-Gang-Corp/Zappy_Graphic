/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** ConnectionUI
*/

#ifndef CONNECTIONUI_HPP_
#define CONNECTIONUI_HPP_

#include "GUI.hpp"
#include "TextElement.hpp"

class ConnectionUI {
    public:
        ConnectionUI(int screenWidth, int screenHeight, std::string port, std::string host);
        std::string getPort() { return _portText; }
        std::string getHost() { return _hostText; }
        bool getStatus() { return _status; }
        void draw();

    private:
        void drawInputField(const std::string& label, const Rectangle& rect, const std::string& text, bool active);
        void processInput();
        
        Rectangle _form, _port, _host;
        TextElement _footerText, _mainTitle;
        std::string _portText, _hostText;
        bool _status, _portActive, _hostActive;
};


#endif /* !CONNECTIONUI_HPP_ */
