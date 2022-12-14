#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

class GraphNode;

#include "GraphAction.hpp"
#include "../thread/thread.hpp"
#include "../util/RefCounted.hpp"

/**
 * Edge that describes directed link FROM one node TO another. ie It is directed.
 * An edge cannot exist without forming a link between two nodes. ie It _cannot_ dangle.
 * Edges should not be modified and are considered immutable.
 * When an edge detaches the final node to be detached is responsible for deleting it.
 */
class GraphEdge final : private RefCounted
{
	friend GraphNode;

    public:

	protected:

		// Must be virtual for reference counting auto-delete.
		virtual ~GraphEdge();

    private:

		/// Node this edge starts at.
        GraphNode* _fromNode;
		/// Node this edge ends at.
        GraphNode* _toNode;

		// Node supplied handles that are used to speed up the handling of edges by nodes.
		// The idea is to not have to search for pointers and that these handles are indexes into an array of edges contained
		// on the node. A value of -1 means this edge is not attached to the node.
		unsigned _fromNodeHandle;
		unsigned _toNodeHandle;

		/// Flags that allow edge traversal of an action.
		unsigned long _traversalFlags;

		// Generic lock.
        ThreadMutex _lock;

		/**
		 * Create directed link between two nodes.
		 * @note Because this is refcounted it will require the automatic initial refcount to be released before being deleted.
		 * @param fromNode Node link is from.
		 * @param toNode Node link is to.
		 * @param traversalFlags Flags that control what can traverse the edge.
		 */
		GraphEdge(GraphNode* fromNode, GraphNode* toNode, unsigned long traversalFlags);

		/**
		 * Detach this edge from the nodes it is associated with.
		 * Will block until full detached.
		 */
		void detach();

		/**
		 * Whether this edge is fully formed.
		 * @returns {bool} True if complete. False otherwise.
		 */
		bool isComplete();

		/**
		 * Determine if action can traverse edge.
		 * @param action Graph action to traverse the edge.
		 */
		bool canTraverse(GraphAction* action);
};

#endif
