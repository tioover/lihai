#pragma once

#include <vector>
#include <option.h>

using GraphValue = int;


class Edge {
    friend class Graph;

    size_t target;
    Option<size_t> next_outgoing;
public:
    Edge(size_t target, size_t next_outgoing) :
            target(target), next_outgoing(next_outgoing) {}

    Edge(size_t target) : target(target), next_outgoing(Option<size_t>()) {}
};

class Vertex {
    friend class Graph;

    GraphValue value;
    Option<size_t> outgoing_edge;
public:
    Vertex(GraphValue value, size_t outgoing) :
            value(value), outgoing_edge(Option<size_t>(outgoing)) {}

    Vertex(GraphValue value) : value(value), outgoing_edge(Option<size_t>()) {}
};


class Graph {
    friend class Edge;

    std::vector<Edge> edges{};
    std::vector<Vertex> vertices{};
public:
    size_t add_vertex(Vertex vertex) {
        vertices.push_back(vertex);
        return vertices.size() - 1;
    }

    size_t add_edge(size_t source, size_t target) {
        Vertex &vertex = vertices[source];
        size_t edge_len = edges.size();
        if (vertex.outgoing_edge.is_none()) {
            vertex.outgoing_edge = Option<size_t>(edge_len);
        } else {
            size_t i = vertex.outgoing_edge.get();
            while (!edges[i].next_outgoing.is_none()) {
                i = edges[i].next_outgoing.get();
            }
            edges[i].next_outgoing = Option<size_t>(edge_len);
        }
        edges.push_back(Edge(target));
        return edge_len;
    }
};
