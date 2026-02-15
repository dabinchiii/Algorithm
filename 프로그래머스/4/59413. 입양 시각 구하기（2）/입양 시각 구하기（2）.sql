# 0시부터 23시까지, 각 시간대별로 입양이 몇 건이나 발생했는지 조회
# 결과는 시간대 순으로 정렬
SET @HOUR := -1;

SELECT
    (@HOUR := @HOUR + 1) AS HOUR,
    (
        SELECT COUNT(*)
        FROM ANIMAL_OUTS
        WHERE HOUR(DATETIME) = @HOUR
    ) AS COUNT
FROM ANIMAL_OUTS
WHERE @HOUR < 23;
