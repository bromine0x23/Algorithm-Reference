GOAL_NAME = Code
$(GOAL_NAME).pdf
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

pdf: $(GOAL_NAME).pdf

build: cleanbuild $(GOAL_NAME).pdf

$(GOAL_NAME).pdf: $(GOAL_NAME).tex
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
	find . -name '*.acn' -type f -print -exec rm -rf {} \;
	find . -name '*.acr' -type f -print -exec rm -rf {} \;
	find . -name '*.alg' -type f -print -exec rm -rf {} \;
	find . -name '*.aux' -type f -print -exec rm -rf {} \;
	find . -name '*.bbl' -type f -print -exec rm -rf {} \;
	find . -name '*.blg' -type f -print -exec rm -rf {} \;
	find . -name '*.dvi' -type f -print -exec rm -rf {} \;
	find . -name '*.fdb_latexmk' -type f -print -exec rm -rf {} \;
	find . -name '*.glg' -type f -print -exec rm -rf {} \;
	find . -name '*.glo' -type f -print -exec rm -rf {} \;
	find . -name '*.gls' -type f -print -exec rm -rf {} \;
	find . -name '*.idx' -type f -print -exec rm -rf {} \;
	find . -name '*.ilg' -type f -print -exec rm -rf {} \;
	find . -name '*.ind' -type f -print -exec rm -rf {} \;
	find . -name '*.ist' -type f -print -exec rm -rf {} \;
	find . -name '*.lof' -type f -print -exec rm -rf {} \;
	find . -name '*.log' -type f -print -exec rm -rf {} \;
	find . -name '*.lot' -type f -print -exec rm -rf {} \;
	find . -name '*.maf' -type f -print -exec rm -rf {} \;
	find . -name '*.mtc' -type f -print -exec rm -rf {} \;
	find . -name '*.mtc0' -type f -print -exec rm -rf {} \;
	find . -name '*.nav' -type f -print -exec rm -rf {} \;
	find . -name '*.nlo' -type f -print -exec rm -rf {} \;
	find . -name '*.out' -type f -print -exec rm -rf {} \;
	find . -name '*.pdfsync' -type f -print -exec rm -rf {} \;
	find . -name '*.ps' -type f -print -exec rm -rf {} \;
	find . -name '*.snm' -type f -print -exec rm -rf {} \;
	find . -name '*.synctex.gz' -type f -print -exec rm -rf {} \;
	find . -name '*.toc' -type f -print -exec rm -rf {} \;
	find . -name '*.tdo' -type f -print -exec rm -rf {} \;
	find . -name '*.vrb' -type f -print -exec rm -rf {} \;
	find . -name '*.xdy' -type f -print -exec rm -rf {} \;
	
cleanall: clean cleanbuild
	
cleanbuild:
	-rm $(GOAL_NAME).pdf

testbuild: build cleanall

.PHONY: all build clean cleanall cleanbuild testbuild