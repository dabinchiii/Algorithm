# 우유와 요거트를 동시에 구입한 장바구니의 아이디를 조회
# 결과는 장바구니의 아이디 순
SELECT CART_ID
FROM CART_PRODUCTS
GROUP BY CART_ID
HAVING BIT_OR(
    CASE NAME
        WHEN 'Milk' THEN 1
        WHEN 'Yogurt' THEN 2
        ELSE 0
    END
) = 3
ORDER BY CART_ID;