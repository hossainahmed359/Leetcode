-- WITH start_activity 
-- AS (
--     SELECT a.machine_id, a.process_id, a.activity_type, a.timestamp AS start_timestamp
--     FROM Activity AS a
--     WHERE activity_type = 'start'
-- ),
-- end_activity 
-- AS (
--     SELECT a.machine_id, a.process_id, a.activity_type, a.timestamp AS end_timestamp
--     FROM Activity AS a
--     WHERE activity_type = 'end'
-- )

-- SELECT t1.machine_id,  ROUND(AVG(t2.end_timestamp - t1.start_timestamp), 3) AS processing_time 
-- FROM start_activity AS t1
-- JOIN end_activity AS t2
-- ON t1.machine_id = t2.machine_id AND  t1.process_id  = t2.process_id
-- GROUP BY t1.machine_id;


SELECT t1.machine_id, ROUND(AVG(t2.timestamp - t1.timestamp), 3) AS processing_time
FROM Activity AS t1
JOIN Activity AS t2
ON 
    t1.machine_id = t2.machine_id AND 
    t1.process_id = t2.process_id AND 
    t1.activity_type = "start" AND 
    t2.activity_type = "end"
GROUP BY t1.machine_id;


