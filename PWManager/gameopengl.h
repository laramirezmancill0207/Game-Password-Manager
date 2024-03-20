#ifndef GAMEOPENGL_H
#define GAMEOPENGL_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class GameOpenGL  : public QOpenGLWidget, public QOpenGLFunctions
{
	Q_OBJECT

public:
	GameOpenGL(QWidget *parent);
	~GameOpenGL();
protected:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int w, int h) override;

};

#endif