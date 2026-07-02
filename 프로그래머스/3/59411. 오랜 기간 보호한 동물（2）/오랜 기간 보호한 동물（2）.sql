# 입양을 간 동물 중, 보호 기간이 가장 길었던 동물 두 마리의 아이디와 이름을 조회
# 결과는 보호 기간이 긴 순으로 조회
SELECT
    I.ANIMAL_ID,
    I.NAME
FROM ANIMAL_OUTS AS O
LEFT JOIN ANIMAL_INS AS I
    ON O.ANIMAL_ID = I.ANIMAL_ID
ORDER BY (O.DATETIME - I.DATETIME) DESC
LIMIT 2;