# 2022년 4월 13일 취소되지 않은 흉부외과(CS) 진료 예약 내역을 조회
# 진료예약번호, 환자이름, 환자번호, 진료과코드, 의사이름, 진료예약일시 항목을 출력
# 결과는 진료예약일시를 기준으로 오름차순 정렬
SELECT
    APNT.APNT_NO,
    PT.PT_NAME,
    APNT.PT_NO,
    APNT.MCDP_CD,
    DR.DR_NAME,
    APNT.APNT_YMD
FROM (
    SELECT *
    FROM APPOINTMENT
    WHERE DATEDIFF(APNT_YMD, '2022-04-13') = 0
    AND APNT_CNCL_YN = 'N'
    AND MCDP_CD = 'CS'
) AS APNT
LEFT JOIN PATIENT AS PT
    ON APNT.PT_NO = PT.PT_NO
LEFT JOIN DOCTOR AS DR
    ON APNT.MDDR_ID = DR.DR_ID
ORDER BY APNT.APNT_YMD ASC;