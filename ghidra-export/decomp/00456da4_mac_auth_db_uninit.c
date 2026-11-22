// func mac_auth_db_uninit @ 00456da4 size=328

undefined4 mac_auth_db_uninit(void)

{
  if (DAT_00766ff4 != 0) {
    FUN_00408360();
    DAT_00766ff4 = 0;
  }
  if (DAT_00766ff8 != 0) {
    FUN_00408360();
    DAT_00766ff8 = 0;
  }
  if (DAT_00766ffc != 0) {
    FUN_00408160();
    DAT_00766ffc = 0;
  }
  if (DAT_00767000 != 0) {
    FUN_00408160();
    DAT_00767000 = 0;
  }
  if (DAT_00767004 != 0) {
    FUN_00408160();
    DAT_00767004 = 0;
  }
  if (DAT_00767020 != 0) {
    FUN_00407df0();
    DAT_00767020 = 0;
  }
  if (DAT_00767024 != 0) {
    FUN_00407df0();
    DAT_00767024 = 0;
  }
  if (DAT_00767008 != 0) {
    FUN_00408310();
    DAT_00767008 = 0;
  }
  if (DAT_00767018 != 0) {
    FUN_00407df0();
    DAT_00767018 = 0;
  }
  if (DAT_0076701c != 0) {
    FUN_00407df0();
    DAT_0076701c = 0;
  }
  g_mac_auth_data = 0;
  return 0;
}

