set macros

set terminal epslatex standalone size width,height header \
" \\usepackage[utf8]{inputenc} \n \
  \\usepackage[british]{babel} \n \
  \\usepackage[T1]{fontenc} \n \
  \\usepackage{lmodern} \n \
  \\usepackage{esvect} \n \
  \\usepackage{commath} \n \
  \\usepackage{amsmath} \n \
  \\usepackage{amssymb} \n \
  \\usepackage{nicefrac} \n \
  \\usepackage[output-decimal-marker={.},per-mode=fraction,fraction-function=\nicefrac,range-phrase={\ldots},separate-uncertainty,multi-part-units=repeat,binary-units,detect-all=true]{siunitx} \n \
  \\usepackage[version=3]{mhchem} \
  \\renewcommand{\\familydefault}{\\sfdefault} \n \
  \\usepackage[lm]{sfmath} \n \
  \\usepackage{microtype} \n" \
 colour colourtext font 12

set out @filebase.".tex"
