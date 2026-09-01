#include "Shader.h"
#include <glad/glad.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




#include <stdio.h>


void addChar(char *s, char c) {

    while (*s++);

    *(s - 1) = c;

    *s = '\0';
}

const char* ReadFileAsString(const char* filepath) {

    FILE* fptr;
    char* string_result = malloc(5000);

    fptr = fopen(filepath, "r");

    if (fptr == NULL) {
        fprintf(stderr, "File Opening Error");
        exit(1);
    }

	int c;

    while ((c = fgetc(fptr)) != EOF) {
			addChar( string_result, c);
	}

	return string_result;

}

GLuint CompileShader(GLenum type, const char* source_code) {
		GLuint shader = glCreateShader(type);

		glShaderSource(shader, 1,&source_code, 0);

		glCompileShader(shader);

		GLint isCompiled = 0;

		glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);

		if (isCompiled == GL_FALSE)
		{
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				GLchar infoLog[maxLength];
				glGetShaderInfoLog(shader, maxLength, &maxLength, infoLog);

				glDeleteShader(shader);

				fprintf(stderr, "Shader Compile Error %s", infoLog);

		}

		return shader;
}

void LoadFromGLSLTextFiles(const char* vertex_shader_path, const char* fragment_shader_path) {
		const char *vertex_source = ReadFileAsString(vertex_shader_path);
		const char *fragment_source = ReadFileAsString(fragment_shader_path);

		GLuint program = glCreateProgram();

		GLuint vertex_shader = CompileShader(GL_VERTEX_SHADER, vertex_source);
		glAttachShader(program, vertex_shader);

		GLuint fragment_shader = CompileShader(GL_FRAGMENT_SHADER, fragment_source);
		glAttachShader(program, fragment_shader);

		glLinkProgram(program);

		GLint is_linked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&is_linked);

		if (is_linked == GL_FALSE) {
				GLint max_length = 0;
				glGetProgramiv(program, GL_INFO_LOG_LENGTH, &max_length);

				char* infoLog[max_length];
				glGetProgramInfoLog(program, max_length, &max_length, infoLog[0]);

				glDeleteProgram(program);

				glDeleteShader(vertex_shader);
				glDeleteShader(fragment_shader);

				printf(stderr, "Shader Link Failure %s", infoLog);
				// HZ_CORE_ASSERT(false, "Shader link failure!");
		}
	
		glDetachShader(program, vertex_shader);
		glDetachShader(program, fragment_shader);
		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);

}

GLint CreateComputeShader(const char* filepath) {
		const char *shader_source = ReadFileAsString(filepath);

		GLuint shader_handle = glCreateShader(GL_COMPUTE_SHADER);

		const GLchar *source = (const GLchar*)shader_source;
		glShaderSource(shader_handle, 1, &source, 0);

		glCompileShader(shader_handle);

		GLint is_compiled = 0;

		if (is_compiled == GL_FALSE) {
				GLint max_length = 0;
				glGetShaderiv(shader_handle, GL_INFO_LOG_LENGTH, &max_length);

				GLchar *info_log[max_length];
				glGetShaderInfoLog(shader_handle, max_length, &max_length, info_log[0]);

				fprintf(stderr, "Compute Shader compilation error %s", (char *)info_log);

				glDeleteShader(shader_handle);
				return 0;
		}

		GLuint program = glCreateProgram();
		glAttachShader(program, shader_handle);
		glLinkProgram(program);

		GLint is_linked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&is_linked);

		if (is_linked == GL_FALSE) {
				GLint max_length = 0;
				glGetProgramiv(program, GL_INFO_LOG_LENGTH, &max_length);

				GLchar *info_log[max_length];
				glGetProgramInfoLog(program, max_length, &max_length, info_log[0]);

				fprintf(stderr, "Compute Shader Linking Error %s", (char*)&info_log);

				glDeleteProgram(program);
				glDeleteShader(shader_handle);

				return 0;
		}

		glDetachShader(program, shader_handle);
		return program;
}

GLint ReloadComputeShader(GLint ComputeID, const char* filepath) {
		glDeleteProgram(ComputeID);

		return CreateComputeShader(filepath);
}






        



















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


    


    



