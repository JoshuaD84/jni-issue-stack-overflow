#!/bin/zsh

rm -rf bin main.jar

jdk="/usr/lib/jvm/java-11-oracle"

javac -d bin --module-path jfx src/**/*.java

jar cfm main.jar MANIFEST.MF -C bin .

g++ -I"$jdk/include/" \
-I"$jdk/include/linux" \
-L$jdk \
-L$jdk/lib/server/ \
src/cpp/launch.cpp -ljvm \
-o ./bin/launch

