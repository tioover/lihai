#pragma once

#include <vector>
#include "option.h"


namespace {
    struct Edge {
        size_t target;
        size_t next;
        bool empty;
        Edge(size_t target, size_t next_outgoing):
                target(target), next(next_outgoing), empty(false) {}
        Edge(): empty(true) {}
    };

    template <typename T>
    struct Vertex {
        using Value = T;
        Value value;
        size_t outgoing_edges;
        Vertex(Value value, size_t outgoing): value(value), outgoing_edges(outgoing) {}
    };
}

template <typename T>
class Graph {
    std::vector<Edge> edges {};
    std::vector<Vertex<T>> vertices {};

public:
    using Value = T;
    size_t add_vertex(Value value) {
        size_t edge_id = edges.size(), vertex_id = vertices.size();
        edges.push_back(Edge());
        vertices.push_back(Vertex<T>(value, edge_id));
        return vertex_id;
    }

    size_t add_edge(size_t source, size_t target) {
        size_t i = vertices[source].outgoing_edges;
        while (!edges[i].empty) {
            if (edges[i].target == target) return i;
            i = edges[i].next;
        }
        edges[i].empty = false;
        edges[i].target = target;
        edges[i].next = edges.size();
        edges.push_back(Edge());
        return i;
    }

    Value get(size_t vertex_index) {
        return vertices[vertex_index].value;
    }
};

