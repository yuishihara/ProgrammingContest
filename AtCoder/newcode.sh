#/bin/bash
USAGE="usage: ./newcode.sh [ContestId] [ProblemId] [Language], example: ./newcode.sh practice 2"

if test $# -ge 4 ; then
    echo too much arguments
    echo $USAGE
    exit 1
elif test $# -le 1 ; then
    echo too few arguments
    echo $USAGE
    exit 1
fi

LANGUAGE=$3
if [ $LANGUAGE == "cpp" ] ; then
    TEMPLATE_FILE=../../Template/$LANGUAGE/Template.cpp
    SUFFIX=.cpp
elif [ $LANGUAGE == "rust" ] ; then
    TEMPLATE_FILE=../../Template/$LANGUAGE/Template.rs
    SUFFIX=.rs
fi
FILENAME=$1$2$SUFFIX
cp $TEMPLATE_FILE $FILENAME
exit 0
