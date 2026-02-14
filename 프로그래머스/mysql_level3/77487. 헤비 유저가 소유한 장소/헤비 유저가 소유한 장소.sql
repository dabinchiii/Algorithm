# 헤비 유저가 등록한 공간의 정보를 아이디 순으로 조회
# 헤비 유저: 공간을 둘 이상 등록한 사람
SELECT
    P.ID,
    P.NAME,
    P.HOST_ID
FROM PLACES P
JOIN (
    SELECT HOST_ID AS ID
    FROM PLACES
    GROUP BY HOST_ID
    HAVING COUNT(*) >= 2
) HEAVY_USER ON P.HOST_ID = HEAVY_USER.ID
ORDER BY P.ID;