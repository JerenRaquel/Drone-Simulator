#include "inputSystem.hpp"

InputSystem::InputSystem() {}

InputSystem::~InputSystem() {}

// Utility
void InputSystem::Update(GLFWwindow* const window) noexcept {
  double xpos, ypos;
  glfwGetCursorPos(window, &xpos, &ypos);

  this->mousePosition_ = Vector<float>(xpos, ypos);
  if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
    this->isMouseDown_ = true;
  } else {
    this->isMouseDown_ = false;
  }
}

// Getters
Vector<float> InputSystem::GetMousePosition() const noexcept {
  return this->mousePosition_;
}

bool InputSystem::IsMouseDown() const noexcept { return this->isMouseDown_; }