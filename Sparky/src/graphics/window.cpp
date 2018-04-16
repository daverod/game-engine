//
//  window.cpp
//  Sparky
//
//  Created by David Rodin on 4/13/18.
//  Copyright © 2018 David Rodin. All rights reserved.
//

#include "window.hpp"

namespace sparky { namespace graphics {
    Window::Window(const char * title, int width, int height)
    {
        m_Title = title;
        m_Width = width;
        m_Height = height;
        if(!init())
            glfwTerminate();
    }
    Window::~Window()
    {
        glfwTerminate();
    }
    bool Window::init()
    {
        if (!glfwInit())
        {
            std::cout << "Failed to initialize GLFW" << std::endl;
            return false;
        }
        
        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
        if (!m_Window)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            return false;
        }
        
        glfwMakeContextCurrent(m_Window);
        
        return true;
    }
    void Window::clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    void Window::update() const
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }
    bool Window::closed() const
    {
        return glfwWindowShouldClose(m_Window);
    }
}}
