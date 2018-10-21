#pragma once
#include <string>
#include <SDL2/SDL.h>

class Display
{
public:
	Display(int width, int hight, const std::string& title);

	void Update();
	bool isClosed();

	~Display();

protected:
private:
	Display(const Display& other) {}
	Display& operator=(const Display& other) {}

	SDL_Window* m_Window;
	SDL_GLContext m_glContext;
	bool m_isClosed;

};