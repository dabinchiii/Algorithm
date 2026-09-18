# 식품분류별로 가격이 제일 비싼 식품의 분류, 가격, 이름을 조회
# 식품분류가 '과자', '국', '김치', '식용유'인 경우만 출력
# 결과는 식품 가격을 기준으로 내림차순 정렬
WITH TEMP AS (
    SELECT
        CATEGORY,
        PRICE,
        PRODUCT_NAME,
        RANK() OVER (
            PARTITION BY CATEGORY
            ORDER BY PRICE DESC
        ) AS RNK
    FROM FOOD_PRODUCT
    WHERE CATEGORY IN ('과자', '국', '김치', '식용유')
)
SELECT
    CATEGORY,
    PRICE AS MAX_PRICE,
    PRODUCT_NAME
FROM TEMP
WHERE RNK = 1
ORDER BY MAX_PRICE DESC;