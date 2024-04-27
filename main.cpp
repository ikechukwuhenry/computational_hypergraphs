#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Hypergraph
{
    private:
        // Map or dictionary of vertices to their incident hypergraph
        unordered_map<int, vector<int>> vertextToHyperedges;

        // Map or dictionary of hyperedges to their incident vertices
        unordered_map<int, vector<int>> hyperedgeToVertices;

    public:
        // Add a vertex to the hypergraph
        void addVertex(int vertex)
        {
            vertextToHyperedges[vertex] = {};
        }

        // Add a hyperedge to the hypergraph
        void addHyperedge(int hyperedge, vector<int> vertices)
        {
            hyperedgeToVertices[hyperedge] = vertices;
            for (int vertex : vertices)
            {
                vertextToHyperedges[vertex].push_back(hyperedge);
            }
        }

        // Print the hypergraph
        void print()
        {
            cout << "Vertices:" << endl;
            for (auto& pair: vertextToHyperedges)
            {
                cout << " " << pair.first << ": ";
                for (int hyperedge : pair.second)
                {
                    cout << hyperedge << " ";
                }
                cout << endl;
            }
            cout << "Hyperedges:" << endl;
            for (auto& pair: hyperedgeToVertices)
            {
                cout << " " << pair.first << ": ";
                for (int vertex: pair.second)
                {
                    cout << vertex << " ";
                }
                cout << endl;
            }
        }

};

int main() {
    Hypergraph hypergraph;

    // Add vertices
    hypergraph.addVertex(1);
    hypergraph.addVertex(2);
    hypergraph.addVertex(3);
    hypergraph.addVertex(4);

    // Add hypergraph
    hypergraph.addHyperedge(1, {1,2});
    hypergraph.addHyperedge(2, {2,3});
    hypergraph.addHyperedge(3, {1, 3,4});
    hypergraph.addHyperedge(4, {2,4});

    // Print the hypergraph
    hypergraph.print();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
