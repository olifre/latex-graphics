#!/bin/bash

set -e

rm -rf test
mkdir -p test
cp -ra src/* test
cp -ra examples/* test
cd test

pdflatex -interaction=batchmode -halt-on-error -shell-escape example.tex
