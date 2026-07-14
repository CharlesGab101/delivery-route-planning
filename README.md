# CPSC 335: Algorithm Engineering - Project 3: Delivery Route Planning

## 👥 Team

| Name | Role / Email |
| --- | --- |
| **Charles Edwill Gabut** | Student ([charles_g@csu.fullerton.edu](mailto:charles_@csu.fullerton.edu)) |

---

## 🛠 Project Components

### 1. Delivery Route Planning (Project 3 - Part 2)
An optimization algorithm designed to find the cheapest path between a starting location and a target destination given a strictly limited number of stopovers (stops/connections).
*   **Objective:** Find the minimum travel cost from a starting vertex to a target vertex while ensuring the path does not exceed $k$ allowed stopovers.
*   **Logic:**
    *   **Graph Representation:** Utilizes a custom Graph class built with dynamically allocated Adjacency Lists of Nodes, mapping connections (edges) and their associated weights (costs).
    *   **Bellman-Ford / BFS Variant Traversal:** Explores the graph step-by-step from the starting vertex. By tracking distance tables relative to the number of stopovers allowed, it limits the relaxation steps to $k+1$ iterations. This ensures that any path exceeding the stopover limit is ignored, ultimately returning the minimum accumulated cost (or `-1` if unreachable).
*   **Efficiency:** 
    *   **Time Complexity:** $\mathcal{O}(k \times (V + E))$ where $V$ is the number of vertices, $E$ is the number of edges, and $k$ is the number of allowed stopovers. The algorithm iterates at most $k+1$ times, relaxing the edges of visited nodes.
    *   **Space Complexity:** $\mathcal{O}(V + E)$ to maintain the custom adjacency list structure and memory arrays used to track current costs across iterations.

---

## 💻 Tech Stack

| Category | Tools / Concepts |
| --- | --- |
| **Language** | C++ (Standard C++17) |
| **Algorithms** | Shortest Path Optimization, Bellman-Ford/BFS Traversal |
| **Data Structures** | Custom Directed Weighted Graph (Adjacency List), Custom Linked Nodes, Vectors |

---

## 🚀 Getting Started

### Compilation
To compile the **Delivery Route Planning** executable, run the following command in your terminal:
```bash
algorithm_two_2_.sh
