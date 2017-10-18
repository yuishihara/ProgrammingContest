#/bin/bash
USAGE="usage: ./newcode.sh [ContestId] [ProblemId], example: ./newcode.sh practice 2"

if test $# -ge 3 ; then
    echo too much arguments
    echo $USAGE
    exit 1
elif test $# -le 1 ; then
    echo too few arguments
    echo $USAGE
    exit 1
fi

TEMPLATE_FILE=../Template/Template.cpp
CPP_SUFFIX=.cpp
CPP_FILENAME=$1$2$CPP_SUFFIX
cp $TEMPLATE_FILE $CPP_FILENAME
exit 0
