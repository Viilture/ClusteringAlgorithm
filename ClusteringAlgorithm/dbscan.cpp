#include "dbscan.h"

using namespace std;

DBSCAN::DBSCAN(QObject *parent) : ClusterAbstract(parent)
{

}

DBSCAN::~DBSCAN()
{

}

void DBSCAN::clustering(const vector<QPointF>& points, vector<int>& labels, double eps, int minPts)
{
    int n = points.size();
    int clusterIdx = 1;

    vector<bool> visited(n, false);
    vector<bool> noise(n, false);

    for (int i = 0; i < n; ++i) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        vector<int> neighbors;

        for (int j = 0; j < n; ++j) {
            if (sqrt(pow(points[i].x() - points[j].x(), 2) + pow(points[i].y() - points[j].y(), 2)) <= eps) {
                neighbors.push_back(j);
            }
        }

        if (neighbors.size() < minPts) {
            noise[i] = true;
        } else {
            labels[i] = clusterIdx;

            for (int j = 0; j < neighbors.size(); ++j) {
                int neighborIdx = neighbors[j];

                if (!visited[neighborIdx]) {
                    visited[neighborIdx] = true;
                    vector<int> neighborNeighbors;

                    for (int k = 0; k < n; ++k) {
                        if (sqrt(std::pow(points[neighborIdx].x() - points[k].x(), 2) + pow(points[neighborIdx].y() - points[k].y(), 2)) <= eps) {
                            neighborNeighbors.push_back(k);
                        }
                    }

                    if (neighborNeighbors.size() >= minPts) {
                        neighbors.insert(neighbors.end(), neighborNeighbors.begin(), neighborNeighbors.end());
                    }
                }

                if (labels[neighborIdx] == 0) {
                    labels[neighborIdx] = clusterIdx;
                }
            }

            clusterIdx++; // Увеличиваем clusterIdx для следующего кластера
        }
    }

    for (int i = 0; i < n; ++i) {
        if (noise[i]) {
            labels[i] = 0;
        }
    }
}


