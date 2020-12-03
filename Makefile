.PHONY: all test clean graphblas-java graphblas-java-clean graphblas

all: graphblas-java
	mvn clean install

graphblas-java: graphblas
	cd graphblas-java ; \
		mvn clean install

graphblas-java-clean:
	cd graphblas-java; \
		mvn clean

clean: graphblas-java-clean
	mvn clean

graphblas:
	cd GraphBLAS; \
		make clean; make install
