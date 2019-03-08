# dbEngine

This is a database engine that parses, optimizes, and excutes SQL commands. It supports select, where, join(inner, left, right, natural), functions(AVG, SUM, COUNT, MAX, MIN), group by, expressions, alias, subquery and Distinct. The following queries are tested. Also implemented push down conjunctive predicates optimization

	1. Simple SELECT query
SELECT SID, Score.CID, Score.Score<br/>
  FROM Score;

SELECT Course.* <br/>
  FROM Course;

SELECT * <br/>
  FROM Stud;

	2. Where clause
SELECT SID, Fname, Lname, Age <br/>
  FROM Stud <br/>
  WHERE SID > 1003 AND SID < 1009 AND Age > 17 OR Fname = 'Rony';

	3. Join
SELECT SID, Fname, Lname, Age, CID, Score<br/>
  FROM Stud<br/>
  LEFT JOIN Score<br/>
  ON Score.SID = Stud.SID;

SELECT SID, Fname, Lname, Age, CID, Score<br/>
  FROM Stud<br/>
  RIGHT JOIN Score<br/>
  ON Score.SID = Stud.SID;

SELECT *<br/>
  FROM Stud<br/>
  NATURAL JOIN Course;

SELECT * <br/>
  FROM Stud<br/>
  NATURAL JOIN Score;

SELECT SID, Fname, Lname, Age, CID, Score<br/>
  FROM Stud<br/>
  INNER JOIN Score <br/>
  ON Score.SID = Stud.SID<br/>
  WHERE SID > 1003 AND SID < 1009 AND Score > 80;

SELECT SID, Fname, Lname, Age, CID, Score<br/>
  FROM <br/>
	  (SELECT * <br/>
	   FROM Stud<br/>
	   WHERE SID > 1003 AND SID < 1009;)<br/>
  INNER JOIN<br/>
	  (SELECT * <br/>
	   FROM Score<br/>
	   WHERE Score > 80;)<br/>
  ON Score.SID = Stud.SID;

SELECT * <br/>
  FROM Stud<br/>
  INNER JOIN Score<br/>
  ON Stud.SID = Score.SID<br/>
  INNER JOIN Course<br/>
  ON Score.CID = Course.CID;
 
	4. Functions and Groupby
SELECT Fname + ' ' + Lname, MIN(Score)<br/>
  FROM Stud<br/>
  INNER JOIN Score <br/>
  ON Score.SID = Stud.SID<br/>
  GROUP BY Fname + ' ' + Lname;

SELECT Fname + ' ' + Lname, MAX(Score)<br/>
  FROM Stud<br/>
  INNER JOIN Score <br/>
  ON Score.SID = Stud.SID<br/>
  GROUP BY Fname + ' ' + Lname;

SELECT Fname + ' ' + Lname, SUM(Score)<br/>
  FROM Stud<br/>
  INNER JOIN Score <br/>
  ON Score.SID = Stud.SID<br/>
  GROUP BY Fname + ' ' + Lname;

SELECT Fname + ' ' + Lname, COUNT(Score)<br/>
  FROM Stud<br/>
  INNER JOIN Score <br/>
  ON Score.SID = Stud.SID<br/>
  GROUP BY Fname + ' ' + Lname;

SELECT Fname + ' ' + Lname, AVG(Score)<br/>
  FROM Stud<br/>
  INNER JOIN Score <br/>
  ON Score.SID = Stud.SID<br/>
  WHERE SID > 1003 AND SID < 1009 AND Score > 80<br/>
  GROUP BY Fname + ' ' + Lname;

	5. Expressions
SELECT Fname + ' ' + Lname, AVG(Score) * 2 + 100, AVG(Score) * 2<br/>
  FROM Stud<br/>
  INNER JOIN Score <br/>
  ON Score.SID = Stud.SID<br/>
  WHERE SID > 1003 AND SID < 1009 AND Score * 2 + SID > SID + 160<br/>
  GROUP BY Fname + ' ' + Lname;

	6. Alias and subquery
SELECT st.SID AS ID, res.Fname + ' ' + res.Lname AS name, AVG(sc.Score) * 2 AS score<br/>
  FROM Stud AS st<br/>
  INNER JOIN Score AS sc <br/>
  ON sc.SID = st.SID AS res<br/>
  WHERE ID > 1003 AND ID < 1009 OR name = 'David Wei'<br/>
  GROUP BY ID, name;

SELECT res.SID, res.score<br/>
  FROM<br/>
	  (SELECT st.SID AS ID, st.Fname + ' ' + st.Lname AS name, AVG(sc.Score) * 2 AS score<br/>
	   FROM Stud AS st<br/>
	   INNER JOIN Score AS sc <br/>
	   ON sc.SID = st.SID<br/>
	   WHERE ID > 1003 AND ID < 1009 OR name = 'David Wei'<br/>
	   GROUP BY ID, name;) AS res <br/>
  WHERE res.score > 85;


	7. DISTINCT
SELECT DISTINCT Stud.Age<br/>
  FROM Stud;

SELECT DISTINCT st.SID, st.Fname , st.Age<br/>
  FROM Stud AS st;

SELECT COUNT (DISTINCT Stud.Age)<br/>
  FROM Stud;

SELECT AVG (DISTINCT Stud.Age)<br/>
  FROM Stud;

SELECT SUM (DISTINCT Stud.Age)<br/>
  FROM Stud;

SELECT MIN (DISTINCT Stud.Age)<br/>
  FROM Stud;

SELECT MAX (DISTINCT Stud.Age)<br/>
  FROM Stud;
