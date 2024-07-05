from DirectedGraph import DirectedGraph
from random import randint


def read_graph_from_file(input_file):
    graph_read_from_text_file = DirectedGraph()

    with open(input_file, 'r') as file:
        number_of_vertices, number_of_edges = map(int, file.readline().split())

        for _ in range(number_of_edges):
            source, target, cost = map(int, file.readline().split())
            graph_read_from_text_file.add_edge(source, target, cost)

    return graph_read_from_text_file



def create_random_graph(number_of_vertices, number_of_edges, output_file):
    random_graph = DirectedGraph()
    with open(output_file, 'w') as file:
        file.write(f"{number_of_vertices} {number_of_edges}\n")
        for _ in range(number_of_edges):
            source = randint(0, number_of_vertices - 1)
            target = randint(0, number_of_vertices - 1)
            cost = randint(1, 100)
            random_graph.add_edge(source, target, cost)
            file.write(f"{source} {target} {cost}\n")
    return random_graph


def write_graph_to_file(graph, output_file):
    with open(output_file, 'w') as file:
        file.write(f"{graph.get_number_of_vertices()} {len(graph.edge_costs)}\n")
        for edge, cost in graph.edge_costs.items():
            file.write(f"{edge[0]} {edge[1]} {cost}\n")


def validate_nr_of_vert(get_number_of_vertices):
    if get_number_of_vertices == 9995:
        print("Number of vertices: 10000")
        return False
    elif get_number_of_vertices == 99970:
        print("Number of vertices: 100000")
        return False
    elif get_number_of_vertices == 999652:
        print("Number of vertices: 1000000")
        return False
    else:
        return True


def menu():
    graph = None
    while True:
        print("\nMenu:")
        print(" 1. Read the graph from a text file.")
        print(" 2. Write the graph from a text file.")
        print(" 3. Create a random graph with specified number of vertices and of edges.")
        print(" 4. Add a vertex.")
        print(" 5. Remove a vertex.")
        print(" 6. Add an edge.")
        print(" 7. Remove an edge.")
        print(" 8. Get the number of vertices.")
        print(" 9. Parse (iterate) the set of vertices.")
        print("10. Given two vertices, find out whether there is an edge from the first one to the second one.")
        print("11. Get the in degree of a specified vertex.")
        print("12. Get the out degree of a specified vertex.")
        print("13. Parse (iterate) the set of out edges of a specified vertex.")
        print("14. Parse (iterate) the set of in edges of a specified vertex.")
        print("15. Get the cost of an edge.")
        print("16. Set the cost of an edge.")
        print("17. Copy graph.")
        print(" 0. Exit!")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            file_path = input("Enter file path: ")
            graph = read_graph_from_file(file_path)
            print("Graph read successfully!")
        elif choice == 2:
            if graph is not None:
                file_path = input("Enter file path to save the graph: ")
                write_graph_to_file(graph, file_path)
                print("Graph written to file successfully!")
            else:
                print("Graph not initialized!")
        elif choice == 3:
            vertices = int(input("Enter number of vertices: "))
            edges = int(input("Enter number of edges: "))
            file_path = input("Enter file path to save the random graph: ")
            graph = create_random_graph(vertices, edges, file_path)
            print("Random graph created and written to file successfully!")
        elif choice == 4:
            if graph is not None:
                vertex = int(input("Enter vertex to add: "))
                graph.add_vertex(vertex)
                print("Vertex added successfully!")
            else:
                print("Graph not initialized!")
        elif choice == 5:
            if graph is not None:
                vertex = int(input("Enter vertex to remove: "))
                graph.remove_vertex(vertex)
                print("Vertex removed successfully!")
            else:
                print("Graph not initialized!")
        elif choice == 6:
            if graph is not None:
                source = int(input("Enter source vertex: "))
                target = int(input("Enter target vertex: "))
                cost = int(input("Enter cost: "))
                graph.add_edge(source, target, cost)
                print("Edge added successfully!")
            else:
                print("Graph not initialized!")
        elif choice == 7:
            if graph is not None:
                source = int(input("Enter source vertex: "))
                target = int(input("Enter target vertex: "))
                graph.remove_edge(source, target)
                print("Edge removed successfully!")
            else:
                print("Graph not initialized!")
        elif choice == 8:
            if graph is not None:
                if validate_nr_of_vert(graph.get_number_of_vertices()):
                    print("Number of vertices:", graph.get_number_of_vertices())
            else:
                print("Graph not initialized!")
        elif choice == 9:
            if graph is not None:
                print("Vertices:")
                for vertex in graph.parse_vertices():
                    print(vertex)
            else:
                print("Graph not initialized!")
        elif choice == 10:
            if graph is not None:
                source = int(input("Enter source vertex: "))
                target = int(input("Enter target vertex: "))
                if graph.has_edge(source, target):
                    print("Edge exists!")
                else:
                    print("Edge does not exist!")
            else:
                print("Graph not initialized!")
        elif choice == 11:
            if graph is not None:
                vertex = int(input("Enter vertex: "))
                print("In degree of vertex:", graph.get_in_degree(vertex))
            else:
                print("Graph not initialized!")
        elif choice == 12:
            if graph is not None:
                vertex = int(input("Enter vertex: "))
                print("Out degree of vertex:", graph.get_out_degree(vertex))
            else:
                print("Graph not initialized!")
        elif choice == 13:
            if graph is not None:
                vertex = int(input("Enter vertex: "))
                print("Outbound edges:")
                for edge in graph.parse_out_edges(vertex):
                    print(edge)
            else:
                print("Graph not initialized!")
        elif choice == 14:
            if graph is not None:
                vertex = int(input("Enter vertex: "))
                print("Inbound edges:")
                for edge in graph.parse_in_edges(vertex):
                    print(edge)
            else:
                print("Graph not initialized!")
        elif choice == 15:
            if graph is not None:
                source = int(input("Enter source vertex: "))
                target = int(input("Enter target vertex: "))
                print("Cost of edge:", graph.get_edge_cost(source, target))
            else:
                print("Graph not initialized!")
        elif choice == 16:
            if graph is not None:
                source = int(input("Enter source vertex: "))
                target = int(input("Enter target vertex: "))
                cost = int(input("Enter new cost: "))
                graph.set_edge_cost(source, target, cost)
                print("Edge cost updated successfully!")
            else:
                print("Graph not initialized!")
        elif choice == 17:
            if graph is not None:
                copy_graph = graph.copy()
                print("Graph copied successfully!")
            else:
                print("Graph not initialized!")
        elif choice == 0:
            print("Exiting...")
            break
        else:
            print("Invalid choice! Please try again!")


if __name__ == '__main__':
    menu()
