# 물고기의 종류 별 물고기의 이름과 잡은 수를 출력
# 물고기의 이름 컬럼명은 FISH_NAME, 잡은 수 컬럼명은 FISH_COUNT
# 결과는 잡은 수 기준으로 내림차순 정렬
SELECT
    COUNT(*) AS FISH_COUNT,
    N.FISH_NAME
FROM FISH_INFO I
JOIN FISH_NAME_INFO N
    ON I.FISH_TYPE = N.FISH_TYPE
GROUP BY N.FISH_NAME
ORDER BY FISH_COUNT DESC;