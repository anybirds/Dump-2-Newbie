#ifndef TRIANGLEWIDGET_H
#define TRIANGLEWIDGET_H

#include <QOpenGLWidget>

class TriangleWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    TriangleWidget(QWidget *parent = nullptr);
    ~TriangleWidget();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
};

#endif // TRIANGLEWIDGET_H
