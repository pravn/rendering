//Writes an object file from cube data
//This is quite straight forward since the obj file format is rather 
//similar to how the vertex and index buffer data are laid out

#ifndef CUBE_UTILS_H
#define CUBE_UTILS_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class DumpObjfile{
public:
  DumpObjfile(const std::string objfilename_in, const std::string title_header_in, const Cube &cube)
  {
    filename = objfilename_in;
    title = title_header_in;

    create_file();
    create_title_header();
    write_mtl_filename();
    write_vertices(cube);
    write_faces(cube);
    std::cout << "Finished writing" << std::endl;
  }

  ~DumpObjfile(){
    std::cout << "Closing file" << std::endl;
    file_handle.close();
  }

  void create_file(){
    std::cout << "Writing into file: "<< filename << std::endl;
    file_handle.open(filename, std::ios::out);
  }

  void create_title_header(){
    std::cout << "In create_title_header" << std::endl;
    std::cout << "title_header: " << title << std::endl;

    file_handle << "#title";
    file_handle << std::endl;
    file_handle << "#";
    file_handle << title;
    file_handle << std::endl;
  }

  void write_vertices(const Cube &cube){
    file_handle << "#vertices" << std::endl;

    int N = cube.N;

    std::cout << "N=" << N << std::endl;

    //ordering 
    //front
    //back
    //right
    //left
    //top
    //bottom

    for (int ind=0; ind < 6*(N)*(N); ind++){
      //      int i = 3*ind;
      int v =3*ind;

      file_handle << "v" << space(4);
      file_handle << cube._vbo_cube_vertices[v] << space(1);
      file_handle << cube._vbo_cube_vertices[v+1] << space(1);
      file_handle << cube._vbo_cube_vertices[v+2] << space(1);
      file_handle << std::endl;
    }
    
    file_handle << std::endl;
  
  }      

  void write_mtl_filename(){
    file_handle << "mtllib a.mtl" << std::endl;
  }

  void write_faces(const Cube &cube){
    file_handle << "#faces/indices" << std::endl;
    file_handle << "usemtl red" << std::endl;

    int N = cube.N;

    //ordering 
    //front
    //back
    //right
    //left
    //top
    //bottom

    for(int ind=0; ind < 36*(N-1)*(N-1); ind+=6){
      //      std::cout << "ind=" << ind << std::endl;

      file_handle << "f" << space(4);
      file_handle << cube._ibo_cube_elements[ind]+1   << space(1);
      file_handle << cube._ibo_cube_elements[ind+1]+1 << space(1);
      file_handle << cube._ibo_cube_elements[ind+2]+1 << space(1);
      
      file_handle << std::endl;

      file_handle << "f" << space(4);
      file_handle << cube._ibo_cube_elements[ind+3]+1 << space(1);
      file_handle << cube._ibo_cube_elements[ind+4]+1 << space(1);
      file_handle << cube._ibo_cube_elements[ind+5]+1 << space(1);
      
      //      std::cout << "printed" << std::endl;
      file_handle << std::endl;
      file_handle << "#" << std::endl;
    }

    file_handle << std::endl;
  }

  std::string space(int n){
    if(n>24){
      std::cerr << "Space count should be less than 24" << std::endl;
    }
    
    std::ostringstream t;
    
    for(int i=0; i<n; i++){
      t << " ";
    }

    return t.str();
  }

    
    
      
      


private:
  std::ofstream file_handle;
  std::string filename;
  std::string title;
};
  
#endif      
      

    
		
    
    
  
  
    
    
  
    
    
    
    
    
    
    
