# C++ Solutions for the Book

Some of the solutions were inspired by the [Book's official repository](https://github.com/careercup/CtCI-6th-Edition-cpp).

### Requirements
* CMake >= 3.14
* Valgrind (optional)

### Test them out!

To run the exercises and their tests:

1 - Create a CMake Build Environment
```(bash)
mkdir build 
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

2 - Call CTest
```(bash)
ctest
```
or, in order to see stdout:
```(bash)
ctest --verbose
```

3 - (Optional) Check any memory leakage in the exercises
ctest -T memcheck