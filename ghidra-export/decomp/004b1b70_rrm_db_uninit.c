// func rrm_db_uninit @ 004b1b70 size=60

undefined4 rrm_db_uninit(void)

{
  if (rrm_mutex != 0) {
    FUN_00408360();
    rrm_mutex = 0;
  }
  return 0;
}

