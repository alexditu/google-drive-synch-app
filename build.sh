#!/bin/bash

BUILD_DIR=./build

function build() {
	BUILD_TYPE="$1"
	CLEAN="$2"

	echo "building for ${BUILD_TYPE}"

	BUILD_PATH="${BUILD_DIR}-${BUILD_TYPE,,}"
	if [ -d "${BUILD_PATH}" ] && [ "x${CLEAN}" = "xy" ]; then
		echo "cleaning previous build dir ${BUILD_PATH}"
		rm -rf "${BUILD_PATH}"
	fi

	mkdir -p "${BUILD_PATH}"
	cd "${BUILD_PATH}"

	cmake -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" ..
	cmake --build .

	cd ..
}

#build Debug
build Release


