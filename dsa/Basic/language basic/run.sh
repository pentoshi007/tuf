#!/bin/bash

# Optimized C++ Competitive Programming Runner
# Compatible with Clang on macOS Apple Silicon
# Usage: ./run.sh [filename] [mode]
# Modes: fast (default), debug, time

FILENAME=${1:-setup}
MODE=${2:-fast}
CPP_FILE="${FILENAME}.cpp"
EXEC_FILE="${FILENAME}"

# Color codes for better output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${BLUE}🚀 Clang C++20 Compiler (Apple Silicon Optimized)${NC}"
echo -e "📁 Compiling: ${YELLOW}${CPP_FILE}${NC}"

case $MODE in
    "debug")
        echo -e "🐛 Debug mode with extra warnings"
        clang++ -std=c++20 -g -DDEBUG -Wall -Wextra -o "${EXEC_FILE}_debug" "${CPP_FILE}"
        EXEC_FILE="${EXEC_FILE}_debug"
        ;;
    "time")
        echo -e "⏱️  Performance timing mode"
        clang++ -std=c++20 -O2 -Wall -o "${EXEC_FILE}" "${CPP_FILE}"
        ;;
    *)
        echo -e "⚡ Fast optimized compilation"
        clang++ -std=c++20 -O2 -Wall -o "${EXEC_FILE}" "${CPP_FILE}"
        ;;
esac

if [ $? -eq 0 ]; then
    echo -e "${GREEN}✅ Compilation successful!${NC}"
    
    if [ "$MODE" == "time" ]; then
        echo -e "🕐 Running with timing..."
        time ./"${EXEC_FILE}" < input.txt > output.txt
    else
        echo -e "🔄 Running: input.txt → output.txt"
        ./"${EXEC_FILE}" < input.txt > output.txt
    fi
    
    echo -e "${BLUE}📤 Output:${NC}"
    cat output.txt
    
    # Show input for reference
    echo -e "\n${BLUE}📥 Input was:${NC}"
    cat input.txt
    
else
    echo -e "${RED}❌ Compilation failed!${NC}"
    exit 1
fi
