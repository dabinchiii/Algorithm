# 물고기 종류 별로 가장 큰 물고기의 ID, 물고기 이름, 길이를 출력
# 물고기의 ID 컬럼명은 ID, 이름 컬럼명은 FISH_NAME, 길이 컬럼명은 LENGTH
# 결과는 물고기의 ID에 대해 오름차순 정렬
# 잡은 물고기의 길이가 10cm 이하일 경우에는 LENGTH 가 NULL
# 물고기 종류별 가장 큰 물고기는 1마리만 있으며 10cm 이하의 물고기가 가장 큰 경우는 없습니다.
SELECT
    I.ID,
    N.FISH_NAME,
    I.LENGTH
FROM (
    SELECT
        ID,
        FISH_TYPE,
        LENGTH,
        RANK() OVER (
            PARTITION BY FISH_TYPE
            ORDER BY LENGTH DESC
        ) AS R
    FROM FISH_INFO
) I JOIN FISH_NAME_INFO N
    ON I.FISH_TYPE = N.FISH_TYPE
WHERE R = 1
ORDER BY I.ID ASC;
