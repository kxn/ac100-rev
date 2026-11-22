// func uac_sqlite_commit @ 00522540 size=36

void uac_sqlite_commit(undefined4 param_1)

{
  uac_sqlite_exec(param_1,"COMMIT;",0,0);
  return;
}

