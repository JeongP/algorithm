-- 코드를 입력하세요
SELECT CART_ID, if(sum(price)<50000, sum(price)+3000,sum(price)) from cart_products group by cart_id