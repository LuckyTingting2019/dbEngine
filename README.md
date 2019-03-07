# dbEngine

This is a database engine that parses and excutes SQL commands. It supports select, where, join(inner, left, right, natural),
functions(AVG, SUM, COUNT, MAX, MIN), group by, expressions, alias, subquery and Distinct. The following queries are tested.

	1. Simple SELECT query
SELECT *
  FROM Stud;

SELECT *
  FROM Score;

SELECT Course.*
  FROM Course;

SELECT SID, Stud.Fname, Stud.Lname, Age
  FROM Stud;

	2. Where clause
SELECT CID, CName
  FROM Course
  WHERE CName = 'C++' OR CName = 'Java';

SELECT SID, Fname, Lname, Age
  FROM Stud
  WHERE SID > 1004 AND SID < 1009 OR Fname = 'Rony' AND Age > 17;

	3. Join
SELECT SID, Fname, Lname, Age, CID, Score
  FROM Stud LEFT JOIN Score 
  ON Score.SID = Stud.SID;

SELECT SID, Fname, Lname, Age, CID, Score
  FROM Stud RIGHT JOIN Score
  ON Score.SID = Stud.SID;

SELECT * 
  FROM Stud NATURAL JOIN Score;

SELECT *
  FROM Stud NATURAL JOIN Course;

SELECT SID, Fname, Lname, Age, CID, Score
  FROM Stud INNER JOIN Score 
  ON Score.SID = Stud.SID;

SELECT SID, Fname, Lname, Age, CID, Score
  FROM Stud INNER JOIN Score 
  ON Score.SID = Stud.SID
  WHERE Score > 80 AND Age < 19 OR Lname = 'Zhao';

	4. Functions and Groupby
SELECT SID, AVG(Score)
  FROM Stud INNER JOIN Score 
  ON Score.SID = Stud.SID
  WHERE Score > 80 AND Age < 19 OR Lname = 'Zhao'
  GROUP BY SID;

SELECT Fname + ' ' + Lname, SUM(Score)
  FROM Stud INNER JOIN Score 
  ON Score.SID = Stud.SID
  GROUP BY Fname + ' ' + Lname;

SELECT Fname + ' ' + Lname, MIN(Score)
  FROM Stud INNER JOIN Score 
  ON Score.SID = Stud.SID
  GROUP BY Fname + ' ' + Lname;

SELECT Fname + ' ' + Lname, MAX(Score)
  FROM Stud INNER JOIN Score 
  ON Score.SID = Stud.SID
  GROUP BY Fname + ' ' + Lname;

SELECT Fname + ' ' + Lname, COUNT(Score)
  FROM Stud INNER JOIN Score 
  ON Score.SID = Stud.SID
  GROUP BY Fname + ' ' + Lname;

	5. Expressions	
SELECT Fname + ' ' + Lname, AVG(Score) * 2 + 100, AVG(Score) * 2
  FROM Stud INNER JOIN Score 
  ON Score.SID = Stud.SID
  WHERE Score * 2 + SID > SID + 160 AND Age < 19 OR Lname = 'Zhao'
  GROUP BY Fname + ' ' + Lname;

	6. Alias and subquery
SELECT st.SID AS ID, st.Fname + ' ' + st.Lname AS name, AVG(sc.Score) * 2 AS score
  FROM Stud AS st INNER JOIN Score AS sc 
  ON sc.SID = st.SID
  WHERE ID > 1003 AND ID < 1009 OR name = 'David Wei'
  GROUP BY ID, name;

SELECT res.SID AS ID, res.Fname + ' ' + res.Lname AS name, SUM(res.Score) AS score
  FROM Stud AS st INNER JOIN Score AS sc
  ON sc.SID = st.SID AS res
  WHERE ID > 1003 AND ID < 1009 OR name = 'David Wei'
  GROUP BY ID, name;

SELECT res.SID, res.score
  FROM
	  (SELECT st.SID AS ID, st.Fname + ' ' + st.Lname AS name, AVG(sc.Score) * 2 AS score
	  FROM Stud AS st INNER JOIN Score AS sc 
	  ON sc.SID = st.SID
	  WHERE ID > 1003 AND ID < 1009 OR name = 'David Wei'
	  GROUP BY ID, name;) AS res 
  WHERE res.score > 85;


	7. DISTINCT
SELECT DISTINCT Stud.Age
  FROM Stud;

SELECT DISTINCT st.SID, st.Fname , st.Age
  FROM Stud AS st;

SELECT COUNT (DISTINCT Stud.Age)
  FROM Stud;

SELECT AVG (DISTINCT Stud.Age)
  FROM Stud;

SELECT SUM (DISTINCT Stud.Age)
  FROM Stud;

SELECT MIN (DISTINCT Stud.Age)
  FROM Stud;

SELECT MAX (DISTINCT Stud.Age)
  FROM Stud;
