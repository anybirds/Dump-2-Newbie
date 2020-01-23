#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QOpenGLWidget>

class SceneWidget : public QOpenGLWidget
{
public:
    SceneWidget(QWidget *parent = nullptr);
    ~SceneWidget();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
};

#endif // SCENEWIDGET_H
