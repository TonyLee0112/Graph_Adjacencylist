#pragma once
#include "Graph.h"
// Dijkstra�� �ִ� ��� �˰���
void Graph :: dijkstraShortestPath(int start) {
    // �ִ� ��θ� �����ϴ� �迭
    vector<int> distance(vertices, INT_MAX);

    // �ش� ������ �̹� ó���Ǿ����� ���θ� �����ϴ� �迭
    vector<bool> processed(vertices, false);

    // ���� ���������� �Ÿ��� 0
    distance[start] = 0;

    // Dijkstra �˰��� ����
    for (int count = 0; count < vertices - 1; count++) {
        int currentVertex = -1;
        int minDistance = INT_MAX;

        // ���� ó������ ���� ���� �߿��� �ִ� ��θ� ���� ������ ã��
        for (int i = 0; i < vertices; i++) {
            if (!processed[i] && distance[i] < minDistance) {
                currentVertex = i;
                minDistance = distance[i];
            }
        }

        // ã�� ������ ó���� ������ ǥ��
        processed[currentVertex] = true;

        // ���� �������� �� �� �ִ� ��� �������� ��ȸ
        for (const auto& edge : adjacencyList[currentVertex]) {
            int nextVertex = edge.toward;
            int weight = edge.weight;

            // �� ª�� ��θ� �߰��ϸ� ������Ʈ
            if (!processed[nextVertex] && distance[currentVertex] + weight < distance[nextVertex]) {
                distance[nextVertex] = distance[currentVertex] + weight;
            }
        }
    }

    // �ִ� ��� ���
    cout << "Shortest paths from vertex " << start << " to other vertices:" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "To vertex " << i << ": " << distance[i] << endl;
    }
}