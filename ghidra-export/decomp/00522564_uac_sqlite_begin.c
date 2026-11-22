// func uac_sqlite_begin @ 00522564 size=36

void uac_sqlite_begin(undefined4 param_1)

{
  uac_sqlite_exec(param_1,"BEGIN;",0,0);
  return;
}

