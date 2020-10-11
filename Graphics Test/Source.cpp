#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

int main() {
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

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//glPushMatrix();
		glRotatef(1.0f, 0.0f, 0.0f, 1.0f);

		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-0.5f, -0.5f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.0f, 0.5f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		//glPopMatrix();

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}