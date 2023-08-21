#include "gscene.h"


GScene::GScene(QWidget* parent) : QGraphicsView(parent)
{
    QGraphicsScene* scene = new QGraphicsScene(this);

    setScene(scene);

    scan = QSharedPointer<DBSCAN>::create();
}

GScene::~GScene()
{

}

const QVector<QGraphicsEllipseItem *> &GScene::getVecEllipse() const
{
    return vecEllipse;
}

QSharedPointer<DBSCAN> GScene::getScan() const
{
    return scan;
}

int32_t GScene::DBscaning(int32_t radius, int32_t points)
{
    QTime time = QTime::currentTime();

    std::vector<QPointF> vecPoint;
    std::vector<int> labels;

    for(auto &it:vecEllipse)
    {
        vecPoint.push_back(it->pos());
        labels.push_back(0);
    }

    scan->clustering(vecPoint, labels, radius, points);

    int numColors = sizeof(clusterColors) / sizeof(clusterColors[0]);

    for(int i = 0; i < vecPoint.size(); i++)
    {
        int label = labels[i] % numColors;
        vecEllipse.at(i)->setBrush(QBrush(clusterColors[label]));
        vecEllipse.at(i)->update();
    }
    return QTime::currentTime().msecsSinceStartOfDay() - time.msecsSinceStartOfDay();
}

void GScene::mouseMoveCreate()
{
    mouseMoveState ^= 1;
}

void GScene::cleaning()
{
    for(auto it: vecEllipse)
    {
        scene()->removeItem(it);
    }

    vecEllipse.clear();
}

void GScene::mousePressEvent(QMouseEvent *event)
{
    QTime time = QTime::currentTime();
    QGraphicsEllipseItem* item = scene()->addEllipse(QRectF(-5, -5, 10, 10));
    item->setPos(mapToScene(event->pos()));

    vecEllipse.push_back(item);
}

void GScene::mouseMoveEvent(QMouseEvent *event)
{
    if(!mouseMoveState) return;

    QGraphicsEllipseItem* item = scene()->addEllipse(QRectF(-5, -5, 10, 10));
    item->setPos(mapToScene(event->pos()));

    vecEllipse.push_back(item);

    std::vector<QPointF> vecPoint;
    std::vector<int> labels;

    for(auto &it:vecEllipse)
    {

        vecPoint.push_back(it->pos());
        labels.push_back(1);
    }
}
