# Data Structures
Code produced in the Traphs Theory class in the Federal University of Espírito Santo

What is a Spanning Tree?

A Spanning tree is a subset to a connected graph G, where all the edges are connected, i.e, one can traverse to any edge from a particular edge with or without intermediates. Also, a spanning tree must not have any cycle in it. Thus we can say that if there are N vertices in a connected graph then the no. of edges that a spanning tree may have is N-1.

What is a Minimum Spanning Tree? 

Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. A single graph can have many different spanning trees. A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected, undirected graph is a spanning tree with a weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.

How many edges does a minimum spanning tree has? 

A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph. 

How to find MST using Kruskal’s algorithm?
Below are the steps for finding MST using Kruskal’s algorithm:

1- Sort all the edges in non-decreasing order of their weight.
2- Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.
3- Repeat step#2 until there are (V-1) edges in the spanning tree.

Kruskal’s algorithm to find the minimum cost spanning tree uses the greedy approach. The Greedy Choice is to pick the smallest weight edge that does not cause a cycle in the MST constructed so far. 