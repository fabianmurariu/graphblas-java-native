.PHONY: all test clean graphblas-java graphblas-java-clean

all: graphblas-java
	mvn clean install

graphblas-java:
	cd graphblas-java ; \
		mvn clean install

graphblas-java-clean:
	cd graphblas-java; \
		mvn clean

clean: graphblas-java-clean
	mvn clean
