# 2022년도 평가 점수가 가장 높은 사원들의 점수, 사번, 성명, 직책, 이메일을 조회
# 2022년도의 평가 점수는 상,하반기 점수의 합을 의미
# 평가 점수를 나타내는 컬럼의 이름은 SCORE
SELECT
    TOTAL_SCORE AS SCORE,
    EMP_NO,
    EMP_NAME,
    POSITION,
    EMAIL
FROM (
    SELECT
        EMP.EMP_NO,
        EMP.EMP_NAME,
        EMP.POSITION,
        EMP.EMAIL,
        SUM(G.SCORE) AS TOTAL_SCORE,
        RANK() OVER (ORDER BY SUM(G.SCORE) DESC) AS R
    FROM HR_EMPLOYEES AS EMP
    JOIN HR_GRADE AS G
        ON EMP.EMP_NO = G.EMP_NO
    WHERE YEAR = 2022
    GROUP BY G.EMP_NO
) AS T
WHERE R = 1;
    