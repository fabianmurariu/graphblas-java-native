# JNI bindings for GraphBLAS

## Build and get the code

```bash 
git clone --recurse-submodules https://github.com/fabianmurariu/graphblas-java-native.git

# this will build GraphBLAS for you and build the maven java project
make graphblas-java

# to install GraphBLAS

sudo make grb-install

# if you don't wish to install you need to set 
# LD_LIBRARY_PATH=$(pwd)/GraphBLAS/build:$LD_LIBRARY_PATH 
# before running the maven tests outside of make
```
## For usage check tests
in [GRAPHBLASSpec.scala](https://github.com/fabianmurariu/graphblas-java-native/blob/master/graphblas-java/src/test/scala/com/github/fabianmurariu/unsafe/GRAPHBLASSpec.scala)

### Create a Matrix

```scala
  Buffer mat = GRBCORE.createMatrix(GRAPHBLAS.booleanType(), rows, cols)
```
