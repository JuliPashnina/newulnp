-- Create table
create table CM_NASPUNKT
(
  CM_OKATO   NUMBER(12) not null,
  STATE      CHAR(6) not null,
  CM_CTEXT   VARCHAR2(254) not null,
  CM_SOCR    VARCHAR2(10) not null,
  CM_NTERR   NUMBER(11),
  CM_POSELEN VARCHAR2(10)
)
tablespace CCBPRODREPTS_01
  pctfree 10
  initrans 1
  maxtrans 255
  storage
  (
    initial 256K
    next 256K
    minextents 1
    maxextents unlimited
    pctincrease 0
  );
-- Create/Recreate primary, unique and foreign key constraints 
alter table CM_NASPUNKT
  add primary key (CM_OKATO)
  using index 
  tablespace CCBPRODREPTS_01
  pctfree 10
  initrans 2
  maxtrans 255
  storage
  (
    initial 256K
    next 256K
    minextents 1
    maxextents unlimited
    pctincrease 0
  );
-- Create/Recreate indexes 
create index CM_NASPUNKT_CM_CTEXT on CM_NASPUNKT (CM_CTEXT)
  tablespace CCBPRODREPTS_01
  pctfree 10
  initrans 2
  maxtrans 255
  storage
  (
    initial 256K
    next 256K
    minextents 1
    maxextents unlimited
    pctincrease 0
  );
