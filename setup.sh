#!/usr/bin/env bash

# Variable definitions
case $(uname) in
    Linux)
        echo "This is an linux environment. Setting up for linux"
        OS=linux
        ;;
    Darwin)
        echo "This is an mac os environment. Setting up for mac"
        OS=mac
        ;;
esac
# End variable definitions

BASE_DIR=${HOME}/Coding
INSTALL_DIR=${BASE_DIR}/ProgrammingContest
if ! [ -d ${BASE_DIR} ]; then
    mkdir -p ${BASE_DIR}
fi
if ! [ -d ${INSTALL_DIR} ]; then
    cd ${BASE_DIR}
    $(git clone git@github.com:yuishihara/ProgrammingContest.git)
fi
cd ${INSTALL_DIR}

ONLINE_JUDGE_HELPER_PATH=OnlineJudgeHelper
if ! [ -d ${ONLINE_JUDGE_HELPER_PATH} ]; then
    echo "Cloning online judge helper..."
    $(git clone https://github.com/nodchip/OnlineJudgeHelper.git)
fi

SERVICES="AtCoder Codeforces"
HELPER_SCRIPT="oj.py"
for service in ${SERVICES}; do
    echo ${service}
    if [ -d ${service} ]; then
        cd ${service}
        ln -ivs ../${ONLINE_JUDGE_HELPER_PATH}/${HELPER_SCRIPT} ${HELPER_SCRIPT}
        chmod +x ${HELPER_SCRIPT}
        cd ../
    fi
done

SETTING_FILE_PATH=${HOME}/Dropbox/Coding/ProgrammingContests
LINUX_SETTING_FILE_NAME="setting_linux.json"
MAX_SETTING_FILE_NAME="setting_mac.json"
SETTING_FILE_NAME=".onlinejudgehelper.setting.json"
case ${OS} in
    linux)
        ln -ivs ${SETTING_FILE_PATH}/${LINUX_SETTING_FILE_NAME} ${HOME}/${SETTING_FILE_NAME}
        ;;
    mac)
        ln -ivs ${SETTING_FILE_PATH}/${MAC_SETTING_FILE_NAME} ${HOME}/${SETTING_FILE_NAME}
        ;;
esac
