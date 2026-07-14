 #include <vector>
#include "graph_2_.cpp"
// conversion of matrix 2d indexes into vertex in the graph
void contruct_graph(int rows, int columns, Graph& graph, const std::vector<std::vector<int>>& matrix) {
    for (int r = 0; r < rows; r++) {
        graph.addEdge(matrix[r][0], matrix[r][1], matrix[r][2]); // add edge from [r][0] to [r][1] and thge weight is [r][2]
    }
}
