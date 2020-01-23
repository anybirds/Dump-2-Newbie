#include <Scene.hpp>

#include <Common/World.hpp>

#include "scenewidget.h"

using namespace Engine;

SceneWidget::SceneWidget(QWidget *parent) : QOpenGLWidget(parent)
{

}

SceneWidget::~SceneWidget() {

}

void SceneWidget::initializeGL() {
    Scene scene; // replace this to Scene scene({""});
}

void SceneWidget::paintGL() {
    World::Render();
}

void SceneWidget::resizeGL(int w, int h) {

}


