#include "Shader.h"
#include <glad/glad.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




#include <stdio.h>

const char* ReadFileAsString(const char* filepath) {

    char result_ptr[5000]
    FILE* fptr;
    char string[256];

    fptr = fopen(filepath, "r");

    if (fptr == NULL) {
        fprintf(stderr, "File Opening Error");
        exit(1);
    }
    
    while ((string = fgets(fptr)))
        strcat(result_str, c);
        

        



















GLuint CompileShader(GLenum type, const GLchar* source) {

    GLuint shader = glCreateShader(type);

    glShaderSource(shader, 1, source, 0);

    glCompileShader(shader);

    GLint isCompiled = 0;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);

    if (isCompiled == GL_FALSE) {

        GLint maxLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);        

        char* infoLog = malloc(maxLength);

        glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

        glDeleteShader(shader);

        fprintf(stderr, infoLog);
        fprintf(stderr, "Shader Compilation Error");

    }

    return shader;
}

LoadFromGLSLTextFiles(const char* vertexShaderPath, const char* fragmentShaderPath) {
    const char* vertexSource = ReadFileAs


    


    



