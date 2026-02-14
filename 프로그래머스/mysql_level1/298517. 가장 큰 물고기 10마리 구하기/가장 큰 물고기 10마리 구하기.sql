# 가장 큰 물고기 10마리의 ID와 길이를 출력
# 결과는 길이를 기준으로 내림차순 정렬하고, 길이가 같다면 물고기의 ID에 대해 오름차순 정렬
# D 컬럼명은 ID, 길이 컬럼명은 LENGTH로 해주세요.
SELECT ID, LENGTH
FROM FISH_INFO
ORDER BY LENGTH DESC, ID ASC
LIMIT 10;