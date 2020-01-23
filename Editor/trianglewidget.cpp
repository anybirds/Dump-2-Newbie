#include <engine.hpp>

#include "trianglewidget.h"

TriangleWidget::TriangleWidget(QWidget *parent) : QOpenGLWidget(parent)
{

}

TriangleWidget::~TriangleWidget() {

}

void TriangleWidget::initializeGL() {
    Engine::prepareTriangle();
}

void TriangleWidget::paintGL() {
    Engine::drawTriangle();
    update();
}

void TriangleWidget::resizeGL(int w, int h) {

}
