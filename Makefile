.PHONY: all test clean graphblas-java graphblas-java-clean graphblas

GRB_LIB=GraphBLAS/build/install_manifest.txt

all: graphblas-java
	mvn clean install

graphblas-java: $(GRB_LIB)
	cd graphblas-java ; \
		mvn clean install

graphblas-java-clean:
	cd graphblas-java; \
		mvn clean

clean: graphblas-java-clean
	mvn clean

$(GRB_LIB):
	cd GraphBLAS; \
		make clean; make JOBS=8 install
