#pragma once

#include "list_node_1_.cpp"

class Graph {
public:
    Graph() : total_vertices_(0) {}
    Graph(int vertices) : total_vertices_(vertices) {}

    void initialization() {
        adjacencylist = new Node*[total_vertices_];
        for (int i = 0; i < total_vertices_; i++) {
            adjacencylist[i] = nullptr;
        }
    }

    void addEdge(int current, int target, int weight) {
        Node* newNode = new Node;
        newNode->setID(target);
        newNode->setWeight(weight);
        newNode->setNext(adjacencylist[current]);
        adjacencylist[current] = newNode;
    }

    bool checkEdge(int current, int target) {
        Node* temp = adjacencylist[current];
        while (temp != nullptr) {
            if (temp->getID() == target) {
                return true;
            }
            temp = temp->getNext();
        }
        return false;
    }

    int getTotalVertices() const {
        return total_vertices_;
    }

    void setTotalVertices(int v) {
        total_vertices_ = v;
    }

    Node** getAdjacencylist() {
        return this->adjacencylist;
    }

private:
    int total_vertices_;
    Node** adjacencylist;
};
