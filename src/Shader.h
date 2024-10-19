#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
public:
  unsigned int ID;

  // build the shader program from 2 file paths
  Shader(const std::string &vertexPath, const std::string &fragmentPath);

  // activate the shader program
  void use() const;

  void setBool(const std::string &name, bool value) const;
  void setInt(const std::string &name, int value) const;
  void setFloat(const std::string &name, float value) const;
  void setVector4(const std::string &name, float x, float y, float z,
                  float w) const;

private:
  // use to check for linking/compilation errors
  void checkCompileErrors(unsigned int shader, std::string type);
};

#endif
