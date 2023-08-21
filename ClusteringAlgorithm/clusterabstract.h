#ifndef CLUSTERABSTRACT_H
#define CLUSTERABSTRACT_H

#include <QObject>

class ClusterAbstract : public QObject
{
    Q_OBJECT
public:
    explicit ClusterAbstract(QObject *parent = nullptr);
    virtual ~ClusterAbstract();

};

#endif // CLUSTERABSTRACT_H
