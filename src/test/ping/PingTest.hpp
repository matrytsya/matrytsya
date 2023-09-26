#include "../../graph/Graph.hpp"
#include "../../graph/GraphNodeHandle.hpp"
#include "../../graph/nodes/TestNode.hpp"
#include "../../thread/ThreadPool.hpp"
#include "../UnitTest.hpp"

class PingTest : public UnitTest
{
	public:

		PingTest() : UnitTest("PingTest"){}

	protected:

		virtual void runTests()
		{
			startThreadPool(2);

			Graph* graph = new Graph();

			// Build a network of nodes and apply ping test action.
			// The nodes must _not_ be allocated on the stack because of auto-delete once de-reffed.

			TestNode* testNode1 = new TestNode(graph);
			TestNode* testNode2 = new TestNode(graph);
			TestNode* testNode3 = new TestNode(graph);

			GraphNodeHandle nodeHandle1(testNode1);
			GraphNodeHandle nodeHandle2(testNode2);
			GraphNodeHandle nodeHandle3(testNode3);

			testNode1 -> formEdgeTo(nodeHandle2, );

			delete graph;

			stopThreadPool();
		}
};