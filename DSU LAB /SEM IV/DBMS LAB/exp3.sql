-- Create two table one is country table which will contain country id, country name
-- Other table is the state table which will contain the state id, country id can be repeated, state name 


create table country(
country_id int primary key,
country_name varchar(20)
);

create table state(
state_id int,
country_id int,
state_name varchar(20)
);


insert into country values
(1,'India'),
(2,'Srilanks'),
(3,'Nepal'),
(4,'Pakisthan'),
(5,'Usa');

insert into state values
(1,1,'Karnataka'),
(2,1,'Assam'),
(3,1,'Delhi'),
(4,2,'Columbo'),
(5,2,'Kandy'),
(6,3,'Kathmandu'),
(7,5,'Newyork');

select * from country
select * from state

-- INNER JOIN , it will display the common record according to id 
-- a) Apply inner join on both the table and display country_id,country_name, state_name
select country.country_id,country_name, state_name
from country
inner join state
on country.country_id = state.country_id

-- It shows only those countries that have matching states
-- Countries without states are excluded


-- LEFT JOIN 
-- b) Apply left join on both the table and display country_id,country_name, state_name
select country.country_id,country_name,state_name
from country
left join state
on country.country_id = state.country_id

-- RIGHT JOIN
-- c) Apply right join on both the table and display country_id,country_name, state_name
select country.country_id,country_name,state_name
from country
right join state
on country.country_id = state.country_id

-- Full join 
-- d) Apply full join on both the table and display country_id,country_name, state_name
select country.country_id,country_name,state_name
from country
left join state
on country.country_id = state.country_id

union

select country.country_id,country_name,state_name
from country
right join state
on country.country_id = state.country_id
