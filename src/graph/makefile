srcFiles = Graph.cpp GraphAction.cpp GraphActionTargetable.cpp GraphEdge.cpp GraphNode.cpp\
./actions/TestAction.cpp\
./actionTargets/TestActionTarget.cpp\
./nodes/TestNode.cpp
hdrFiles = Graph.hpp GraphAction.hpp GraphActionTarget.hpp GraphActionTargetable.hpp graphActionFlagRegister.hpp GraphEdge.hpp \
GraphNode.hpp\
./actions/TestAction.hpp\
./actionTargets/TestActionTarget.hpp\
./nodes/TestNode.cpp

objFiles = $(srcFiles:.cpp=.o)

CXX = $(cname)
CXXFLAGS = $(cflags)

graph.a : $(objFiles)
	@ echo
	@ echo "*** Building Graph Module ***"
	@ echo
	ar rcs graph.a $(objFiles)

# During clean ignore make.dep being rebuilt during only to be removed again.
ifneq ($(MAKECMDGOALS),clean)
   include make.dep
endif

PHONY : dep
dep : make.dep

make.dep : $(srcFiles) $(hdrFiles)
	@ echo
	@ echo "*** Building Graph Dependencies ***"
	@ echo
	  $(cname) $(sdl_cflags) $(depflags) -MM $(srcFiles) > make.dep
	@ echo
	@ echo "*** Graph Dependencies Built Okay ***"
	@ echo

PHONY : clean
clean :
	@ echo
	@ echo "*** Cleaning Graph Module ***"
	@ echo
	-rm -f *.o make.dep graph.a
