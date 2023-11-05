-- 코드를 입력하세요
SELECT 
    PT_NAME
    ,PT_NO
    ,GEND_CD
    ,AGE
    ,IFNULL(TLNO, 'NONE') as TLNO
    FROM PATIENT
    WHERE GEND_CD='w' and AGE <= 12
    ORDER BY AGE desc, PT_NAME asc