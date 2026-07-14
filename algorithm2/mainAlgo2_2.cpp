#include <algorithm>
#include <iostream>
#include <set> 
#include <string>
#include <vector>

#include "graph_2_.cpp"
#include "bfs_2_.cpp"
#include "contruct_graph_2_.cpp"

int check_for_avaliable_trees(const std::vector<std::vector<int>> &matrix);
int main() {
  int edges = 0;
  int columns = 3;
  std::vector<std::vector<int>> matrix;
  std::cout << "=============Welcome to Project 3 Delivery Route "
               "Planning============="
            << std::endl;

  while (true) {
    std::cout << "Enter Number of Edge: ";
    if (std::cin >> edges && edges > 0) {
      break;
    } else {
      std::cout << "Invalid Input! Try Again\n" << std::endl;
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    }
  }

  matrix = std::vector<std::vector<int>>(edges, std::vector<int>(columns, 0));
  std::set<std::pair<int, int>> seen_edges;
  int max_vertex = -1;

  std::cout << "\n";
  std::cout << "=======Input edges and their weights=======\n\n";

  for (int i = 0; i < edges; i++) {
    int firstVertex = 0;
    int secondVertex = 0;
    int weight = 0;
    std::cout << "=====Edge #" << i + 1 << " =====\n";
    while (true) {
      
      std::cout << "Enter the first vertex: ";
      if (!(std::cin >> firstVertex)) {
        std::cout << "Invalid input! Please enter an integer; Try Again\n";
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        continue;
      }

      std::cout << "Enter the second vertex: ";
      if (!(std::cin >> secondVertex)) {
        std::cout << "Invalid input! Please enter an integer; Try Again\n";
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        continue;
      }

      if (firstVertex < 0 || secondVertex < 0) {
        std::cout << "Vertex indices must be non-negative. Please try again.\n";
        continue;
      }

      if (firstVertex == secondVertex) {
        std::cout << "Self-loops are not allowed. Please enter different vertices.\n\n";
        continue;
      }

      if (seen_edges.count({firstVertex, secondVertex})) {
        std::cout << "Edge already exists. Please enter different vertices.\n";
        continue;
      }
      while (true) {
        std::cout << "Enter the weight for edge: ";
        if ((std::cin >> weight)) {
           break;
        } else {
          std::cout << "Invalid input! Please enter an integer; Try Again\n";
          std::cin.clear();
          std::cin.ignore(9999, '\n');
        }
      }
      

      matrix[i][0] = firstVertex;
      matrix[i][1] = secondVertex;
      matrix[i][2] = weight;
      seen_edges.insert({firstVertex, secondVertex});
      max_vertex = std::max(max_vertex, std::max(firstVertex, secondVertex));
      break;
    }
  }

  int num_vertices = max_vertex + 1;
  Graph graph(num_vertices);
  graph.initialization(); // O(n)
  contruct_graph(edges, columns, graph, matrix);

  std::cout << "\nMatrix:\n";

  for (int r = 0; r < edges; r++) {
    for (int c = 0; c < columns; c++) {
      std::cout << matrix[r][c] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";

  int starting_vertex = 0;
  int target_vertex = 0;

  while (true) {
    std::cout << "Enter the starting vertex: ";
    if (std::cin >> starting_vertex && starting_vertex >= 0) {
      break;
    } else {
      std::cout << "Invalid input! Please enter a non-negative integer; Try Again\n";
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    }
  }

  while (true) {
    std::cout << "Enter the target vertex: ";
    if (std::cin >> target_vertex && target_vertex >= 0) {
      break;
    } else {
      std::cout << "Invalid input! Please enter a non-negative integer; Try Again\n";
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    }
  }

  int stopovers;
  while (true) {
    std::cout << "Enter the number of stopovers allowed: ";
    if (std::cin >> stopovers) {
      break;
    } else {
      std::cout << "Invalid input! Please enter an integer; Try Again\n";
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    }
  }

  int number_moves = minimum_moves(starting_vertex, target_vertex, graph,
                                     num_vertices, stopovers); // o(v + e)
  std::cout << "===============================================================================\n";
  std::cout << "Minimum cost from vertex " << starting_vertex << " to vertex "
            << target_vertex << " with at most " << stopovers
            << " stopovers is: " << number_moves << std::endl;
  std::cout << "===============================================================================\n";

  return 0;
}