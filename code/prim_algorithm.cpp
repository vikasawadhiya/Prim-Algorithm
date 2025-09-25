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

#include "prim_algorithm.hpp"

#include <queue>
#include <tuple>

using namespace std;

namespace graphLibrary {

	namespace {

		using WeightedEdge = pair<size_t, ptrdiff_t>;
		using EdgeQueueElement = tuple<size_t, size_t, ptrdiff_t>;

		/// @brief  It is used as function object to compare edges.
		/// It is used as greater-than comparator to turn std::priority_queue to min-heap.
		/// 
		class edgeEntryGreaterThanComparator {

		public:
			bool operator() (const EdgeQueueElement& edge1, const EdgeQueueElement& edge2) const {

				return get<2>(edge2) < get<2>(edge1);
			}
		};

		using EdgeQueue = priority_queue< EdgeQueueElement, vector<EdgeQueueElement>, edgeEntryGreaterThanComparator >;
	}

	/// @brief If a graph is a disconnect graph it requires multiple runs of Prim's algorithm.
	/// In each run, Prim's algorithm is applied on a component to find the minimum spanning tree.
	/// In connected graph it runs only one time but in disconnected graph it runs once for each component.
	/// 
	/// @param edgeQueue It represents std::priority_queue or min-heap
	/// 
	/// @param selectedVertexCount It represents selected status of vertices.
	/// 
	/// @param vertexSelectStatus It represents selected number of vertices.
	/// 
	/// @param tree It represents minimum spanning tree.
	/// 
	/// @param graph It represents graph passed as parameter to Prim's algorithm.
	/// 
	void primAlgorithmOnAComponet(EdgeQueue& edgeQueue,
								  size_t& selectedVertexCount,
								  vector<bool>& vertexSelectStatus,
								  vector< vector<WeightedEdge> >& tree,
								  const vector< vector<WeightedEdge> >& graph) {


		size_t u;
		size_t v;
		ptrdiff_t w;

		while ( !edgeQueue.empty() ) {

			std::tie(u, v, w) = edgeQueue.top();
			edgeQueue.pop();

			if (!vertexSelectStatus[v]) {

				vertexSelectStatus[v] = true;
				++selectedVertexCount;

				tree[u].emplace_back(v, w);

				if ( !( selectedVertexCount < graph.size() ) ) {

					return;
				}

				for (const WeightedEdge& edge : graph[v]) {

					if ( !vertexSelectStatus.at( edge.first ) ) {

						edgeQueue.emplace(v, edge.first, edge.second);
					}
				}
			}
		}
	}

	vector< vector< WeightedEdge > > primAlgorithm(const vector< vector<WeightedEdge> >& graph) {

		size_t selectedVertexCount = 0;
		vector<bool> vertexSelectStatus( graph.size() );

		vector< vector< WeightedEdge > > minimumSpanningTree( graph.size() );

		for (size_t i = 0; i < graph.size(); ++i) {

			if ( !vertexSelectStatus[i] ) {

				vertexSelectStatus[i] = true;
				++selectedVertexCount;

				EdgeQueue edgeQueue;

				for (const WeightedEdge& edge : graph[i]) {

					if ( !vertexSelectStatus.at(edge.first) ) {

						edgeQueue.emplace(i, edge.first, edge.second);
					}
				}

				if ( !edgeQueue.empty() ) {

					primAlgorithmOnAComponet(edgeQueue, selectedVertexCount, vertexSelectStatus, minimumSpanningTree, 
											graph);
				}

				if ( !( selectedVertexCount < graph.size() ) ) {

					break;
				}
			}
		}

		return minimumSpanningTree;
	}
}
