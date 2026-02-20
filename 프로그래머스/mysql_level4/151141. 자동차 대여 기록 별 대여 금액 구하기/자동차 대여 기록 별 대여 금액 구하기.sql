# 자동차 종류가 '트럭'인 자동차의 대여 기록에 대해서
# 대여 기록 별로 대여 금액(컬럼명: FEE)을 구하여 대여 기록 ID와 대여 금액 리스트를 출력
# 결과는 대여 금액을 기준으로 내림차순 정렬하고,
# 대여 금액이 같은 경우 대여 기록 ID를 기준으로 내림차순 정렬
SELECT
    H.HISTORY_ID,
    ROUND(
        (DATEDIFF(H.END_DATE, H.START_DATE) + 1)
        * C.DAILY_FEE
        * (100 - IFNULL(D.DISCOUNT_RATE, 0))
        * 0.01
    , 0) AS FEE
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY H
JOIN CAR_RENTAL_COMPANY_CAR C
    ON H.CAR_ID = C.CAR_ID AND C.CAR_TYPE = '트럭'
LEFT JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN D
    ON C.CAR_TYPE = D.CAR_TYPE
        AND D.DURATION_TYPE = (
            CASE
                WHEN DATEDIFF(H.END_DATE, H.START_DATE) + 1 >= 90 THEN '90일 이상'
                WHEN DATEDIFF(H.END_DATE, H.START_DATE) + 1 >= 30 THEN '30일 이상'
                WHEN DATEDIFF(H.END_DATE, H.START_DATE) + 1 >= 7 THEN '7일 이상'
            END
        )
ORDER BY FEE DESC, HISTORY_ID DESC;
