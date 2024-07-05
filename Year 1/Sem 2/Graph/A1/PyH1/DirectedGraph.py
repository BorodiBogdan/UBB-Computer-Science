from copy import deepcopy


class DirectedGraph:
    def __init__(self):
        self.vertices = set()

        self.adjacency_list = {}
        self.edge_costs = {}

    def add_vertex(self, vertex):
        if vertex not in self.vertices:
            self.vertices.add(vertex)
            self.adjacency_list[vertex] = set()

    def remove_vertex(self, vertex):
        if vertex in self.vertices:
            self.vertices.remove(vertex)
            del self.adjacency_list[vertex]
            for v in self.adjacency_list:
                self.adjacency_list[v].discard(vertex)
            self.remove_edge_with_vertex(vertex)

    def add_edge(self, source, target, cost):
        self.add_vertex(source)
        self.add_vertex(target)
        self.adjacency_list[source].add(target)

        self.edge_costs[(source, target)] = cost

    def remove_edge(self, source, target):
        if (source, target) in self.edge_costs:
            self.adjacency_list[source].discard(target)
            del self.edge_costs[(source, target)]

    def remove_edge_with_vertex(self, vertex):
        edges_to_remove = [(source, target) for (source, target) in self.edge_costs.keys()
                           if source == vertex or target == vertex]
        for edge in edges_to_remove:
            del self.edge_costs[edge]

    def get_number_of_vertices(self):
        return len(self.vertices)


    def parse_vertices(self):
        return iter(self.vertices)

    def get_in_degree(self, vertex):
        return sum(1 for v in self.adjacency_list if vertex in self.adjacency_list[v])

    def get_out_degree(self, vertex):
        return len(self.adjacency_list.get(vertex, []))

    def parse_out_edges(self, vertex):
        return iter((vertex, target) for target in self.adjacency_list.get(vertex, []))

    def parse_in_edges(self, vertex):
        return iter((source, vertex) for source in self.adjacency_list if vertex in self.adjacency_list[source])

    def get_edge_endpoints(self, edge_id):
        if edge_id in self.edge_costs:
            return edge_id
        return None

    def get_edge_cost(self, source, target):
        return self.edge_costs.get((source, target), None)

    def has_edge(self, source, target):
        return target in self.adjacency_list.get(source, [])

    def set_edge_cost(self, source, target, cost):
        if (source, target) in self.edge_costs:
            self.edge_costs[(source, target)] = cost

    def copy(self):
        new_graph = DirectedGraph()
        for vertex in self.vertices:
            new_graph.add_vertex(vertex)
        for edge, cost in self.edge_costs.items():
            new_graph.add_edge(edge[0], edge[1], cost)
        return new_graph

    def copy_with_deepcopy(self):
        return deepcopy(self)

