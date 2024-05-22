create table todo_group (
                            id varchar primary key,
                            name varchar(255) not null,
                            times integer,
                            category varchar,
                            create_time timestamp,
                            finish_time timestamp
);

create table todo_item(
    id varchar primary key,
    belong_id varchar,
    title varchar,
    description varchar,
    is_finish integer,
    weight smallint
);


insert into todo_group(id, name, times, category, create_time, finish_time) values ('1', 'test1', 1, 'once', '2021-01-01 00:00:00', '2021-01-01 00:00:00');
insert into todo_group(id, name, times, category, create_time, finish_time) values ('2', 'test2', 1, 'cycle', '2021-01-01 00:00:00', '2021-01-01 00:00:00');
insert into todo_group(id, name, times, category, create_time, finish_time) values ('3', 'test3', 1, 'daily', '2021-01-01 00:00:00', '2021-01-01 00:00:00');
insert into todo_group(id, name, times, category, create_time, finish_time) values ('4', 'test4', 1, 'property', '2021-01-01 00:00:00', '2021-01-01 00:00:00');
-- 查询todo_group存在多少条数据
select count(todo_group.id) from todo_group;

-- 查询todo_group中所有的数据
select * from todo_group;

select todo_group.id, todo_group.name, todo_group.finish_time, todo_group.category from todo_group;

-- 查询todo_item中存在多少条数据
select count(todo_item.id) from todo_item;


--通过id删除todo_group中的数据
delete from todo_group where id = '1';