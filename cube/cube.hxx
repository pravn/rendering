#ifndef CUBE_H
#define CUBE_H

//#include <GL/gl.h>
#include <GL/glu.h>
//#include <GL/glut.h>
#include <vector>
#include <iostream>

struct vec3d{
  GLfloat x;
  GLfloat y;
  GLfloat z;
};

//Forward 
class Cube;
class DumpObjfile;

class Cube{
public:
  //the minimum number of vertices is 2 
Cube(int N_in=2){
  std::cout << "Cube!" << std::endl;
//nvertices=two*(nx*ny+ny*nz+nz*nz-nx-ny-nz)=six*(N*N-N)
//vertices = new GLfloat[3*six*(N*N-N)];  (for each x,y,z dimension; add another 3 for color (not implemented yet))
  N=N_in;
  //  _vbo_cube_vertices=new GLfloat[18*(N*N-N)];
  _vbo_cube_vertices = new GLfloat[18*N*N];
  _vbo_cube_colors   = new GLfloat[18*N*N];

//nindices=two*six*[(nx-1)*(ny-1)+(ny-1)*(nz-1)+(nz-1)*(nx-1)] = 36*(N-1)*(N-1)
//  _ibo_cube_elements=new GLint[36*(N-1)*(N-1)];
  _ibo_cube_elements = new GLuint[36*(N-1)*(N-1)];
  vbo_size = 18*N*N;
  ibo_size = 36*(N-1)*(N-1);
    

  h = (p1-p0)/(N-1);
}

  friend class DumpObjfile;

  GLfloat *get_colorbuffer_ptr() const{
    return &_vbo_cube_colors[0];
  }

GLfloat* get_VBO_ptr() const{
  return &_vbo_cube_vertices[0];
}

  GLint get_VBO_size() const{
    return sizeof(GLfloat)*vbo_size;
  }

  GLint get_IBO_size() const{
    return sizeof(GLuint)*ibo_size;
  }

  GLuint* get_IBO_ptr() const{
  return &_ibo_cube_elements[0];
}

  void assign_VertexCoord_vec3(GLfloat x, GLfloat y, GLfloat z, int i);
  void assign_VertexColor_vec3(GLfloat r, GLfloat g, GLfloat b, int i);
  void assign_FrontIndex_vec6(int ind, int vert);
  void assign_BackIndex_vec6(int ind, int vert);
  void assign_RightIndex_vec6(int ind, int vert);
  void assign_LeftIndex_vec6(int ind, int vert);
  void assign_TopIndex_vec6(int ind, int vert);
  void assign_BottomIndex_vec6(int ind, int vert);

  void set_VertexBuffer_data();
  void set_IndexBuffer_data();
  void print_IndexBuffer_data();
  void print_VertexBuffer_data();
  


~Cube(){
  std::cout << "Destryoing vbo and ibo" << std::endl;
  delete[] _vbo_cube_vertices;
  delete[] _vbo_cube_colors;
  delete[] _ibo_cube_elements;
}

private: 
  GLfloat *_vbo_cube_vertices;
  GLfloat *_vbo_cube_colors;
  GLuint *_ibo_cube_elements;

  int N;
  int vbo_size;
  int ibo_size;
  const float p0=-1.0;
  const float p1=+1.0;
  float h;
};


#endif


