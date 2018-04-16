//
//  main.cpp
//  Sparky
//
//  Created by David Rodin on 4/13/18.
//  Copyright © 2018 David Rodin. All rights reserved.
//

#include <iostream>

//GLEW
#define GLEW_STATIC
#include <GL/glew.h>

//GLFW
#include <GLFW/glfw3.h>

#include "src/graphics/window.hpp"

const GLint WIDTH = 800, HEIGHT = 600;

int main(int argc, const char * argv[]) {
//    glfwInit();
//
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
//    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE );
//
//    GLFWwindow * window = glfwCreateWindow(WIDTH, HEIGHT, "Goofin", nullptr, nullptr);
//
//    int screenWidth, screenHeight;
//    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
//
//    if (window == nullptr) {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(window);
//
//    glewExperimental = GL_TRUE;
//
//    if (glewInit() != GLEW_OK) {
//        std::cout << "Failed to initialize GLEW window" << std::endl;
//        return -1;
//    }
//
//    glViewport(0, 0, screenWidth, screenHeight);
//
//    while(!glfwWindowShouldClose(window)) {
//        glfwPollEvents();
//
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        glfwSwapBuffers(window);
//    }
//
//    glfwTerminate();
    using namespace sparky;
    using namespace graphics;
    
    Window window("Sparky!", 800, 600);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    
    while (!window.closed()) {
        window.clear();
        window.update();
    }
    
    return 0;
}
    
                                    
