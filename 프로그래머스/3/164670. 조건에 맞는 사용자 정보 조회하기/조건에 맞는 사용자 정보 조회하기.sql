# 중고 거래 게시물을 3건 이상 등록한 사용자의 사용자 ID, 닉네임, 전체주소, 전화번호를 조회
# 전체 주소는 시, 도로명 주소, 상세 주소가 함께 출력
# 전화번호의 경우 xxx-xxxx-xxxx 같은 형태로 하이픈 문자열(-)을 삽입하여 출력
# 결과는 회원 ID를 기준으로 내림차순 정렬
WITH TG AS (
    SELECT WRITER_ID
    FROM USED_GOODS_BOARD
    GROUP BY WRITER_ID
    HAVING COUNT(*) >= 3
),

USER_INFO AS (
    SELECT
        USER_ID,
        NICKNAME,
        CONCAT(
            CITY, ' ',
            STREET_ADDRESS1, ' ',
            STREET_ADDRESS2
        ) AS FULL_ADDRESS,
        CONCAT(
            SUBSTR(TLNO, 1, 3), '-',
            SUBSTR(TLNO, 4, 4), '-',
            SUBSTR(TLNO, 8)
        ) AS FORMATTED_TLNO
    FROM USED_GOODS_USER
)

SELECT
    U.USER_ID,
    U.NICKNAME,
    U.FULL_ADDRESS AS '전체주소',
    U.FORMATTED_TLNO AS '전화번호'
FROM TG AS TG
JOIN USER_INFO AS U
    ON TG.WRITER_ID = U.USER_ID
ORDER BY USER_ID DESC;
