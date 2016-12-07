#include "cube.hxx"
  //inline hint
void Cube::assign_VertexCoord_vec3(GLfloat x, GLfloat y, GLfloat z,int ind){
  int i = 3*ind;

  //  std::cout << "Cube::assign_vertex_vec3() x y z " << i << " " << 
  //    x << " " << y << " " << z << " " << std::endl;
    _vbo_cube_vertices[i]=x;
    _vbo_cube_vertices[i+1]=y;
    _vbo_cube_vertices[i+2]=z;

  }

void Cube::assign_VertexColor_vec3(GLfloat r, GLfloat g, GLfloat b, int ind){
  int i = 3*ind;

  _vbo_cube_colors[i]=r;
  _vbo_cube_colors[i+1]=g;
  _vbo_cube_colors[i+2]=b;
}

  //inline hint
void Cube::assign_FrontIndex_vec6(int ind, int vert)
  {

    /* 
     *   *
     *   *

     *   *               *
     *               *   *    

     */

    int i = 6*ind;

    _ibo_cube_elements[i]=vert;
    _ibo_cube_elements[i+1]=vert+1;
    _ibo_cube_elements[i+2]=vert+N+1;
    _ibo_cube_elements[i+3]=vert+N+1;
    _ibo_cube_elements[i+4]=vert+N;
    _ibo_cube_elements[i+5]=vert;

  }


void Cube::assign_BackIndex_vec6(int ind, int vert_in)
  {

    /* 
     *   *
     *   *

     *   *               *
     *               *   *    

     */

    int i = 6*(N-1)*(N-1)+6*ind;
    int vert = vert_in + N*N;

    //    std::cout << "ind=" << ind << std::endl;


    _ibo_cube_elements[i]=vert+1;
    _ibo_cube_elements[i+1]=vert;
    _ibo_cube_elements[i+2]=vert+N;

    _ibo_cube_elements[i+3]=vert+N;
    _ibo_cube_elements[i+4]=vert+N+1;
    _ibo_cube_elements[i+5]=vert+1;


    /*    std::cout << _ibo_cube_elements[i] << _ibo_cube_elements[i+1] << _ibo_cube_elements[i+2] 
	      << _ibo_cube_elements[i+3] << _ibo_cube_elements[i+4] << _ibo_cube_elements[i+5]  
	      << std::endl;
    */



  }

void Cube::assign_RightIndex_vec6(int ind, int vert_in){
  int i= 12*(N-1)*(N-1)+6*ind;
  int vert = vert_in+2*N*N;

  _ibo_cube_elements[i] = vert+1;
  _ibo_cube_elements[i+1] = vert;
  _ibo_cube_elements[i+2] = vert+N;
  
  _ibo_cube_elements[i+3] = vert+N;
  _ibo_cube_elements[i+4] = vert+N+1;
  _ibo_cube_elements[i+5] = vert+1;

  /*    std::cout << _ibo_cube_elements[i] << _ibo_cube_elements[i+1] << _ibo_cube_elements[i+2] 
	      << _ibo_cube_elements[i+3] << _ibo_cube_elements[i+4] << _ibo_cube_elements[i+5]  
	      << std::endl;*/

}

void Cube::assign_LeftIndex_vec6(int ind, int vert_in){
  int i= 18*(N-1)*(N-1)+6*ind;
  int vert = vert_in+3*N*N;

  _ibo_cube_elements[i] = vert;
  _ibo_cube_elements[i+1] = vert+1;
  _ibo_cube_elements[i+2] = vert+N+1;
  
  _ibo_cube_elements[i+3] = vert+N+1;
  _ibo_cube_elements[i+4] = vert+N;
  _ibo_cube_elements[i+5] = vert;




}

void Cube::assign_TopIndex_vec6(int ind, int vert_in){
  int i= 24*(N-1)*(N-1)+6*ind;
  int vert = vert_in+4*N*N;

  _ibo_cube_elements[i] = vert+1;
  _ibo_cube_elements[i+1] = vert;
  _ibo_cube_elements[i+2] = vert+N;
  
  _ibo_cube_elements[i+3] = vert+N;
  _ibo_cube_elements[i+4] = vert+N+1;
  _ibo_cube_elements[i+5] = vert+1;

}

void Cube::assign_BottomIndex_vec6(int ind, int vert_in){
  int i= 30*(N-1)*(N-1)+6*ind;
  int vert = vert_in+5*N*N;

  _ibo_cube_elements[i] = vert;
  _ibo_cube_elements[i+1] = vert+1;
  _ibo_cube_elements[i+2] = vert+N+1;
  
  _ibo_cube_elements[i+3] = vert+N+1;
  _ibo_cube_elements[i+4] = vert+N;
  _ibo_cube_elements[i+5] = vert;


}



//single process
void Cube::set_VertexBuffer_data(){

  std::cout <<"Cube::set_VertexBuffer_data()" << std::endl;

  GLfloat a;    
  GLfloat b;

  int i;
  int j;


  //xy
  //front
  for(int ind=0; ind<N*N; ind++){//for each vertex index 
   i=ind/N;
   j=ind%N;

    a = p0+j*h;
    b = p0+i*h;

    //front (xy)
    assign_VertexCoord_vec3(a,b,1.0,ind);
    assign_VertexColor_vec3(1.0,0,0.0, ind);
  }

  //  print_VertexBuffer_data();

  
    //back
  for(int ind=0; ind <N*N; ind++){
    i=ind/N;
    j=ind%N;
    
    a = p0+j*h;
    b = p0+i*h;
    
    assign_VertexCoord_vec3(a,b,-1.0, N*N+ind);
    assign_VertexColor_vec3(1.0,0.0,0.0, N*N+ind);
  }


  //    print_VertexBuffer_data();


    //right
  for(int ind=0; ind <N*N; ind++){
    i=ind/N;
    j=ind%N;
    
    a = p0+j*h;
    b = p0+i*h;
    
    assign_VertexCoord_vec3(1,a,b, 2*N*N+ind);
    assign_VertexColor_vec3(0.0,0.0,0.0, 2*N*N+ind);
  }

  //left
  for(int ind=0; ind <N*N; ind++){
    i=ind/N;
    j=ind%N;
    
    a = p0+j*h;
    b = p0+i*h;
    
    assign_VertexCoord_vec3(-1,a,b, 3*N*N+ind);
    assign_VertexColor_vec3(0.0,0.0,0.0, 3*N*N+ind);
  }

  //top
  for(int ind=0; ind <N*N; ind++){
    i=ind/N;
    j=ind%N;
    
    a = p0+j*h;
    b = p0+i*h;
    
    assign_VertexCoord_vec3(a,1.0,b, 4*N*N+ind);
    assign_VertexColor_vec3(0.0,1.0,0.0, 4*N*N+ind);
  }

  //bottom
  for(int ind=0; ind <N*N; ind++){
    i=ind/N;
    j=ind%N;
    
    a = p0+j*h;
    b = p0+i*h;
    
    assign_VertexCoord_vec3(a,-1.0,b, 5*N*N+ind);
    assign_VertexColor_vec3(0.0,1.0,0.0, 5*N*N+ind);
  }

}

void Cube::set_IndexBuffer_data(){ 
  std:: cout << "Cube::set_IndexBuffer_data()" << std::endl;
  int ind;
  int vert;
    for(int i=0; i<N-1; i++)
      for(int j=0; j<N-1; j++){
    //xy(2), yz(2), zx(2) 
	ind = i*(N-1)+j;
	vert = N*i+j;
		assign_FrontIndex_vec6(ind,vert);
		assign_BackIndex_vec6(ind, vert);
		assign_RightIndex_vec6(ind, vert);
		assign_LeftIndex_vec6(ind, vert);
		assign_TopIndex_vec6(ind, vert);
		assign_BottomIndex_vec6(ind, vert);
      }
}


void Cube::print_IndexBuffer_data(){
  std::cout << "IBO:"  << std:: endl;

  for(int ind=0; ind <24*(N-1)*(N-1); ind+=6){
    std::cout << ind << "::" << _ibo_cube_elements[ind] <<
      " " << _ibo_cube_elements[ind+1] << 
      " " << _ibo_cube_elements[ind+2] << 
      "    " << _ibo_cube_elements[ind+3] << 
      " " << _ibo_cube_elements[ind+4] << 
      " " << _ibo_cube_elements[ind+5] << std:: endl;
  }
}

void Cube::print_VertexBuffer_data(){
  std::cout << "VBO: " << std::endl;
  for(int i=0; i<9*N*N; i+=3){
    std::cout << i << " " << _vbo_cube_vertices[i] 
	      << " " << _vbo_cube_vertices[i+1] 
	      << " " << _vbo_cube_vertices[i+2] 
	      << std::endl;
  }
}
    
