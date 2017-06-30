-- Create table
create table CM_ULITSA
(
  CM_OKATO      NUMBER(12) not null,
  CM_NPOSELOK   NUMBER(5) default 0 not null,
  CM_CTEXT      VARCHAR2(254) not null,
  CM_SOCR       VARCHAR2(10) not null,
  CM_K_STREET   NUMBER(15),
  CM_NULITSAID  VARCHAR2(12) not null,
  CM_K_FIAS     CHAR(36),
  CM_CTEXT_FIAS VARCHAR2(254)
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
-- Add comments to the columns 
comment on column CM_ULITSA.CM_CTEXT_FIAS
  is 'Название улицы из справочника ФИАС';
-- Create/Recreate primary, unique and foreign key constraints 
alter table CM_ULITSA
  add primary key (CM_NULITSAID, CM_NPOSELOK, CM_OKATO)
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
create index CM_ULITSA on CM_ULITSA (CM_CTEXT)
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
create index CM_ULITSA_CM_OKATO on CM_ULITSA (CM_OKATO)
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