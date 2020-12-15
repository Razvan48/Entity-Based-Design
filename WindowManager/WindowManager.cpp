#include "WindowManager.h"

WindowManager::WindowManager(int width, int height, std::string title): width(width), height(height), title(title)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);
	//glfwGetPrimaryMonitor();

	glfwMakeContextCurrent(this->window);

	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSetTime(this->currentTime);

	glewInit();

	glfwSwapInterval(1);
}

WindowManager::~WindowManager()
{
	glfwDestroyWindow(this->window);
}

void WindowManager::PreFrameDraw()
{
	this->previousTime = this->currentTime;
	this->currentTime = glfwGetTime();
	this->deltaTime = this->currentTime - this->previousTime;

	glClear(GL_COLOR_BUFFER_BIT);
}

void WindowManager::PostFrameDraw()
{
	glfwSwapBuffers(this->window);

	glfwPollEvents();
}

void WindowManager::SetBackgroundColor(double red, double green, double blue, double alpha)
{
	glClearColor(red, green, blue, alpha);
}

void WindowManager::SetBackgroundColor(double red, double green, double blue)
{
	glClearColor(red, green, blue, 1.0f);
}