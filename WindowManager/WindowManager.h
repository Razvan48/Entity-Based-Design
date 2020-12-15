#pragma once

#include <glew.h>
#include <glfw3.h>

#include <iostream>

#include <string>

class WindowManager
{
public:

	int width;
	int height;

	std::string title;

	GLFWwindow* window;

	WindowManager(int width, int height, std::string title);

	~WindowManager();

	inline int GetWidth() const { return this->width; }
	inline int GetHeight() const { return this->height; }

	inline GLFWwindow* GetWindow() const { return this->window; }

	inline double GetDeltaTime() const { return this->deltaTime; }

	void PreFrameDraw();
	void PostFrameDraw();

	void SetBackgroundColor(double red, double green, double blue, double alpha);
	void SetBackgroundColor(double red, double green, double blue);

	inline bool ShouldWindowClose() const { return glfwWindowShouldClose(this->window); }

	inline void SetWindowShouldClose(bool state) const { glfwSetWindowShouldClose(this->window, state); }

private:

	double currentTime = 0.0;
	double previousTime = 0.0;

	double deltaTime = 0.0;

};