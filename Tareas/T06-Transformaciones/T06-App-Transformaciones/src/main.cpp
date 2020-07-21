//============================================================================
// Name        : YING YANG
// Editado   : Barrozo Figueroa Osti Katriel
//============================================================================



// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include "Utils.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

const float toRadians = 3.14159265f / 180.0f;

GLuint renderingProgram;
GLuint renderingProgram2;/////////KATRIEL
/*
GLfloat* m_Vertices;*/
GLuint n_Vertices;
GLuint m_VBO;
GLuint m_VAO;

////
GLuint m_VBO2;
GLuint m_VAO2;
////
float curAngle = 0.0f;

int dimVertices;//katriel
int numberOfVertices;//katriel---------------------------------

void init (GLFWwindow* window) {

	// Utils
	renderingProgram = Utils::createShaderProgram("src/vertShader.glsl", "src/fragShader.glsl");

	// Cria um ID na GPU para um array de  buffers
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);



	/////////////////////////////////////////////////////////////////////////////////////////////


	GLfloat radius = 0.8;//GLfloat radius = 0.5;//KATRIEL------------------------------------
	GLint numberOfSides = 800; // 50
	numberOfVertices = numberOfSides+1; // points + one center point
	GLfloat twicePi =  /*2.0f**/ M_PI;

	GLfloat verticesX[numberOfVertices*6];
	GLfloat verticesY[numberOfVertices*6];
	GLfloat verticesZ[numberOfVertices*6];

	GLfloat verticesc1[numberOfVertices*6];//KATRIEL------------------------------------
	GLfloat verticesc2[numberOfVertices*6];///KATRIEL------------------------------------
	GLfloat verticesc3[numberOfVertices*6];//KATRIEL------------------------------------



	//CIRCULO 1
	for (int i = 0; i < numberOfVertices; i++) {// int i = 1 //KATRIEL------------------------------------
		verticesX[i] =0.0 + (radius * cos(i * twicePi / numberOfSides));
		verticesY[i] = 0.0+ (radius * sin(i * twicePi / numberOfSides));
		verticesZ[i] = 0.0;

		verticesc1[i] = 0.0;//KATRIEL------------------------------------
		verticesc2[i] = 0.0;//KATRIEL------------------------------------
		verticesc3[i] = 0.0;//KATRIEL------------------------------------

	}


	//CIRCULO 2
	twicePi = 2.0f * M_PI;
	for (int i = numberOfVertices; i < numberOfVertices*2; i++) {
			verticesX[i] = 0.4 + (0.4 * cos(i * twicePi / numberOfSides));
			verticesY[i] = 0.0 + (0.4  * sin(i * twicePi / numberOfSides));
			verticesZ[i] = 0.0;


			verticesc1[i] = 0.0;//KATRIEL------------------------------------
			verticesc2[i] = 0.0;//KATRIEL------------------------------------
			verticesc3[i] = 0.0;//KATRIEL------------------------------------
	}

	//CIRCULO 3
		twicePi = 2.0f * M_PI;
		for (int i = numberOfVertices*2; i < numberOfVertices*3; i++) {
				verticesX[i] = -0.4 + (0.4 * cos(i * twicePi / numberOfSides));
				verticesY[i] = 0.0 + (0.4  * sin(i * twicePi / numberOfSides));
				verticesZ[i] = 0.0;


				verticesc1[i] = 1.0;//KATRIEL------------------------------------
				verticesc2[i] = 1.0;//KATRIEL------------------------------------
				verticesc3[i] = 1.0;//KATRIEL------------------------------------
		}


		//CIRCULO 4
				twicePi = 2.0f * M_PI;
				for (int i = numberOfVertices*3; i < numberOfVertices*4; i++) {
						verticesX[i] = 0.0 + (0.8 * cos(i * twicePi / numberOfSides));
						verticesY[i] = 0.0 + (0.8  * sin(i * twicePi / numberOfSides));
						verticesZ[i] = 0.0;


						verticesc1[i] = 0.0;//KATRIEL------------------------------------
						verticesc2[i] = 0.0;//KATRIEL------------------------------------
						verticesc3[i] = 0.0;//KATRIEL------------------------------------
				}
				//CIRCULO 5
								twicePi = 2.0f * M_PI;
								for (int i = numberOfVertices*4; i < numberOfVertices*5; i++) {
										verticesX[i] = 0.4 + (0.1 * cos(i * twicePi / numberOfSides));
										verticesY[i] = 0.0 + (0.1  * sin(i * twicePi / numberOfSides));
										verticesZ[i] = 0.0;


										verticesc1[i] = 1.0;//KATRIEL------------------------------------
										verticesc2[i] = 1.0;//KATRIEL------------------------------------
										verticesc3[i] = 1.0;//KATRIEL------------------------------------
								}

								//CIRCULO 6
												twicePi = 2.0f * M_PI;
												for (int i = numberOfVertices*5; i < numberOfVertices*6; i++) {
														verticesX[i] = -0.4 + (0.1 * cos(i * twicePi / numberOfSides));
														verticesY[i] = 0.0 + (0.1  * sin(i * twicePi / numberOfSides));
														verticesZ[i] = 0.0;


														verticesc1[i] = 0.0;//KATRIEL------------------------------------
														verticesc2[i] = 0.0;//KATRIEL------------------------------------
														verticesc3[i] = 0.0;//KATRIEL------------------------------------
												}






	dimVertices = (numberOfVertices*6) * 6;

	GLfloat m_Vertices[dimVertices];

	for (int i = 0; i < numberOfVertices*6; i++) {
		m_Vertices[i * 6] = verticesX[i];
		m_Vertices[i * 6 + 1] = verticesY[i];
		m_Vertices[i * 6 + 2] = verticesZ[i];


		m_Vertices[i * 6+3] = verticesc1[i];
		m_Vertices[i * 6 + 4] = verticesc2[i];
		m_Vertices[i * 6 + 5] = verticesc3[i];

	}


	//////////////////////////////////////////////////////////////////////////////////////////////



	// Cria um ID na GPU para nosso buffer
	glGenBuffers(1, &m_VBO);

	// Cria um ID na GPU para um array de  buffers
	glGenVertexArrays(1, &m_VAO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	// Reserva memoria na GPU para um TARGET receber dados
	// Copia esses dados pra essa área de memoria
	glBufferData(
			GL_ARRAY_BUFFER,	// TARGET associado ao nosso buffer
			dimVertices * sizeof(GLfloat),	// tamanho do buffer
			m_Vertices,			// Dados a serem copiados pra GPU
			GL_STATIC_DRAW		// Política de acesso aos dados, para otimização
		);

	glVertexAttribPointer(
			0,			// Lembra do (layout = 0 ) no vertex shader ? Esse valor indica qual atributo estamos indicando
			3,			// cada vertice é composto de 3 valores
			GL_FLOAT,	// cada valor do vértice é do tipo GLfloat
			GL_FALSE,	// Quer normalizar os dados e converter tudo pra NDC ? ( no nosso caso, já esta tudo correto, então deixamos como FALSE)
			6 * sizeof(GLfloat),// De quantos em quantos bytes, este atributo é encontrado no buffer ? No nosso caso 3 floats pros vertices + 3 floats pra cor = 6 floats
			(GLvoid*) 0	// Onde está o primeiro valor deste atributo no buffer. Nesse caso, está no início do buffer
		);

	glEnableVertexAttribArray(0);	// Habilita este atributo



	////////////////katriel-hoy////////////////////////
	// Faremos a mesma coisa pra cor de cada vértice
	glVertexAttribPointer(
			1,			// Lembra do (layout = 1 ) no vertex shader ? Esse valor indica qual atributo estamos indicando
			3,			// cada vertice é composto de 3 valores
			GL_FLOAT,	// cada valor do vértice é do tipo GLfloat
			GL_FALSE,	// Quer normalizar os dados e converter tudo pra NDC ? ( no nosso caso, já esta tudo correto, então deixamos como FALSE)
			6 * sizeof(GLfloat),// De quantos em quantos bytes, este atributo é encontrado no buffer ? No nosso caso 3 floats pros vertices + 3 floats pra cor = 6 floats
			(GLvoid*) (3 * sizeof(GLfloat))	// Onde está o primeiro valor deste atributo no buffer. Nesse caso, 3 floats após o início do buffer
		);

	glEnableVertexAttribArray(1);		// Habilita este atributo

	////////////////////////////////////////////////

	glBindVertexArray(0);



}

void display(GLFWwindow* window, double currentTime) {
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(renderingProgram);

	GLuint uniformModel = glGetUniformLocation(renderingProgram, "model");



   // gl_Position = model * vec4(0.4 * pos.x, 0.4 * pos.y, pos.z, 1.0);
	curAngle += 5.0f;//RAPIDES CUANDO AUMENTA>>>>
	if (curAngle >= 360)
	{
		curAngle -= 360;
	}

	// Matriz con elementos de valor 1
	glm::mat4 model(1.0f);//model(1.0f);
	//Giro Antihorario
	model = glm::rotate(model, curAngle *toRadians, glm::vec3(0.0f, 0.0f, -1.0f));//glm::vec3(0.0f, 0.0f, 1.0f));//ANTIHORARIO

	//Usando UniformMatrix
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	//Usando ProgramUniform
	//glProgramUniformMatrix4fv(renderingProgram, uniformModel, 1, GL_FALSE, glm::value_ptr(model));

	// Use este VAO e suas configurações
	glBindVertexArray(m_VAO);
	glPointSize(10.0f);//-----------------numberOfVertices*4
	glDrawArrays(GL_TRIANGLE_FAN,0,numberOfVertices); // glDrawArrays(GL_LINES, 0, 3);//--------------
	glBindVertexArray(0);

	///////////////CIRCULO 2
	glBindVertexArray(m_VAO);
		glPointSize(10.0f);//-----------------numberOfVertices*4
		glDrawArrays(GL_TRIANGLE_FAN,numberOfVertices,numberOfVertices); // glDrawArrays(GL_LINES, 0, 3);//--------------
		glBindVertexArray(0);

		///////////////CIRCULO 3
			glBindVertexArray(m_VAO);
				glPointSize(10.0f);//-----------------numberOfVertices*4
				glDrawArrays(GL_TRIANGLE_FAN,numberOfVertices*2,numberOfVertices); // glDrawArrays(GL_LINES, 0, 3);//--------------
				glBindVertexArray(0);

				///////////////CIRCULO 4
							glBindVertexArray(m_VAO);
								glPointSize(3.0f);//-----------------numberOfVertices*4
								glDrawArrays(GL_POINTS,numberOfVertices*3,numberOfVertices); // glDrawArrays(GL_LINES, 0, 3);//--------------
								glBindVertexArray(0);

								///////////////CIRCULO 5
										glBindVertexArray(m_VAO);
											glPointSize(10.0f);//-----------------numberOfVertices*4
											glDrawArrays(GL_TRIANGLE_FAN,numberOfVertices*4,numberOfVertices); // glDrawArrays(GL_LINES, 0, 3);//--------------
											glBindVertexArray(0);

											///////////////CIRCULO 6
														glBindVertexArray(m_VAO);
															glPointSize(10.0f);//-----------------numberOfVertices*4
															glDrawArrays(GL_TRIANGLE_FAN,numberOfVertices*5,numberOfVertices); // glDrawArrays(GL_LINES, 0, 3);//--------------
															glBindVertexArray(0);




	glUseProgram(0);
}
int main(void) {
    if (!glfwInit()) {
    	exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  //
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            //
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); 	// Resizable option.

    GLFWwindow* window = glfwCreateWindow(500, 500, "Barrozo Figueroa Osti Katriel", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
    	exit(EXIT_FAILURE);
    }
    glfwSwapInterval(1);

    init(window);
  // init2(window);//

    while (!glfwWindowShouldClose(window)) {
        display(window, glfwGetTime());
      //  display2(window, glfwGetTime());//
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
