#!/usr/bin/env bash

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

SETTING_FILE_PATH=${HOME}/Dropbox/Coding/ProgrammingContests/setting.json
SETTING_FILE_NAME=".onlinejudgehelper.setting.json"
if [ -f ${SETTING_FILE_PATH} ]; then
    ln -ivs ${SETTING_FILE_PATH} ${HOME}/${SETTING_FILE_NAME}
fi
