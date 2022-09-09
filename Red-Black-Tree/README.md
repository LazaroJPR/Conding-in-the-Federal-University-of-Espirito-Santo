# Data Structures
Code produced in the Data Sctruture II class in the Federal University of Espírito Santo

A red-black tree is a kind of self-balancing binary search tree where each node has an extra bit, and that bit is often interpreted as the color (red or black). These colors are used to ensure that the tree remains balanced during insertions and deletions. Although the balance of the tree is not perfect, it is good enough to reduce the searching time and maintain it around O(log n) time, where n is the total number of elements in the tree. This tree was invented in 1972 by Rudolf Bayer. 

It must be noted that as each node requires only 1 bit of space to store the color information, these types of trees show identical memory footprints to the classic (uncolored) binary search tree. 

Rules That Every Red-Black Tree Follows: 

1- Every node has a color either red or black.
2- The root of the tree is always black.
3- There are no two adjacent red nodes (A red node cannot have a red parent or red child).
4- Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.
5 -All leaf nodes are black nodes.