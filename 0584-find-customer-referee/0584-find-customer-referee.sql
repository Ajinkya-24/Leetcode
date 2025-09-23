# Write your MySQL query statement below
SELECT name
FROM Customer
Where COALESCE(referee_id,0) !=2