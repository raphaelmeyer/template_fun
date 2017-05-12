#!/bin/bash

PROJECT_ROOT=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
BUILD=${PROJECT_ROOT}/build

while getopts "c:" arg ; do
  case ${arg} in
    c)
      case ${OPTARG} in
        gcc)
          export CC=gcc
          export CXX=g++
          BUILD=${PROJECT_ROOT}/gcc-build
          ;;
        clang)
          export CC=clang
          export CXX=clang++
          BUILD=${PROJECT_ROOT}/clang-build
          ;;
      esac
      ;;
  esac
done

if [ ! -d ${BUILD} ] ; then
  mkdir -p ${BUILD}
fi

cd ${BUILD}
cmake ${PROJECT_ROOT}
make

