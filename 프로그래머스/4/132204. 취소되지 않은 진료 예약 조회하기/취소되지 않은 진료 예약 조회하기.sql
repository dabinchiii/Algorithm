# 2022년 4월 13일 취소되지 않은 흉부외과(CS) 진료 예약 내역을 조회
# 진료예약번호, 환자이름, 환자번호, 진료과코드, 의사이름, 진료예약일시 항목 출력
# 결과는 진료예약일시를 기준으로 오름차순 정렬
WITH TARGET_APNT AS (
    SELECT *
    FROM APPOINTMENT
    WHERE APNT_CNCL_YN = 'N'
        AND MCDP_CD = 'CS'
        AND DATE(APNT_YMD) = DATE('2022-04-13')
)
SELECT
    A.APNT_NO AS PTNO_NO,
    P.PT_NAME,
    A.PT_NO,
    A.MCDP_CD,
    D.DR_NAME,
    A.APNT_YMD
FROM TARGET_APNT AS A
JOIN PATIENT AS P
    ON A.PT_NO = P.PT_NO
JOIN DOCTOR AS D
    ON A.MDDR_ID = D.DR_ID
ORDER BY APNT_YMD;