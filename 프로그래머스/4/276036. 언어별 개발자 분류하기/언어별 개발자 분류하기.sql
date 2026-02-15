# GRADE가 존재하는 개발자의 GRADE, ID, EMAIL을 조회
# GRADE는 다음과 같이 정해집니다.
    # A : Front End 스킬과 Python 스킬을 함께 가지고 있는 개발자
    # B : C# 스킬을 가진 개발자
    # C : 그 외의 Front End 개발자
# 결과는 GRADE와 ID를 기준으로 오름차순 정렬
SELECT
    CASE
        WHEN HAS_FRONTEND = 1 AND HAS_PYTHON = 1 THEN 'A'
        WHEN HAS_CSHARP = 1 THEN 'B'
        WHEN HAS_FRONTEND THEN 'C'
    END AS GRADE,
    ID,
    EMAIL
FROM (
    SELECT
        ID,
        EMAIL,
        IF(
            SKILL_CODE & (
                SELECT BIT_OR(CODE)
                FROM SKILLCODES
                WHERE CATEGORY = 'Front End'
            ) != 0, 1, 0
        ) AS HAS_FRONTEND,
        IF(
            SKILL_CODE & (
                SELECT CODE
                FROM SKILLCODES
                WHERE NAME = 'Python'
            ) != 0, 1, 0
        ) AS HAS_PYTHON,
        IF(
            SKILL_CODE & (
                SELECT CODE
                FROM SKILLCODES
                WHERE NAME = 'C#'
            ) != 0, 1, 0
        ) AS HAS_CSHARP
    FROM DEVELOPERS
) T
WHERE HAS_FRONTEND + HAS_CSHARP != 0
ORDER BY GRADE ASC, ID ASC;
