#pragma once
#include "Graph.h"
// Dijkstra의 최단 경로 알고리즘
void Graph :: dijkstraShortestPath(int start) {
    // 최단 경로를 저장하는 배열
    vector<int> distance(vertices, INT_MAX);

    // 해당 정점이 이미 처리되었는지 여부를 저장하는 배열
    vector<bool> processed(vertices, false);

    // 시작 정점까지의 거리는 0
    distance[start] = 0;

    // Dijkstra 알고리즘 실행
    for (int count = 0; count < vertices - 1; count++) {
        int currentVertex = -1;
        int minDistance = INT_MAX;

        // 아직 처리되지 않은 정점 중에서 최단 경로를 가진 정점을 찾음
        for (int i = 0; i < vertices; i++) {
            if (!processed[i] && distance[i] < minDistance) {
                currentVertex = i;
                minDistance = distance[i];
            }
        }

        // 찾은 정점을 처리된 것으로 표시
        processed[currentVertex] = true;

        // 현재 정점에서 갈 수 있는 모든 정점들을 순회
        for (const auto& edge : adjacencyList[currentVertex]) {
            int nextVertex = edge.toward;
            int weight = edge.weight;

            // 더 짧은 경로를 발견하면 업데이트
            if (!processed[nextVertex] && distance[currentVertex] + weight < distance[nextVertex]) {
                distance[nextVertex] = distance[currentVertex] + weight;
            }
        }
    }

    // 최단 경로 출력
    cout << "Shortest paths from vertex " << start << " to other vertices:" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "To vertex " << i << ": " << distance[i] << endl;
    }
}