.PHONY: all test clean graphblas-java graphblas-java-clean graphblas

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
ROOT_DIR := $(dir $(mkfile_path))
GRB_BUILD= $(ROOT_DIR)GraphBLAS/build
GRB_LIB=$(GRB_BUILD)/libgraphblas.so

all: graphblas-java
	mvn clean install

graphblas-java: $(GRB_LIB)
	cd $(ROOT_DIR)graphblas-java ; \
		LD_LIBRARY_PATH=$(GRB_BUILD):$$LD_LIBRARY_PATH mvn clean install

graphblas-java-clean:
	cd $(ROOT_DIR)graphblas-java; \
		mvn clean

clean: graphblas-java-clean
	cd $(ROOT_DIR); \
		graphblas-java mvn clean

$(GRB_LIB):
	cd GraphBLAS; \
		make clean; make JOBS=8 library

grb-install:
	cd $(ROOT_DIR)/GraphBLAS; \
		make install
