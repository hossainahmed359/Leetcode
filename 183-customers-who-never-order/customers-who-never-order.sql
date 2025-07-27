# Write your MySQL query statement below

WITH 
    tmp 
AS (
    SELECT 
        c.id, 
        c.name,
        o.id AS 'order_id'
    FROM
        Customers AS c
    LEFT JOIN
        Orders AS o ON c.id = o.customerId
)

SELECT 
    name AS Customers
FROM 
    tmp
WHERE
    order_id IS NULL;

