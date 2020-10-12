#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

void drawTriangle();
void drawAxes();

int main() {
	float r = 0.1f;

	cout << "Koko" << endl;
	if (!glfwInit()) {
		cout << "Failed to init glfw" << endl;
		glfwTerminate();
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(800, 600, "Graphics Test", NULL, NULL);

	if (window == NULL) {
		cout << "Failed to create window";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glViewport(0, 0, 800, 600);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		drawAxes();

		glPushMatrix();
		//glTranslatef(-0.5f, -0.5f, 1.0f);
		glRotatef((450 * (3.1415 / 180)) , 0.0f, 0.0f, 1.0f);
		//glTranslatef(0.5f, 0.5f, 1.0f);
		drawTriangle();
		glPopMatrix();

		r += 0.1;

		glPushMatrix();
		glScalef(1.0f, -1.0f, 0.0f);
		drawTriangle();
		glPopMatrix();

		glPushMatrix();
		glScalef(-1.0f, -1.0f, 0.0f);
		drawTriangle();
		glPopMatrix();

		glPushMatrix();
		glScalef(-1.0f, 1.0f, 0.0f);
		drawTriangle();
		glPopMatrix();

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

void drawTriangle() {
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.25f, 0.25f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.5f, 0.75f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.75f, 0.25f);
	glEnd();
}

void drawAxes() {
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2f(0.0f, 1.0f);
	glVertex2f(0.0f, -1.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(1.0f, 0.0f);
	glVertex2f(-1.0f, 0.0f);
	glEnd();
}