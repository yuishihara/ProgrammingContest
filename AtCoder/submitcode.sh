#/bin/bash
USAGE="usage: ./codetest.sh [ContestId] [ProblemId], example: ./codetest.sh practice 2"

if test $# -ge 3 ; then
    echo too much arguments
    echo $USAGE
    exit 1
elif test $# -le 1 ; then
    echo too few arguments
    echo $USAGE
    exit 1
fi

CPP_SUFFIX=.cpp
CPP_FILENAME=$1$2$CPP_SUFFIX
./oj.py --atcoder --submit -i $CPP_FILENAME $1 $2
exit 0
