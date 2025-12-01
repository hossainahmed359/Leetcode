WITH m 
AS (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(managerId) >= 5
)

SELECT e.name
FROM Employee AS e
JOIN m
ON e.id = m.managerId;
