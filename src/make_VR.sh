#!/bin/bash
g++ DisplayImage.cpp -o VR `pkg-config --cflags --libs opencv`

