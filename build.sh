#!/bin/bash
BUILD_DIR = "build"

usage() {
    echo "Usage: $0 [options]"
    echo "Options:"
    echo " -b, --build  Nur Build ausführen"
    echo " -t, --test   Build und Tests ausführen"
    echo " -h, --help   Zeigt Hilfe"
    exit 1
}

# Remove build folder
rm -rf $BUILD_DIR

run_build() {
    echo "Start build process..."
    if [ ! -d "$BUILD_DIR" ]; then
        mkdir "$BUILD_DIR"
    fi
    cd "$BUILD_DIR" || exit 1
}