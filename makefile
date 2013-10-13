GOAL_NAME = Code
GOAL = $(GOAL_NAME).pdf
PARTS = \
	DisjointSet/DisjointSet.tex \
	Heap/Heap.tex \
	SSSP/SSSP.tex \
	APSP/APSP.tex \
	MST/MST.tex \
	KMP/KMP.tex \
	BM/BM.tex \
	ACauto/ACauto.tex \
	BiGraph/BiGraph \
	NetworkFlow/NetworkFlow

all: build

build: cleanbuild $(GOAL)

$(GOAL): $(GOAL_NAME).tex
	texify.exe --pdf --tex-option=-synctex=1 $^
	
$(GOAL_NAME).tex: $(PARTS)

DisjointSet/DisjointSet.tex: DisjointSet/DisjointSet.cpp

Heap/Heap.tex: Heap/MinHeap.cpp

SSSP/SSSP.tex: SSSP/relax.cpp SSSP/SPFA.cpp SSSP/Dijkstra.cpp

APSP/APSP.tex: APSP/Floyd.cpp

MST/MST.tex: MST/Kruskal.cpp MST/Prim.cpp

KMP/KMP.tex: KMP/KMP.cpp

BM/BM.tex: BM/BM.cpp

ACauto/ACauto.tex: ACauto/ACauto.cpp

BiGraph/BiGraph.tex: BiGraph/BiGraph.cpp

NetworkFlow/NetworkFlow.tex: NetworkFlow/NetworkFlow.cpp

clean:
	find . -name '*.aux' -type f -print -exec rm -rf {} \;
	find . -name '*.log' -type f -print -exec rm -rf {} \;
	-rm $(GOAL_NAME).out
	-rm $(GOAL_NAME).synctex.gz
	
cleanall: clean cleanbuild
	
cleanbuild:
	-rm $(GOAL_NAME).pdf

testbuild: build cleanall

.PHONY: all build clean cleanall cleanbuild testbuild