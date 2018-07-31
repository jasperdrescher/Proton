#pragma once

#include <vector>

class Controller;
class Keyboard;
class Cursor;

class InputManager
{
public:
	InputManager();
	~InputManager();

private:
	std::vector<Controller*> m_Controllers;
	Keyboard* m_Keyboards;
	Cursor* m_Cursor;
};
