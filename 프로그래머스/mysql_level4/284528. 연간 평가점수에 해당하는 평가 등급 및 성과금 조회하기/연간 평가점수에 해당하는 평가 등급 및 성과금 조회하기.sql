# 사원별로 사번, 성명, 평가 등급, 성과금을 조회
# 평가등급의 컬럼명은 GRADE로, 성과금의 컬럼명은 BONUS
# 결과는 사번 기준으로 오름차순 정렬
    # 기준 점수	   평가 등급	성과금(연봉 기준)
    # 96 이상	    S	       20%
    # 90 이상	    A	       15%
    # 80 이상 	B	       10%
    # 이외	    C	       0%
SELECT
    EMP.EMP_NO,
    EMP.EMP_NAME,
    CASE 
        WHEN G.SCORE >= 96 THEN 'S'
        WHEN G.SCORE >= 90 THEN 'A'
        WHEN G.SCORE >= 80 THEN 'B'
        ELSE 'C'
    END AS GRADE,
    CASE 
        WHEN G.SCORE >= 96 THEN EMP.SAL * 0.2
        WHEN G.SCORE >= 90 THEN EMP.SAL * 0.15
        WHEN G.SCORE >= 80 THEN EMP.SAL * 0.1
        ELSE 0
    END AS BONUS
FROM HR_EMPLOYEES EMP
JOIN (
    SELECT
        EMP_NO,
        AVG(SCORE) AS SCORE
    FROM HR_GRADE
    WHERE YEAR = 2022
    GROUP BY EMP_NO
) G ON EMP.EMP_NO = G.EMP_NO
ORDER BY EMP_NO ASC;