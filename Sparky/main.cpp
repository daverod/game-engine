#include <iostream>
#include "src/graphics/window.hpp"
#include "src/math/math.hpp"

const GLint WIDTH = 800, HEIGHT = 600;

int main(int argc, const char * argv[]) {
    using namespace sparky;
    using namespace graphics;
    using namespace math;
    
    Window window("Sparky!", 800, 600);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    Vec3 a(1, 1, 1);
    Vec3 b(3, 22, 16);
    Vec3 c = a + b;

    while (!window.closed()) {
        window.clear();
        double x, y;
        window.getMousePosition(x, y);
        std::cout << x << " , " << y << std::endl;
        
        std::cout << c << std::endl;
        std::cout << a << std::endl;
        
        if(window.isKeyPressed(GLFW_KEY_A))
            std::cout << "a is pressed" << std::endl;
        if(window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
            std::cout << "mouse button left is pressed" << std::endl;
//        std::cout << window.getHeight() << " , " << window.getWidth() << std::endl;
        glBegin(GL_TRIANGLES);
        glVertex2d(-0.5f, -0.5f);
        glVertex2d( 0.0f,  0.5f);
        glVertex2d( 0.5f,  -0.5f);
        glEnd();
        glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
        window.update();
    }
    
    return 0;
}
    
                                    
