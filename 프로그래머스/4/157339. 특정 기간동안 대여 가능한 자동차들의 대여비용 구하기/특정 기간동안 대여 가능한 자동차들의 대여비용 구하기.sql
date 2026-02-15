# 자동차 종류가 '세단' 또는 'SUV' 인 자동차 중
# 2022년 11월 1일부터 2022년 11월 30일까지 대여 가능하고,
# 30일간의 대여 금액이 50만원 이상 200만원 미만인 자동차에 대해서
# 자동차 ID, 자동차 종류, 대여 금액(컬럼명: FEE) 리스트를 출력
# 결과는 대여 금액을 기준으로 내림차순 정렬하고,
# 대여 금액이 같은 경우 자동차 종류를 기준으로 오름차순 정렬,
# 자동차 종류까지 같은 경우 자동차 ID를 기준으로 내림차순 정렬
SELECT
    TG.CAR_ID,
    TG.CAR_TYPE,
    ROUND(TG.FEE_30 * DC.DISCOUNT_RATE, 0) AS FEE
FROM (
    SELECT
        CAR_ID,
        CAR_TYPE,
        30 * DAILY_FEE AS FEE_30
    FROM CAR_RENTAL_COMPANY_CAR
    WHERE CAR_TYPE IN ('세단', 'SUV')
        AND CAR_ID NOT IN (
            SELECT CAR_ID
            FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
            WHERE START_DATE <= '2022-11-30'
                AND END_DATE >= '2022-11-01'
        )
) TG LEFT JOIN (
    SELECT 
        CAR_TYPE,
        (100 - DISCOUNT_RATE) * 0.01 AS DISCOUNT_RATE
    FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
    WHERE DURATION_TYPE = '30일 이상'
) DC ON TG.CAR_TYPE = DC.CAR_TYPE
WHERE ROUND(TG.FEE_30 * DC.DISCOUNT_RATE, 0) >= 500000
    AND ROUND(TG.FEE_30 * DC.DISCOUNT_RATE, 0) < 2000000
ORDER BY FEE DESC, CAR_TYPE ASC, CAR_ID DESC;