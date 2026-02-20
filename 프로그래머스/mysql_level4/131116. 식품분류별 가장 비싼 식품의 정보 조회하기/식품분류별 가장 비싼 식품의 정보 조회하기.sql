# 식품분류별로 가격이 제일 비싼 식품의 분류, 가격, 이름을 조회
# 식품분류가 '과자', '국', '김치', '식용유'인 경우만 출력
# 결과는 식품 가격을 기준으로 내림차순 정렬
SELECT
    CATEGORY,
    PRICE AS MAX_PRICE,
    PRODUCT_NAME
FROM (
    SELECT
        CATEGORY,
        PRICE,
        PRODUCT_NAME,
        RANK() OVER (
            PARTITION BY CATEGORY
            ORDER BY PRICE DESC
        ) AS R
    FROM FOOD_PRODUCT
) T
WHERE R = 1
    AND CATEGORY IN ('과자', '국', '김치', '식용유')
ORDER BY PRICE DESC;