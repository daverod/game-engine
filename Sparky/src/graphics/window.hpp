//
//  window.hpp
//  Sparky
//
//  Created by David Rodin on 4/13/18.
//  Copyright © 2018 David Rodin. All rights reserved.
//

#ifndef window_hpp
#define window_hpp

#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#pragma once

namespace sparky { namespace graphics {
    
#define MAX_KEYS    1024
#define MAX_BUTTONS 32
    
    class Window
    {
    private:
        friend struct GLFWwindow;
        
        const char* m_Title;
        int m_Width, m_Height;
        GLFWwindow* m_Window;
        bool m_Closed;
        
        bool m_Keys[MAX_KEYS];
        bool m_MouseButtons[MAX_BUTTONS];
        double mx, my;
    public:
        Window(const char * title, int width, int height);
        ~Window();
        bool closed() const;
        void update();
        void clear() const;
        
        inline int getWidth() const { return m_Width; }
        inline int getHeight() const { return m_Height; }
        
        bool isKeyPressed(unsigned int keyCode) const;
        bool isMouseButtonPressed(unsigned int button) const;
        void getMousePosition(double& x, double& y) const;
    private:
        bool init();
        friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
        friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    };
}};

#endif /* window_hpp */
