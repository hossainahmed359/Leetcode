# Write your MySQL query statement below
SELECT 
    name AS 'Employee'
FROM 
    Employee AS e
WHERE
    salary > (
        SELECT 
            salary
        FROM 
            Employee AS m
        WHERE 
            e.managerId = m.id
    );