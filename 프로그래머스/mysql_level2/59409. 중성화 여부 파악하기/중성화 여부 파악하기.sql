# 동물의 아이디와 이름, 중성화 여부를 아이디 순으로 조회
# 중성화가 되어있다면 'O', 아니라면 'X'라고 표시
# 중성화된 동물은 SEX_UPON_INTAKE 컬럼에 'Neutered' 또는 'Spayed'라는 단어가 들어있습니다.
SELECT
    ANIMAL_ID,
    NAME,
    IF(
        INSTR(SEX_UPON_INTAKE, 'Neutered') != 0
        OR  INSTR(SEX_UPON_INTAKE, 'Spayed') != 0,
        'O',
        'X'
    ) AS '중성화'
FROM ANIMAL_INS
ORDER BY ANIMAL_ID;