#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
public:
  unsigned int ID;

  // build the shader program from 2 file paths
  Shader(const std::string &vertexPath, const std::string &fragmentPath);

  // activate the shader program
  void use();

private:
  // use to check for linking/compilation errors
  void checkCompileErrors(unsigned int shader, std::string type);
};

#endif
