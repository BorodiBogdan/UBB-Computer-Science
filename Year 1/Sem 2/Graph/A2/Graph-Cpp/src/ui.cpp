#include "../includes/ui.h"
#include <iostream>

void Ui::readDirectedGraph(std::string input_file)
{
    this->service.destroyGraph();
    std::ifstream fin(input_file);

    int vertices, edges;

    fin >> vertices >> edges;

    int vertex1, vertex2, cost;

    for (int i = 0; i < vertices; ++i)
        service.addVertex(i);

    for (int i = 1; i <= edges; ++i)
    {
        fin >> vertex1 >> vertex2 >> cost;

        service.addEdge(vertex1, vertex2);
        service.modifyEdgeInformation(vertex1, vertex2, cost);
    }
}
void Ui::readUndirectedGraph(std::string input_file)
{
    this->service.destroyGraph();
    std::ifstream fin(input_file);

    int vertices, edges;

    fin >> vertices >> edges;

    int vertex1, vertex2;

    for (int i = 0; i < vertices; ++i)
        service.addVertex(i);

    for (int i = 1; i <= edges; ++i)
    {
        fin >> vertex1 >> vertex2;

        service.addEdge(vertex1, vertex2);
        service.addEdge(vertex2, vertex1);
    }
}
void Ui::DisplayGraph(std::string output_file)
{
    std::ofstream fout(output_file);

    fout << service.getNumberOfVertices() << " " << service.getNumberOfEdges() << "\n";

    fout << "The edges are:\n";
    Graph myGraph = service.getGraph();

    for (auto vertex_iterator = myGraph.getVerticeIterator(); vertex_iterator != myGraph.getEndOfIteration(); ++vertex_iterator)
    {
        auto currentVertex = vertex_iterator->first;

        for (auto edge_iterator = myGraph.getIteratorOutboundEdges(currentVertex); edge_iterator != myGraph.getEndOfIterationOutboundEdges(currentVertex); edge_iterator++)
        {
            fout << edge_iterator->first << " " << edge_iterator->second << " " << myGraph.retrieveEdgeInformation(edge_iterator->first, edge_iterator->second) << "\n";
        }
    }
}
void Ui::menuForA1()
{
    this->readDirectedGraph("../in.txt");
    std::string menu_message = "1. Get  the number of vertices\n";
    menu_message += "2. Parse the set of vertices\n";
    menu_message += "3. Given two vertices, find out whether there is an edge from the first one to the second one\n";
    menu_message += "4. Get in and out degree of an vertex\n";
    menu_message += "5. Parse (iterate) the set of outbound edges of a specified vertex\n";
    menu_message += "6. parse (iterate) the set of inbound edges of a specified vertex\n";
    menu_message += "7. Modify the information (the integer) attached to a specified edge\n";
    menu_message += "8. Add vertex\n";
    menu_message += "9. Remove vertex\n";
    menu_message += "10. Add edge\n";
    menu_message += "11. Remove edge\n";
    menu_message += "12. Get the cost of an edge\n";
    menu_message += "0. exit\n";

    std::cout << menu_message;
    bool ok = true;

    while (ok == true)
    {
        Graph myGraph = this->service.getGraph();
        std::cout << "Enter option: ";
        int option;
        std::cin >> option;

        switch (option)
        {
        case 1:
            std::cout << "There are: " << service.getNumberOfVertices() << " vertices\n";
            break;
        case 2:
            for (auto it = myGraph.getVerticeIterator(); it != myGraph.getEndOfIteration(); ++it)
                std::cout << it->first << "\n";
            break;
        case 3:
            int vertex1, vertex2;
            std::cout << "first vertex: ";
            std::cin >> vertex1;
            std::cout << "second vertex: ";
            std::cin >> vertex2;

            if (service.isEdge(vertex1, vertex2))
                std::cout << "The edge exists!\n";
            else
                std::cout << "Edge not found!!\n";
            break;
        case 4:
            int vertex;
            std::cout << "enter the vertex: ";
            std::cin >> vertex;

            std::cout << "The in degree is: " << service.getInDegree(vertex) << "\n";
            std::cout << "The out degree is: " << service.getOutDegree(vertex) << "\n";
            break;

        case 5:
            std::cout << "Enter vertex: ";
            std::cin >> vertex;
            std::cout << "OutBound edge iteration:\n";
            {
                edgeIterator it = myGraph.getIteratorOutboundEdges(vertex);

                if (it != myGraph.getEndOfIterationOutboundEdges(vertex))
                    std::cout << vertex << "\n";

                for (; it != myGraph.getEndOfIterationOutboundEdges(vertex); ++it)
                    std::cout << it->first << " " << it->second << " " << myGraph.retrieveEdgeInformation(it->first, it->second) << "\n";
                break;
            }
        case 6:
            std::cout << "Enter vertex: ";
            std::cin >> vertex;
            std::cout << "InBound edge iteration:\n";
            {
                auto it = myGraph.getIteratorInboundEdges(vertex);

                if (it != myGraph.getEndOfIterationInboundEdges(vertex))
                    std::cout << vertex << "\n";

                for (; it != myGraph.getEndOfIterationInboundEdges(vertex); ++it)
                    std::cout << it->first << " " << it->second << " " << myGraph.retrieveEdgeInformation(it->first, it->second) << "\n";
            }
            break;
        case 7:
            int new_cost;

            std::cout << "first vertex: ";
            std::cin >> vertex1;
            std::cout << "second vertex: ";
            std::cin >> vertex2;
            std::cout << "Enter the new cost:";
            std::cin >> new_cost;

            service.modifyEdgeInformation(vertex1, vertex2, new_cost);
            std::cout << "Cost succesfully updated!\n";
            break;
        case 8:
            std::cout << "Enter the vertex: ";
            std::cin >> vertex;
            service.addVertex(vertex);
            std::cout << "Vertex succesfully added!\n";
            break;
        case 9:
            std::cout << "Enter the vertex: ";
            std::cin >> vertex;
            service.removeVertex(vertex);
            std::cout << "Vertex succesfully removed!\n";
            break;
        case 10:
            std::cout << "Enter the first vertex: ";
            std::cin >> vertex1;
            std::cout << "Enter the second vertex: ";
            std::cin >> vertex2;
            service.addEdge(vertex1, vertex2);
            std::cout << "Edge succesfully added!\n";
            break;
        case 11:
            std::cout << "Enter the first vertex: ";
            std::cin >> vertex1;
            std::cout << "Enter the second vertex: ";
            std::cin >> vertex2;
            service.removeEdge(vertex1, vertex2);
            std::cout << "Edge succesfully removed!\n";
            break;
        case 12:
            std::cout << "first vertex: ";
            std::cin >> vertex1;
            std::cout << "second vertex: ";
            std::cin >> vertex2;

            std::cout << "The cost is: " << service.retrieveEdgeInformation(vertex1, vertex2) << "\n";
            break;
        case 0:
            ok = false;
            break;
        default:
            std::cout << "Invalid Option";
        }
    }
}
void printComponents(std::vector<std::vector<int>> componentList)
{
    std::cout << "\nThe components are\n";

    for (unsigned int i = 0; i < componentList.size(); ++i)
    {
        std::cout << "Component nr. " << i + 1 << ": \n";

        std::cout << "The nodes from the component are: ";
        for (auto vertex : componentList[i])
        {
            std::cout << vertex << " ";
        }
        std::cout << "\n___________________________________________________\n";
    }
}
void Ui::menuForA2()
{
    std::cout << "1. Find connected components of a graph using DFS\n";
    std::cout << "2. Find strongly connected components of an undirected graph\n";
    std::cout << "3. Solve wolf, goat, cabbage problem\n";
    std::cout << "4. Find biconnected components of a graph\n";
    std::cout << "5. Solve the 15 puzzle problem\n";
    std::cout << "0. Exit\n";

    while (true)
    {
        int option;
        std::cout << "Choose option: ";
        std::cin >> option;

        if (option == 1)
        {
            this->readUndirectedGraph("../conexComponents.txt");
            std::vector<std::vector<int>> connectedComponentList = this->service.connectedComponents();
            printComponents(connectedComponentList);
        }
        else if (option == 2)
        {
            this->readDirectedGraph("../stronglyConnectedComponents.txt");
            std::vector<std::vector<int>> stronglyConnectedComponents = this->service.getStronglyConnectedComponents();

            printComponents(stronglyConnectedComponents);
        }
        else if (option == 3)
        {
            std::vector<std::pair<std::string, std::string>> ans = this->service.solveGoatWolfCabbage();
            std::cout << "One path is:\n";

            for (auto state : ans)
                std::cout << state.first << " - " << state.second << "\n";
        }
        else if (option == 4)
        {
            // this->readUndirectedGraph("../biconnectedConnectedComponents.txt");

            // std::vector<std::vector<int>> ans = this->service.biconexComponents(0, -1);

            // std::cout << "There are " << ans.size() << " biconex components\n";

            // printComponents(ans);
        }
        else if (option == 0)
        {
            break;
        }
    }
}
void Ui::startUi()
{
    while (true)
    {
        std::cout << "Choose assignment\n";
        std::cout << "1. A1\n";
        std::cout << "2. A2\n";

        int option;

        std::cout << "Choose option: ";
        std::cin >> option;

        if (option == 1)
            this->menuForA1();
        else if (option == 2)
            this->menuForA2();
        else if (option == 0)
            exit(0);
    }
}