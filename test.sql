 update prof set city='kolkata' where empid=1;

 update prof set city='mumbai' where empid=5;

 update prof set city='delhi' where empid=10;

 update prof set city='delhi' where empid=8;

 update prof set city='delhi' where empid=4;

 update prof set city='hyderabad' where empid=7;

 update prof set city='hyderabad' where empid=2;

 update prof set city='mumbai' where empid=6;
 update prof set city='delhi' where empid=9;

 update prof set city='chennai' where empid=3;


 select * from prof;

 update prof set city=null where empid=3;

 update prof set city=null where empid=8;

 delete from prof where empid=10;

 insert into prof values(11,'abhinav',35,'male','delhi');

 select * from prof;

 delete from prof where empid=11;


 select * from prof;

 select count(empid),city from prof group by city;

 select * from prof order by age;

 select * from softdept union select * from harddept order by salary

  select * from softdept order by salary;              

 select * from harddept order by salary;

 select * from softdept union select * from harddept;

 select * from softdept union select * from harddept order by salary;

 select * from softdept union select * from harddept order by salary

 select count(empid),city from prof group by city having count(empid)>1;                                

 select * from prof where age between 22 and 28;

 select * from prof where age between 20 and 28;


 select * from prof where city is null;

 select count(city) from prof where city is not null;
                                                                    

 select * from prof where name like 'a%';           

 select * from prof where city in ('mumbai','kolkata');       



select * from prof where exists(select * from softdept where softdept.empid=prof.empid and salary>=23000);   

select distinct city from prof;
