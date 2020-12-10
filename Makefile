.PHONY: all clean  graphblas-java-clean

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
ROOT_DIR := $(dir $(mkfile_path))
GRB_BUILD := $(ROOT_DIR)GraphBLAS/build
OS := $(shell uname -s)

ifeq ($(OS),Linux)
GRB_LIB := $(GRB_BUILD)/libgraphblas.so
else
GRB_LIB := $(GRB_BUILD)/libgraphblas.dynlib
endif

VERSION=

all: build
	mvn clean install

build: $(GRB_LIB)
	LD_LIBRARY_PATH=$(GRB_BUILD):$$LD_LIBRARY_PATH mvn clean install

graphblas-java-clean:
	mvn clean

clean: graphblas-java-clean
	cd $(ROOT_DIR)/GraphBLAS && make clean

$(GRB_LIB):
	cd GraphBLAS; \
		make clean; make JOBS=8 library

grb-install: $(GRB_LIB)
	cd $(ROOT_DIR)/GraphBLAS; \
		make install

set-Darwin-version:
	test $(VERSION)
	mvn versions:set -DnewVersion=$(VERSION)-mac
	mvn versions:update-child-modules

set-Linux-version:
	test $(VERSION)
	mvn versions:set -DnewVersion=$(VERSION)-linux
	mvn versions:update-child-modules

deploy:
	mvn deploy -pl graphblas-package
	mvn nexus-staging:release -pl graphblas-package

release: set-$(OS)-version deploy
