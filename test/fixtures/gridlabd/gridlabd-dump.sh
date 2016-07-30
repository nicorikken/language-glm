#!/bin/bash
GRIDLABD="gridlabd"

function module2classes {
  # For a given GridLAB-D module, outputing included classes
  $GRIDLABD --modhelp $1 2>/dev/null | sed -n -e '/^ *class *[a-zA-Z0-9]*/p' | sed 's/^ *class *\([a-z]*\).*/\1/' | uniq
}

function dump_examples {
  # For a given GridLAB-D module, dumping generated examples into a file
  MOD=$1
  CLASSES=$(module2classes $MOD)

  if [[ -n $CLASSES ]]; then
    EXAMPLEFILE="$MOD.glm"
    echo "classes  found  for  $MOD: $CLASSES" | paste -sd " " -
    echo "// Examples for module $MOD" > "$EXAMPLEFILE"
    printf "progress: "
    for CLASS in $CLASSES; do
      # if [[ $CLASS != "auction" && $CLASS != "stubauction" ]]; then
        # printf "\n" >> "$EXAMPLEFILE"
        echo -e "\n// class $CLASS" >> $EXAMPLEFILE
        printf "$CLASS "
        # commands outputs to stderr
        # timeout and sed to deal with market:auction and market:stubauction examples starting a simulation
        timeout 1 $GRIDLABD --example "$MOD:$CLASS" &>> $EXAMPLEFILE
      # else
        # printf "\nwarning: "
        # $GRIDLABD --example "$MOD:$CLASS" >> "$EXAMPLEFILE"
      # fi
    done
    printf "\n"
    echo "examples dumped into $EXAMPLEFILE"
    return 0;
  else
    echo "warning: no classes found for module $MOD"
    return 1;
  fi
}

if hash $GRIDLABD &>/dev/null; then

  read -d '' MODULES <<"EOF"
climate
market
powerflow
residential
reliability
assert
tape
EOF

  for MOD in $MODULES; do
    # gridlabd --modhelp powerflow > powerflow.cpp
    $GRIDLABD --modhelp $MOD > $MOD.cpp
    echo "modhelp  dumped into $MOD.cpp"
    dump_examples $MOD 2>/dev/null
  done
  echo "cleaning incidental simulation files..."
  rm gridlabd.{err,wrn,xml}
  exit 0;
else
  echo "error: gridlabd command not available" >/dev/stderr
  exit 1;
fi
