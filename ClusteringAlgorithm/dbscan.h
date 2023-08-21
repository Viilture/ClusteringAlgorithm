#ifndef DBSCAN_H
#define DBSCAN_H

#include <QObject>
#include <QPointF>

#include <vector>
#include <math.h>

#include "clusterabstract.h"
using namespace std;

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

class DBSCAN : public ClusterAbstract
{
    Q_OBJECT
public:
    explicit DBSCAN(QObject *parent = nullptr);
    virtual ~DBSCAN();


    void clustering(const vector<QPointF>& points, vector<int>& labels, double eps, int minPts);
};

#endif // DBSCAN_H
