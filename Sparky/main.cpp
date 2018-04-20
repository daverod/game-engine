#include "src/graphics/window.hpp"
#include "src/math/math.hpp"
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <iostream>
#include <cassert>

#if defined __linux__ || defined __APPLE__
// "Compiled for Linux
#else
// Windows doesn't define these values by default, Linux does
#define M_PI 3.141592653589793
#define INFINITY 1e8
#endif


const GLint WIDTH = 800, HEIGHT = 600;

int main(int argc, const char * argv[]) {
    
    using namespace sparky;
    using namespace graphics;
    using namespace math
    
//    Window window("Sparky!", 800, 600);
//    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//    GLuint vao;
//    glGenVertexArrays(1, &vao);
//    glBindVertexArray(vao);
    
//    Vec3 a(1, 1, 1);
//    Vec3 b(3, 22, 16);
//    Vec3 c = a + b;
//
//    Mat4 mat = Mat4(5.0f);
//
//
//    float array[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
//    Mat4 matrixA = Mat4(array);
//    Mat4 matrixB = Mat4(array);
//
//    Mat4 matrixC = matrixA.multiply(matrixB);
//
//    Mat4 positiion = Mat4::translation(Vec3(2, 3, 4));
    
    Vec3 a(2.5f, 4.0f, 0.0f);
    Vec3 b(5.0f, 5.0f, 0.0f);

//    while (!window.closed()) {
//        window.clear();
////        double x, y;
////        window.getMousePosition(x, y);
////        std::cout << x << " , " << y << std::endl;
////
////        std::cout << c << std::endl;
////        std::cout << a << std::endl;
////
////        std::cout << matrixA << std::endl;
////        std::cout << matrixB << std::endl;
////
////        std::cout << matrixC << std::endl;
//
//        std::cout << a.dot( << std::endl;
//
//        if(window.isKeyPressed(GLFW_KEY_A))
//            std::cout << "a is pressed" << std::endl;
//        if(window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
//            std::cout << "mouse button left is pressed" << std::endl;
////        std::cout << window.getHeight() << " , " << window.getWidth() << std::endl;
//        glBegin(GL_TRIANGLES);
//        glVertex2d(-0.5f, -0.5f);
//        glVertex2d( 0.0f,  0.5f);
//        glVertex2d( 0.5f,  -0.5f);
//        glEnd();
//        glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
//        window.update();
//    }
    
    
    srand48(13);
    std::vector<Sphere> spheres;

    spheres.push_back(Sphere(Vec3( 0.0, -10004, -20), 10000, Vec3(0.20, 0.20, 0.20), 0, 0.0));
    
    // light
    spheres.push_back(Sphere(Vec3( 0.0,     20, -30),     3, Vec3(0.00, 0.00, 0.00), 0, 0.0, Vec3(3, 3, 3)));

    RayTracer::render(spheres);
    
    return 0;
}
    
                                    
