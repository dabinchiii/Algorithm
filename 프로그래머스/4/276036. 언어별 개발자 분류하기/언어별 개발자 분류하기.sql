# GRADE가 존재하는 개발자의 GRADE, ID, EMAIL을 조회
# GRADE는 다음과 같이 정해짐
    # A : Front End 스킬과 Python 스킬을 함께 가지고 있는 개발자
    # B : C# 스킬을 가진 개발자
    # C : 그 외의 Front End 개발자
# 결과는 GRADE와 ID를 기준으로 오름차순 정렬
WITH FRONTEND AS (
    SELECT BIT_OR(CODE) AS CODE
    FROM SKILLCODES
    WHERE CATEGORY = 'Front End'
),
PYTHON AS (
    SELECT CODE
    FROM SKILLCODES
    WHERE NAME = 'Python'
),
CSHARP AS (
    SELECT CODE
    FROM SKILLCODES
    WHERE NAME = 'C#'
),
TEMP AS (
    SELECT
        CASE
            WHEN SKILL_CODE & FRONTEND.CODE != 0
                AND SKILL_CODE & PYTHON.CODE != 0
                THEN 'A'
            WHEN SKILL_CODE & CSHARP.CODE != 0
                THEN 'B'
            WHEN SKILL_CODE & FRONTEND.CODE != 0
                THEN 'C'
            ELSE NULL
        END AS GRADE,
        ID,
        EMAIL
    FROM DEVELOPERS, FRONTEND, PYTHON, CSHARP
)
SELECT *
FROM TEMP
WHERE GRADE IS NOT NULL
ORDER BY GRADE, ID;