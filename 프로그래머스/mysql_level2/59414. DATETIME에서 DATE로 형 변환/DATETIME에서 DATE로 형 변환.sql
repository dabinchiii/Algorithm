# 각 동물의 아이디와 이름, 들어온 날짜를 조회
# 들어온 날짜는 시각(시-분-초)을 제외한 날짜(년-월-일)만 보여주세요.
# 결과는 아이디 순으로 조회
SELECT
    ANIMAL_ID,
    NAME,
    DATE_FORMAT(DATETIME, '%Y-%m-%d') AS '날짜'
FROM ANIMAL_INS
ORDER BY ANIMAL_ID ASC;