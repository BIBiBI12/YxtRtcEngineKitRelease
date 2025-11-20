#!/bin/bash

# 颜色定义
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# 提示输入 commit 信息
echo -e "${YELLOW}请输入 commit 信息:${NC}"
read -r commit_message

# 检查是否输入了 commit 信息
if [ -z "$commit_message" ]; then
    echo -e "${RED}错误: commit 信息不能为空${NC}"
    exit 1
fi

# 从 podspec 文件中提取版本号
version=$(grep -E '^\s*s\.version\s*=' YxtRtcEngineKit.podspec | sed -E 's/.*"([^"]+)".*/\1/')

if [ -z "$version" ]; then
    echo -e "${RED}错误: 无法从 YxtRtcEngineKit.podspec 中提取版本号${NC}"
    exit 1
fi

echo -e "${GREEN}提取到版本号: ${version}${NC}"

# 1. Git 提交
echo -e "${YELLOW}正在添加文件到 git...${NC}"
git add .
if [ $? -ne 0 ]; then
    echo -e "${RED}错误: git add 失败${NC}"
    exit 1
fi

echo -e "${YELLOW}正在提交 commit...${NC}"
git commit -m "$commit_message"
if [ $? -ne 0 ]; then
    echo -e "${RED}错误: git commit 失败${NC}"
    exit 1
fi

# 2. 打 tag
echo -e "${YELLOW}正在创建 tag: ${version}...${NC}"
git tag "$version"
if [ $? -ne 0 ]; then
    echo -e "${RED}错误: 创建 tag 失败${NC}"
    exit 1
fi

# 3. Push 到远端仓库

echo -e "${YELLOW}正在 push tag 到远端...${NC}"
git push hub "$version"
if [ $? -ne 0 ]; then
    echo -e "${RED}错误: git push tag 失败${NC}"
    exit 1
fi

# 4. 执行本地的 podPush.sh 脚本
echo -e "${GREEN}Git 操作完成！${NC}"
echo -e "${YELLOW}正在执行 podPush.sh...${NC}"

if [ -f "./podPush.sh" ]; then
    chmod +x ./podPush.sh
    ./podPush.sh
    if [ $? -ne 0 ]; then
        echo -e "${RED}警告: podPush.sh 执行失败${NC}"
        exit 1
    fi
    echo -e "${GREEN}所有操作完成！${NC}"
else
    echo -e "${RED}错误: podPush.sh 文件不存在${NC}"
    exit 1
fi
