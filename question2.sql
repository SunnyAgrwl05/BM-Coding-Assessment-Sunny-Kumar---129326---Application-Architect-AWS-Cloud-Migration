SELECT
    c.email,
    ROUND(AVG(s.cpu_usage), 2) AS average_cpu_usage,
    ROUND(AVG(s.memory_usage), 2) AS average_memory_usage,
    ROUND(AVG(s.disk_usage), 2) AS average_disk_usage
FROM customers c
JOIN site_metrics s
    ON c.id = s.customer_id
GROUP BY c.id, c.email
HAVING
    AVG(s.cpu_usage) > 50
    OR AVG(s.memory_usage) > 50
    OR AVG(s.disk_usage) > 50
ORDER BY c.email ASC;
