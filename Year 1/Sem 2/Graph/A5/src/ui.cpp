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
    this->readDirectedGraph("../testFiles/in.txt");
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
            this->readUndirectedGraph("../testFiles/conexComponents.txt");
            std::vector<std::vector<int>> connectedComponentList = this->service.connectedComponents();
            printComponents(connectedComponentList);
        }
        else if (option == 2)
        {
            this->readDirectedGraph("../testFiles/stronglyConnectedComponents.txt");
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
            // this->readUndirectedGraph("../testFiles/biconnectedConnectedComponents.txt");

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
void Ui::menuForA3()
{
    std::cout << "1. Find a lowest cost path using 'backwards' Dijkstra algorithm\n";
    std::cout << "2. Solve 20 torch problem\n";
    std::cout << "3. Find how many roads are between node x and node y\n";
    std::cout << "4. Find how many minimum cost roads are between node x and node y \n";
    std::cout << "0. Exit\n";

    while (true)
    {
        int option;
        std::cout << "Choose option: ";
        std::cin >> option;

        if (option == 1)
        {
            this->readDirectedGraph("../testFiles/dijkstra.txt");
            int sourceVertex, targetVertex;

            std::cout << "Source: ";
            std::cin >> sourceVertex;
            std::cout << "Destination: ";
            std::cin >> targetVertex;

            std::cout << "The minimum cost of the walk is: " << this->service.reverseDijkstra(sourceVertex, targetVertex) << "\n";
        }
        else if (option == 2)
        {
            std::ifstream fin("../testFiles/torch.in");
            // input number of people
            // a cost array(each element is the time it take's for the i'th person to pass the bridge)

            int nrOfPeople;

            fin >> nrOfPeople;

            std::vector<int> cost;
            int x;

            for (int i = 1; i <= nrOfPeople; ++i)
            {
                fin >> x;
                cost.push_back(x);
            }

            int ans = this->service.solveTorchProblem(nrOfPeople, cost);

            std::cout << "It takes: " << ans << " minutes to cross the bridge\n";

            fin.close();
        }
        else if (option == 3)
        {
            this->readDirectedGraph("../testFiles/numberOfRoads.txt");
            int sourceVertex, targetVertex;

            std::cout << "Source: ";
            std::cin >> sourceVertex;
            std::cout << "Destination: ";
            std::cin >> targetVertex;

            std::cout << "There are " << this->service.getNumberOfRoads(sourceVertex, targetVertex) << " walks between node x and node y\n";
        }
        else if (option == 4)
        {
            this->readDirectedGraph("../testFiles/numberOfRoads.txt");
            int sourceVertex, targetVertex;

            std::cout << "Source: ";
            std::cin >> sourceVertex;
            std::cout << "Destination: ";
            std::cin >> targetVertex;

            std::cout << "There are " << this->service.getNumberOfMinimumCostRoads(sourceVertex, targetVertex) << " minimum cost walks between node x and node y\n";
        }
        else if (option == 0)
            return;
    }
}
void Ui::menuForA4()
{
    /*
    3. Write a program that, given a graph with costs, does the following:

    verify if the corresponding graph is a DAG and performs a topological sorting of the activities using the
    algorithm based on depth-first traversal (Tarjan's algorithm);if it is a DAG, finds a highest cost path between
    two given vertices, in O(m+n).
    */
    std::cout << "0. Exit\n";
    std::cout << "1. Verify if the graph is a DAG and find the highest cost pasth\n";
    std::cout << "2. Find how many roads are between node x and node y\n";
    std::cout << "3. Find how many minimum cost roads are between node x and node y \n";
    std::cout << "4. Given a pre-order traversal of a binary search tree, reconstruct the tree\n";

    while (true)
    {
        int option;
        std::cout << "Choose option: ";
        std::cin >> option;

        if (option == 1)
        {
            this->readDirectedGraph("../testFiles/maximumCostRoad.txt");
            int sourceVertex, targetVertex;

            std::cout << "Source: ";
            std::cin >> sourceVertex;
            std::cout << "Destination: ";
            std::cin >> targetVertex;

            if (this->service.getMaximumCostPath(sourceVertex, targetVertex) == -1)
                std::cout << "The graph is not a DAG!!!\n";
            else
                std::cout << "The maximum cost is: " << this->service.getMaximumCostPath(sourceVertex, targetVertex) << "\n";
        }
        else if (option == 2)
        {
            this->readDirectedGraph("../testFiles/numberOfRoads.txt");
            int sourceVertex, targetVertex;

            std::cout << "Source: ";
            std::cin >> sourceVertex;
            std::cout << "Destination: ";
            std::cin >> targetVertex;

            if (this->service.getNumberOfRoads(sourceVertex, targetVertex) == -1)
                std::cout << "The graph is not a DAG!!!\n";
            else
                std::cout << "There are " << this->service.getNumberOfRoads(sourceVertex, targetVertex) << " walks between node x and node y\n";
        }
        else if (option == 3)
        {
            this->readDirectedGraph("../testFiles/numberOfRoads.txt");
            int sourceVertex, targetVertex;

            std::cout << "Source: ";
            std::cin >> sourceVertex;
            std::cout << "Destination: ";
            std::cin >> targetVertex;

            if (this->service.getNumberOfMinimumCostRoads(sourceVertex, targetVertex) == -1)
                std::cout << "The graph is not a DAG!!!\n";
            else
                std::cout << "There are " << this->service.getNumberOfMinimumCostRoads(sourceVertex, targetVertex) << " minimum cost walks between node x and node y\n";
        }
        else if (option == 4)
        {
            std::vector<int> preOrder = {1, 2, 4, 5, 3, 6, 7};
            std::vector<int> inOrder = {4, 2, 5, 1, 6, 3, 7};

            std::vector<vector<int>> reconstructedTree = this->service.reconstructTree(preOrder, inOrder);

            std::cout << "The tree is:\n";

            int levelNumber = 0;
            for (auto level : reconstructedTree)
            {
                if (levelNumber >= 1)
                {
                    std::cout << "Node " << levelNumber << ": ";
                    for (auto node : level)
                        std::cout << node << " ";

                    if (level.size() == 0)
                        std::cout << "It is a leaf node";

                    std::cout << "\n";
                }
                levelNumber++;
            }
        }
        else if (option == 0)
            break;
    }
}
void Ui::menuForA5()
{
    std::cout << "1. Find the minimum coloring of a graph using backtracking\n";
    std::cout << "2. Find the minimum coloring of a graph using greedy\n";
    std::cout << "3. Find the minimum coloring of a graph using backtracking and greedy\n";
    std::cout << "0. Exit\n";

    while (true)
    {
        int option;
        std::cout << "Choose option: ";
        std::cin >> option;

        if (option == 1)
        {
            this->readUndirectedGraph("../testFiles/minimumColouring.txt");

            std::vector<int> ans = this->service.getMinimumColoringGraph();

            std::cout << "The minimum coloring is: " << ans.size() << "\n";
            std::cout << "The colors are: ";
            for (auto color : ans)
                std::cout << color << " ";
            std::cout << "\n";
        }
        else if (option == 2)
        {
            this->readUndirectedGraph("../testFiles/minimumColouring.txt");

            std::vector<int> ans = this->service.getMinimumColouringGraphGreedy();

            std::cout << "The minimum coloring is: " << ans.size() << "\n";
            std::cout << "The colors are: ";
            for (auto color : ans)
                std::cout << color << " ";
            std::cout << "\n";
        }
        else if (option == 3)
        {
            this->readDirectedGraph("../testFiles/coloring.txt");
            std::vector<int> ans = this->service.getMinimumColoringGraph();

            std::cout << "The minimum coloring is: " << ans.size() << "\n";
            std::cout << "The colors are: ";
            for (auto color : ans)
                std::cout << color << " ";
            std::cout << "\n";
        }
        else if (option == 0)
            break;
    }
}

void Ui::startUi()
{
    while (true)
    {
        std::cout << "Choose assignment\n";
        std::cout << "1. A1\n";
        std::cout << "2. A2\n";
        std::cout << "3. A3\n";
        std::cout << "4. A4\n";
        std::cout << "5. A5\n";

        int option;

        std::cout << "Choose option: ";
        std::cin >> option;

        if (option == 1)
            this->menuForA1();
        else if (option == 2)
            this->menuForA2();
        else if (option == 3)
            this->menuForA3();
        else if (option == 4)
            this->menuForA4();
        else if (option == 5)
            this->menuForA5();
        else if (option == 0)
            exit(0);
    }
}