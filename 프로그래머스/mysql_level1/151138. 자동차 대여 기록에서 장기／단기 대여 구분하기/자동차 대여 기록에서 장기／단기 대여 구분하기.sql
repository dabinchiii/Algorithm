# 대여 시작일이 2022년 9월에 속하는 대여 기록에 대해서
# 대여 기간이 30일 이상이면 '장기 대여' 그렇지 않으면 '단기 대여' 로 표시하는
# 컬럼(컬럼명: RENT_TYPE)을 추가하여 대여기록을 출력
# 결과는 대여 기록 ID를 기준으로 내림차순 정렬
SELECT 
    HISTORY_ID,
    CAR_ID,
    DATE_FORMAT(START_DATE, '%Y-%m-%d') AS START_DATE,
    DATE_FORMAT(END_DATE, '%Y-%m-%d') AS END_DATE,
    IF(DATEDIFF(END_DATE, START_DATE) + 1 >= 30, '장기 대여', '단기 대여')
        AS RENT_TYPE
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE START_DATE >= '2022-09-01'
    AND START_DATE < '2022-10-01'
ORDER BY HISTORY_ID DESC;