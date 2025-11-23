-- SELECT E.student_id, E.subject_name, COUNT(E.subject_name) AS attended_exams 
-- FROM Examinations AS E
-- JOIN Subjects AS S
-- ON E.subject_name = S.subject_name
-- GROUP BY E.student_id, E.subject_name
-- ORDER BY E.student_id, E.subject_name;


SELECT 
    t1.student_id, t1.student_name, t1.subject_name, COUNT(t2.subject_name) AS attended_exams
FROM (
    SELECT St.student_id , St.student_name, Sb.subject_name
    FROM Students AS St
    CROSS JOIN
    Subjects AS Sb
    ORDER BY St.student_id, Sb.subject_name
) AS t1
LEFT JOIN 
    Examinations AS t2
ON 
    t1.student_id = t2.student_id AND t1.subject_name = t2.subject_name
GROUP BY 
    t1.student_id, t1.subject_name
ORDER BY 
    t1.student_id, t1.subject_name;

