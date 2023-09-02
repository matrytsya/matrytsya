#include "TestNode.hpp"

TestNode::~TestNode()
{
}

TestNode::TestNode(Graph* graph) : GraphNode(graph)
{
}

bool TestNode::ping()
{
	return true;
}

void TestNode::_detached()
{
}

bool TestNode::_canActionTarget(GraphAction* action)
{
	return GraphActionTargetable::_canActionTarget(action);
}