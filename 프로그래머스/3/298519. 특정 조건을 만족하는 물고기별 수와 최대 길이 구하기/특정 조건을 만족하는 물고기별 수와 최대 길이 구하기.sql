# 평균 길이가 33cm 이상인 물고기들을 종류별로 분류하여,
# 잡은 수, 최대 길이, 물고기의 종류를 출력
# 결과는 물고기 종류에 대해 오름차순으로 정렬
# 10cm이하의 물고기들은 10cm로 취급하여 평균 길이를 구해주세요.
SELECT
    COUNT(*) AS FISH_COUNT,
    MAX(LENGTH) AS MAX_LENGTH,
    FISH_TYPE
FROM FISH_INFO
GROUP BY FISH_TYPE
HAVING AVG(IF(LENGTH <= 10, 10, LENGTH)) >= 33
ORDER BY FISH_TYPE ASC;