class Graph:
    def __init__(self, nodes: list[int], connections: list[tuple[int, int]]) -> None:
        self.nodes = nodes
        self.connections = connections
        self.traversal_path = []   # Пути обхода вершин

    def __iter__(self):
        # Позволяет использовать граф в циклах for
        if not self.traversal_path:
            self.depth_first_search()
        return iter(self.traversal_path)

    def depth_first_search(self) -> list[int]:
        visited = set()   # Посещённые вершины
        self.traversal_path = []

        def explore_node(node):
            if node not in visited:
                visited.add(node)   # Помечаем узел как посещенный
                self.traversal_path.append(node)

                # Находим все связанные узлы
                adjacent_nodes = []
                for conn in self.connections:
                    if conn[0] == node:
                        adjacent_nodes.append(conn[1])
                    elif conn[1] == node:
                        adjacent_nodes.append(conn[0])

                # Обходим соседей
                for neighbor in adjacent_nodes:
                    explore_node(neighbor)

        # Обеспечиваем обход всех компонентов графа
        for node in self.nodes:
            if node not in visited:
                explore_node(node)

        return self.traversal_path
