create table todo_group (
                            id varchar primary key,
                            name varchar(255) not null,
                            times integer,
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

insert into todo_group(id, name, times, create_time, finish_time) values ('1', 'test', 1, '2021-01-01 00:00:00', '2021-01-01 00:00:00');

-- 查询todo_group存在多少条数据
select count(todo_group.id) from todo_group;

-- 查询todo_group中所有的数据
select * from todo_group;

-- 查询todo_item中存在多少条数据
select count(todo_item.id) from todo_item;