# 2022년 10월 16일에 대여 중인 자동차인 경우 '대여중' 이라고 표시하고, 대여 중이지 않은 자동차인 경우 '대여 가능'을 표시하는 컬럼(컬럼명: AVAILABILITY)을 추가하여 자동차 ID와 AVAILABILITY 리스트를 출력
# 이때 반납 날짜가 2022년 10월 16일인 경우에도 '대여중'으로 표시
# 결과는 자동차 ID를 기준으로 내림차순 정렬
WITH TEMP AS (
    SELECT
        CAR_ID,
        CASE
            WHEN 
                START_DATE <= DATE('2022-10-16')
                AND END_DATE >= DATE('2022-10-16')
            THEN 1
            ELSE 0
        END AS STATUS
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
)

SELECT
    CAR_ID,
    CASE
        WHEN BIT_OR(STATUS) = 1 THEN '대여중'
        ELSE '대여 가능'
    END AS AVAILABILITY
FROM TEMP
GROUP BY CAR_ID
ORDER BY CAR_ID DESC;