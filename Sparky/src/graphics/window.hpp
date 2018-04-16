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
#include <GLFW/glfw3.h>

#pragma once

namespace sparky { namespace graphics {
    
    class Window
    {
    private:
        const char* m_Title;
        int m_Width, m_Height;
        GLFWwindow* m_Window;
        bool m_Closed;
    public:
        Window(const char * title, int width, int height);
        ~Window();
        bool closed() const;
        void update() const;
        void clear() const;
    private:
        bool init();
    };
}};

#endif /* window_hpp */
