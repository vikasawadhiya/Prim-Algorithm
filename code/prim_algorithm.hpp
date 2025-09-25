/*********************************************************************************
** MIT License
**
** Copyright (c) 2025 Vikas Awadhiya
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:

** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.

** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
*********************************************************************************/

#ifndef PRIM_ALGORITHM
#define PRIM_ALGORITHM

#include <vector>

namespace graphLibrary {

	/// @brief Implements Prim's algorithms.
	/// 
	/// @param graph It represents a undirected simple graph in adjacency list format.
	/// 
	/// In two-dimension std::vector, the first dimension std::vector represent the vertices and it has one entry for 
	/// each vertex of a graph. Vertices are labeled from zero up-to one less than number of vertices in a graph.
	/// 
	/// The second dimension of std::vector is std::vector< std::pair< std::size_t, ptrdiff_t > > and represents edges
	/// incident to a vertex in a undirected graph. First element of the std::pair<std::size_t, ptrdiff_t> represent a 
	/// vertex and the second element represent weight of an edge which can be negative as well.
	///
	/// @return It returns std::vector< std::vector< std::pair<std::size_t, std::ptrdiff_t> > > represents minimum
	/// spanning tree of the graph passed to the function.
	/// 
	std::vector< std::vector< std::pair<std::size_t, std::ptrdiff_t> > >
	primAlgorithm(const std::vector< std::vector< std::pair<std::size_t, std::ptrdiff_t> > >& graph);
}


#endif // !PRIM_ALGORITHM

