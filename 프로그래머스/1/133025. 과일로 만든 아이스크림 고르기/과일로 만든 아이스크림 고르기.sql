# 상반기 아이스크림 총주문량이 3,000보다 높으면서 아이스크림의 주 성분이 과일인 아이스크림의 맛을
# 총주문량이 큰 순서대로 조회
SELECT
    FH.FLAVOR
FROM FIRST_HALF FH
JOIN ICECREAM_INFO I
    ON FH.FLAVOR = I.FLAVOR
WHERE FH.TOTAL_ORDER > 3000
    AND I.INGREDIENT_TYPE = 'fruit_based'
ORDER BY FH.TOTAL_ORDER DESC;