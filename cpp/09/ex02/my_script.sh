#!/bin/bash

# 랜덤으로 3000개의 양수 정수 생성 및 문자열로 구성
param_string=""
for ((i = 0; i < 10; i++)); do
    # 랜덤 숫자 생성 (1 이상부터 최대값까지의 범위)
    max_value=100  # 원하는 최대값으로 대체
    random_number=$((1 + RANDOM % max_value))
    
    # 생성한 숫자가 0보다 큰 경우에만 문자열에 추가
    if [ "$random_number" -gt 0 ]; then
        param_string="$param_string $random_number"
    fi
done

# 프로그램 실행 (하나의 문자열로 전달)
./PmergeMe $param_string
