# 가장 큰 물고기의 길이를 'cm' 를 붙여 출력
# 컬럼명은 'MAX_LENGTH' 로 지정
SELECT CONCAT(MAX(LENGTH), 'cm') AS MAX_LENGTH
FROM FISH_INFO;