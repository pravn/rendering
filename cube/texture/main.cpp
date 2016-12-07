#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <string>

GLuint texId;
int w=800;
int h=600;
int winId;

GLuint loadTexture(const std::string fileName, int &width, int &height);


void initGL(int *argc, char **argv){
  glutInit(argc, argv);
   glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(w,h);
  winId=glutCreateWindow("logo");
  GLenum err = glewInit();
  glEnable(GL_DEPTH_TEST);


  int width=0;
  int height=0;

  std::string fileName="2.png";
  texId =loadTexture(fileName, width, height);
  std::cout << "texId=" << texId << std::endl;
}
 

 
static void display(){
}

static void key(unsigned char key, int, int){
  switch(key){

  case 27:
  case 'q':
  case 'Q':
    std::cout << " Called 'quit' " << std::endl;
    glutDestroyWindow(winId);
    exit(0);
  }
}


int main(int argc, char **argv){
  initGL(&argc, argv);
  glutDisplayFunc(display);
  glutKeyboardFunc(key);
  glutMainLoop();
  return 0;
}
  

  

  
