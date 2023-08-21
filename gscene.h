#ifndef GSCENE_H
#define GSCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSharedPointer>
#include <QWidget>
#include <QRectF>
#include <QMouseEvent>
#include <QGraphicsEllipseItem>
#include <QVector>
#include <QTime>
#include <QCursor>
#include <vector>
#include <QDebug>

#include "ClusteringAlgorithm/dbscan.h"

// Создаем массив с цветами для каждой метки кластера
static QColor clusterColors[] = {
    Qt::transparent,
    Qt::red,
    Qt::green,
    Qt::yellow,
    Qt::cyan,
    Qt::magenta,
    Qt::gray,
    Qt::darkRed,
    Qt::darkGreen,
    Qt::darkYellow,
    Qt::darkCyan,
    Qt::darkMagenta,
    Qt::darkGray,
    Qt::lightGray,
    Qt::black,
    Qt::white,
    QColor(255, 165, 0),        // Оранжевый
    QColor(128, 0, 128),        // Пурпурный
    QColor(0, 128, 128),        // Темно-бирюзовый
    QColor(255, 0, 255),        // Фуксия
    QColor(128, 128, 0),        // Оливковый
    QColor(0, 255, 0),          // Лайм
    QColor(255, 0, 0),          // Красный
    QColor(128, 0, 0),          // Темно-коричневый
    QColor(0, 128, 0),          // Зеленый
    QColor(128, 128, 128),      // Серый
    QColor(192, 192, 192),      // Серебряный
    QColor(255, 255, 0),        // Желтый
    QColor(255, 255, 255),      // Белый
};

class GScene : public QGraphicsView
{
    Q_OBJECT

    QVector<QGraphicsEllipseItem*> vecEllipse;

    QSharedPointer<DBSCAN> scan;

    bool mouseMoveState = false;

public:
    explicit GScene(QWidget* object = nullptr);
    virtual ~GScene();

    int32_t DBscaning(int32_t radius, int32_t points);

    void mouseMoveCreate();

    void cleaning();

    QSharedPointer<DBSCAN> getScan() const;

    const QVector<QGraphicsEllipseItem *> &getVecEllipse() const;

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
};

#endif
