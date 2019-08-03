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
    SUFFIX=.cpp
elif [ $LANGUAGE == "rust" ] ; then
    SUFFIX=.rs
fi
FILENAME=$1$2$SUFFIX
../oj.py --atcoder --submit -i $FILENAME $1 $2
exit 0
