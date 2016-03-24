#!/bin/sh

while inotifywait -e modify ./*tex; do
  pdflatex -output-format pdf -jobname=exam 2016
  pdflatex -output-format pdf -jobname=exam 2016
  rm *aux *log *out *toc *bib *tex\~ *.nav *bbl *blg *snm
done
