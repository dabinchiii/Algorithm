# 보호소에 들어올 당시에는 중성화되지 않았지만,
# 보호소를 나갈 당시에는 중성화된 동물의 아이디와 생물 종, 이름을 조회
# 결과는 아이디 순으로 조회
# 중성화를 거치지 않은 동물은 성별 및 중성화 여부에 Intact, 
# 중성화를 거친 동물은 Spayed 또는 Neutered라고 표시되어있습니다.
SELECT
    I.ANIMAL_ID,
    I.ANIMAL_TYPE,
    I.NAME
FROM ANIMAL_INS AS I
JOIN ANIMAL_OUTS AS O
    ON I.ANIMAL_ID = O.ANIMAL_ID
    AND I.SEX_UPON_INTAKE LIKE 'Intact%'
    AND (O.SEX_UPON_OUTCOME LIKE 'Spayed%'
         OR O.SEX_UPON_OUTCOME LIKE 'Neutered%')
ORDER BY I.ANIMAL_ID;

