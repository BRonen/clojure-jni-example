#!/usr/bin/env sh

javac -h . Foo.java;
javac -h Accumulator Accumulator/Acc.java;
javac -h Asm Asm/Asm.java;
cc -shared -fpic -o libfoo.so -I"${JAVA_HOME}/include" -I"${JAVA_HOME}/include/linux" foo.c;
cc -shared -fpic -o libacc.so -I"${JAVA_HOME}/include" -I"${JAVA_HOME}/include/linux" ./Accumulator/acc.c;
cc -shared -fpic -o libasm.so -I"${JAVA_HOME}/include" -I"${JAVA_HOME}/include/linux" ./Asm/asm.c;
