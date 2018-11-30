#!/bin/bash

java -Djava.class.path=./main.jar --module-path ./jfx --add-modules=javafx.controls net.joshuad.test.Main
