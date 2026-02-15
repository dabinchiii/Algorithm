# 리뷰를 가장 많이 작성한 회원의 리뷰들을 조회
# 회원 이름, 리뷰 텍스트, 리뷰 작성일을 출력
# 결과는 리뷰 작성일을 기준으로 오름차순,
# 리뷰 작성일이 같다면 리뷰 텍스트를 기준으로 오름차순 정렬
SELECT
    PF.MEMBER_NAME,
    REVIEW.REVIEW_TEXT,
    DATE_FORMAT(REVIEW.REVIEW_DATE, '%Y-%m-%d') AS REVIEW_DATE
FROM REST_REVIEW REVIEW
JOIN (
    SELECT
        MEMBER_ID,
        RANK() OVER (
            ORDER BY COUNT(*) DESC
        ) AS R
    FROM REST_REVIEW
    GROUP BY MEMBER_ID
) RK ON REVIEW.MEMBER_ID = RK.MEMBER_ID
JOIN MEMBER_PROFILE PF
    ON REVIEW.MEMBER_ID = PF.MEMBER_ID
WHERE R = 1
ORDER BY REVIEW_DATE ASC, REVIEW_TEXT ASC;
