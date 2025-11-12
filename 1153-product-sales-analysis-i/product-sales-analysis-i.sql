SELECT p.product_name, s.year, s.price 
FROM Product AS p
LEFT JOIN  Sales AS s
ON p.product_id = s.product_id
WHERE s.year IS NOT NULL;
