# 3세대의 대장균의 ID(ID) 를 출력
# 결과는 대장균의 ID 에 대해 오름차순 정렬
SELECT ID
FROM ECOLI_DATA
WHERE PARENT_ID IN ( # 2세대 대장균의 ID
    SELECT ID
    FROM ECOLI_DATA
    WHERE PARENT_ID IN ( # 1세대 대장균의 ID
        SELECT ID
        FROM ECOLI_DATA
        WHERE PARENT_ID IS NULL
    )
)
ORDER BY ID ASC;