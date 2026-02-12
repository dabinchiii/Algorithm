# 상품코드 별 매출액(판매가 * 판매량) 합계를 출력
# 결과는 매출액을 기준으로 내림차순 정렬,
# 매출액이 같다면 상품코드를 기준으로 오름차순 정렬
SELECT
    P.PRODUCT_CODE,
    SUM(P.PRICE * S.SALES_AMOUNT) AS SALES
FROM OFFLINE_SALE S 
    LEFT JOIN PRODUCT P
    ON S.PRODUCT_ID = P.PRODUCT_ID
GROUP BY P.PRODUCT_CODE
ORDER BY SALES DESC, P.PRODUCT_CODE ASC;