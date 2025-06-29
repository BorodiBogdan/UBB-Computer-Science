USE HW3
GO

-- First verify the data exists
SELECT * FROM Courses WHERE CourseID = 1;
SELECT * FROM Students WHERE StudentID = 1;

-- Run simultaneously in Window 1:
BEGIN TRANSACTION
    PRINT 'Transaction 1: Starting update on Courses'
    UPDATE Courses SET CourseName = 'test' WHERE CourseID = 1
    PRINT 'Transaction 1: Updated Courses, waiting...'
    WAITFOR DELAY '00:00:10'
    PRINT 'Transaction 1: Attempting to update Students'
    UPDATE Students SET StudentName = 'Andreei' WHERE StudentID = 1
    PRINT 'Transaction 1: Completed both updates'
COMMIT TRANSACTION

-- Run simultaneously in Window 2:
BEGIN TRANSACTION
    PRINT 'Transaction 2: Starting update on Students'
    UPDATE Students SET StudentName = 'test' WHERE StudentID = 1
    PRINT 'Transaction 2: Updated Students, waiting...'
    WAITFOR DELAY '00:00:10'
    PRINT 'Transaction 2: Attempting to update Courses'
    UPDATE Courses SET CourseName = 'test' WHERE CourseID = 1
    PRINT 'Transaction 2: Completed both updates'
COMMIT TRANSACTION

-- Solution (run in both windows after test):
BEGIN TRANSACTION
    UPDATE Courses SET CourseName = CourseName WHERE CourseID = 1
    UPDATE Students SET StudentName = StudentName WHERE StudentID = 1
COMMIT TRANSACTION