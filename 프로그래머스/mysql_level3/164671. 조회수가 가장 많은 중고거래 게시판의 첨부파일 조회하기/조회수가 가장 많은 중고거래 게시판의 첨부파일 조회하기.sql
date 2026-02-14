# 조회수가 가장 높은 중고거래 게시물에 대한 첨부파일 경로를 조회
# (조회수가 가장 높은 게시물은 하나만 존재)
# 첨부파일 경로는 FILE ID를 기준으로 내림차순 정렬
# 기본적인 파일경로는 /home/grep/src/ 이며,
# 게시글 ID를 기준으로 디렉토리가 구분되고,
# 파일이름은 파일 ID, 파일 이름, 파일 확장자로 구성되도록 출력
SELECT
    CONCAT(
        '/home/grep/src/',
        F.BOARD_ID, '/',
        F.FILE_ID,
        F.FILE_NAME,
        F.FILE_EXT
    ) AS FILE_PATH
FROM USED_GOODS_FILE F
JOIN (
    SELECT BOARD_ID
    FROM USED_GOODS_BOARD
    ORDER BY VIEWS DESC
    LIMIT 1
) TARGET ON F.BOARD_ID = TARGET.BOARD_ID
ORDER BY FILE_ID DESC;