/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** ConnectionUi
*/

#include "ConnectionUI.hpp"
#include "Camera.hpp"

ConnectionUI::ConnectionUI(int screenWidth, int screenHeight, std::string port, std::string host)
: _form({ (float)screenWidth / 2 - 250, (float)screenHeight / 2 - 250, 500, 300 }), _port({ _form.x + 10, _form.y + 100, _form.width - 20, 40 }),
        _host({ _form.x + 10, _form.y + 180, _form.width - 20, 40 }), _footerText("Press Enter to connect !", { 0, 0 }, 20, DARKGRAY),
        _mainTitle("Connect to the Server !", { 0, 0 }, 30, DARKGRAY), _status(false), _portActive(false), _hostActive(false), _portText(port), _hostText(host)
{
    _footerText.setPosition({ _form.x + _form.width / 2 - _footerText.getTextWidth() / 2, _form.y + _form.height - 60 });
    _mainTitle.setPosition({ _form.x + _form.width / 2 - _mainTitle.getTextWidth() / 2, _form.y + 20 });
}

void ConnectionUI::draw()
{
    BeginDrawing();
    ClearBackground(SKYBLUE);
    CameraWrapperPtr _camera = CameraWrapper::getInstance();
    _camera->BeginMode();
    // for (auto& model : GUI::getInstance()->getModel()) {
    //     model->drawModel();
    // }
    _camera->EndMode();
    DrawRectangleRec(_form, WHITE);
    DrawRectangleLines((int)_form.x, (int)_form.y, (int)_form.width, (int)_form.height, DARKGRAY);
    _mainTitle.draw();
    
    drawInputField("Port :", _port, _portText, _portActive);
    drawInputField("Host :", _host, _hostText, _hostActive);
    _footerText.draw();
    Color statusColor = _status ? GREEN : RED;
    const std::string statusText = _status ? "Connected" : "Disconnected";
    DrawCircle(_form.x + 20, _form.y + _form.height - 20, 10, statusColor);
    DrawText(statusText.c_str(), _form.x + 40, _form.y + _form.height - 28, 20, statusColor);
    processInput();
    EndDrawing();
}

void ConnectionUI::drawInputField(const std::string& label, const Rectangle& rect, const std::string& text, bool active)
{
    DrawText(label.c_str(), (int)rect.x, (int)rect.y - 25, 20, DARKGRAY);
    DrawRectangleRec(rect, Fade(LIGHTGRAY, 0.5f));
    if (CheckCollisionPointRec(GetMousePosition(), rect)) {
        DrawRectangleLines((int)rect.x, (int)rect.y, (int)rect.width, (int)rect.height, RED);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            _portActive = (&rect == &_port);
            _hostActive = (&rect == &_host);
        }
    } else {
        DrawRectangleLines((int)rect.x, (int)rect.y, (int)rect.width, (int)rect.height, DARKGRAY);
    }
    DrawText(text.c_str(), (int)rect.x + 5, (int)rect.y + rect.height / 2 - 10, 20, BLACK);
    if (active) {
        DrawText("_", (int)rect.x + 10 + MeasureText(text.c_str(), 20), (int)rect.y + rect.height / 2 - 10, 20, BLACK);
    }
}

void ConnectionUI::processInput()
{
    int key = GetCharPressed();
    while (key > 0) {
        if (_portActive && (key >= 32) && (key <= 125) && (_portText.length() < 5)) {
            _portText += (char)key;
        }
        if (_hostActive && (key >= 32) && (key <= 125) && (_hostText.length() < 15)) {
            _hostText += (char)key;
        }
        key = GetCharPressed();
    }
    if (IsKeyPressed(KEY_BACKSPACE)) {
        if (_portActive && !_portText.empty()) _portText.pop_back();
        if (_hostActive && !_hostText.empty()) _hostText.pop_back();
    }
    if (IsKeyPressed(KEY_ENTER))
        _status = true;
    else
        _status = false;
}
