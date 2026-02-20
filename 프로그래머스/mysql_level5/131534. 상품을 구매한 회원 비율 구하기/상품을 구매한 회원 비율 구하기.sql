# 2021년에 가입한 전체 회원들 중
# 상품을 구매한 회원수와 상품을 구매한 회원의 비율을 년, 월 별로 출력
# 회원의 비율
    # = 2021년에 가입한 회원 중 상품을 구매한 회원수 / 2021년에 가입한 전체 회원 수
# 상품을 구매한 회원의 비율은 소수점 두번째자리에서 반올림
# 전체 결과는 년을 기준으로 오름차순 정렬해주시고,
# 년이 같다면 월을 기준으로 오름차순 정렬
SELECT DISTINCT
    S.YEAR,
    S.MONTH,
    COUNT(S.USER_ID) AS PURCHASED_USERS,
    ROUND(
        COUNT(S.USER_ID) / TOTAL.TOTAL_CNT
    , 1) AS PUCHASED_RATIO
FROM (
    SELECT DISTINCT
        USER_ID,
        YEAR(SALES_DATE) AS YEAR,
        MONTH(SALES_DATE) AS MONTH
    FROM ONLINE_SALE
) S
JOIN USER_INFO I
    ON S.USER_ID = I.USER_ID
        AND YEAR(I.JOINED) = 2021
CROSS JOIN (
    SELECT COUNT(*) AS TOTAL_CNT
    FROM USER_INFO
    WHERE YEAR(JOINED) = 2021
) TOTAL
GROUP BY S.YEAR, S.MONTH
ORDER BY S.YEAR ASC, S.MONTH ASC;
