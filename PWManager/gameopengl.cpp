#include "gameopengl.h"
#include <QSurfaceFormat>
#include <QOpenGLFunctions>

GameOpenGL::GameOpenGL(QWidget *parent)
	: QOpenGLWidget(parent)
{
	QSurfaceFormat format;
	format.setDepthBufferSize(24);
	format.setStencilBufferSize(8);
	format.setVersion(3, 2);
	format.setProfile(QSurfaceFormat::CoreProfile);
	QSurfaceFormat::setDefaultFormat(format);
}

GameOpenGL::~GameOpenGL()
{}


void GameOpenGL::initializeGL()
{
	this->initializeOpenGLFunctions();
}

void GameOpenGL::paintGL()
{
	glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 1.0f);

	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);

	glEnd();
	glFlush();
}
void GameOpenGL::resizeGL(int w, int h)
{

}
