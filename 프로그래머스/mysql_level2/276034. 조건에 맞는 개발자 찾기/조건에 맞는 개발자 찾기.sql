# Python이나 C# 스킬을 가진 개발자의 ID, 이메일, 이름, 성을 조회
# 결과는 ID를 기준으로 오름차순 정렬
SELECT
    D.ID,
    D.EMAIL,
    D.FIRST_NAME,
    D.LAST_NAME
FROM DEVELOPERS AS D
    JOIN (
        SELECT SUM(CODE) AS CODE
        FROM SKILLCODES
        WHERE NAME IN ('Python', 'C#')
    ) AS SC
    ON (SC.CODE & D.SKILL_CODE) != 0
ORDER BY D.ID ASC;
