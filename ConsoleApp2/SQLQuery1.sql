CREATE TABLE [dbo].[Books]
(
	[Id] INT NOT NULL PRIMARY KEY identity(1,1),
	Title NVARCHAR(60) not null,
	AuthorName NVARCHAR(100) not null,
	Price decimal default 500.0,
	Count int default 0,
	check (Count >=0)
)