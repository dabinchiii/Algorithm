# 부서별로 부서 ID, 영문 부서명, 평균 연봉을 조회
# 평균연봉은 소수점 첫째 자리에서 반올림하고 컬럼명은 AVG_SAL
# 결과는 부서별 평균 연봉을 기준으로 내림차순 정렬
SELECT
    EMP.DEPT_ID,
    DEPT.DEPT_NAME_EN,
    EMP.AVG_SAL
FROM (
    SELECT
        DEPT_ID,
        ROUND(AVG(SAL), 0) AS AVG_SAL
    FROM HR_EMPLOYEES
    GROUP BY DEPT_ID
) EMP JOIN HR_DEPARTMENT DEPT
    ON EMP.DEPT_ID = DEPT.DEPT_ID
ORDER BY EMP.AVG_SAL DESC;