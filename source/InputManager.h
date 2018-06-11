#pragma once

#include <vector>

class Controller;
class Keyboard;
class Mouse;

class InputManager
{
public:
	InputManager();
	~InputManager();

private:
	std::vector<Controller*> m_Controllers;
	Keyboard* m_Keyboards;
	Mouse* m_Mouse;
};
