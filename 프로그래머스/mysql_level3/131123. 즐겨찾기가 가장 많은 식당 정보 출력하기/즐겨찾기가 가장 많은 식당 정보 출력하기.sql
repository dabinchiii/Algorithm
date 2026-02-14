# 음식종류별로 즐겨찾기수가 가장 많은 식당의 음식 종류, ID, 식당 이름, 즐겨찾기수를 조회
# 결과는 음식 종류를 기준으로 내림차순 정렬
SELECT
    FOOD_TYPE,
    REST_ID,
    REST_NAME,
    FAVORITES
FROM (
    SELECT
        FOOD_TYPE,
        REST_ID,
        REST_NAME,
        FAVORITES,
        RANK() OVER (
            PARTITION BY FOOD_TYPE
            ORDER BY FAVORITES DESC
        ) AS R
    FROM REST_INFO
) T
WHERE R = 1
ORDER BY FOOD_TYPE DESC;