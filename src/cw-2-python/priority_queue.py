class BinomialTree:
    # Узел биномиального дерева
    def __init__(self, key):
        self.key = key
        self.degree = 0
        self.parent = None
        self.child = None
        self.sibling = None


class BinomialHeap:
    # Биномиальная куча
    def __init__(self):
        self.head = None
    
    def is_empty(self):
        return self.head is None
    
    def insert(self, key):
        # Вставка элемента
        new_heap = BinomialHeap()
        new_tree = BinomialTree(key)
        new_heap.head = new_tree
        
        self.merge(new_heap)
    
    def merge(self, other_heap):
        # Слияние двух куч
        if not other_heap or other_heap.is_empty():
            return
        
        self.head = self.merge_root_lists(self.head, other_heap.head)
        
        if self.head is None:
            return
        
        prev = None
        x = self.head
        next_node = x.sibling
        
        while next_node is not None:
            if (x.degree != next_node.degree or 
                (next_node.sibling is not None and next_node.sibling.degree == x.degree)):
                prev = x
                x = next_node
            elif x.key <= next_node.key:
                x.sibling = next_node.sibling
                self.link_trees(next_node, x)
            else:
                if prev is None:
                    self.head = next_node
                else:
                    prev.sibling = next_node
                self.link_trees(x, next_node)
                x = next_node
            
            next_node = x.sibling
    
    def extract_min(self):
        # Извлечение минимального элемента"""
        if self.is_empty():
            raise ValueError("Heap is empty")
        
        # Находим минимальный корень
        min_node_prev = None
        min_node = self.head
        current = self.head
        prev = None
        
        while current is not None:
            if current.key < min_node.key:
                min_node = current
                min_node_prev = prev
            prev = current
            current = current.sibling
        
        # Удаляем минимальный корень
        if min_node_prev is None:
            self.head = min_node.sibling
        else:
            min_node_prev.sibling = min_node.sibling
        
        reversed_children = self.reverse_children(min_node.child)
        child_heap = BinomialHeap()
        child_heap.head = reversed_children
        
        self.merge(child_heap)
        
        return min_node.key
    
    def merge_root_lists(self, head1, head2):
        #Слияние двух отсортированных списков корней
        if head1 is None:
            return head2
        if head2 is None:
            return head1
        
        result = None
        
        if head1.degree <= head2.degree:
            result = head1
            head1 = head1.sibling
        else:
            result = head2
            head2 = head2.sibling
        
        current = result
        
        while head1 is not None and head2 is not None:
            if head1.degree <= head2.degree:
                current.sibling = head1
                head1 = head1.sibling
            else:
                current.sibling = head2
                head2 = head2.sibling
            current = current.sibling
        
        if head1 is not None:
            current.sibling = head1
        else:
            current.sibling = head2
        
        return result
    
    def link_trees(self, child, parent):
        # Связывание двух биномиальных деревьев одинаковой степени
        child.parent = parent
        child.sibling = parent.child
        parent.child = child
        parent.degree += 1
    
    def reverse_children(self, child):
        # Переворот списка детей для создания корректного списка корней
        prev = None
        current = child
        
        while current is not None:
            current.parent = None
            next_node = current.sibling
            current.sibling = prev
            prev = current
            current = next_node
        
        return prev
