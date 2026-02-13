# 2022년 1월의 카테고리 별 도서 판매량을 합산하고,
# 카테고리(CATEGORY), 총 판매량(TOTAL_SALES) 리스트를 출력
# 결과는 카테고리명을 기준으로 오름차순 정렬
SELECT
    CATEGORY,
    SUM(TOTAL_SALES) AS TOTAL_SALES
FROM (
    BOOK JOIN (
        SELECT
            BOOK_ID,
            SUM(SALES) AS TOTAL_SALES
        FROM BOOK_SALES
        WHERE SALES_DATE >= '2022-01-01'
            AND SALES_DATE < '2022-02-01'
        GROUP BY BOOK_ID
    ) AS S ON BOOK.BOOK_ID = S.BOOK_ID
)
GROUP BY CATEGORY
ORDER BY CATEGORY ASC;