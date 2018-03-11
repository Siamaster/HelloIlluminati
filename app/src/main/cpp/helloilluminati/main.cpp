#include "renderer.h"

#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>

void framebuffer_resized(GLFWwindow *window, int width, int height);

GLFWwindow *window = nullptr;
std::unique_ptr<Renderer> renderer = nullptr;

int main() {
    int screen_width = 800;
    int screen_height = 600;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(screen_width, screen_height, "Illuminati", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_resized);

    renderer = std::make_unique<Renderer>(screen_width, screen_height);

    while (!glfwWindowShouldClose(window)) {

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        renderer->DrawFrame();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebuffer_resized(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
    renderer->SetScreenSize(width, height);
}