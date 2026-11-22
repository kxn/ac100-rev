// func wsta_roam_db_uninit @ 00481948 size=268

undefined4 wsta_roam_db_uninit(void)

{
  FUN_00408060(DAT_00767554);
  if (DAT_0076754c != 0) {
    FUN_00408310();
    DAT_0076754c = 0;
  }
  if (DAT_00767548 != 0) {
    FUN_00407df0();
    DAT_00767548 = 0;
  }
  if (DAT_00767544 != 0) {
    FUN_00408160();
    DAT_00767544 = 0;
  }
  DAT_00767550 = 0;
  FUN_00408060(DAT_00767564);
  if (DAT_00767560 != 0) {
    FUN_00408310();
    DAT_00767560 = 0;
  }
  if (DAT_00767558 != 0) {
    FUN_00407df0();
    DAT_00767558 = 0;
  }
  if (DAT_0076755c != 0) {
    FUN_00407df0();
    DAT_0076755c = 0;
  }
  if (l_wsta_roam_data != 0) {
    FUN_00408360();
    l_wsta_roam_data = 0;
  }
  return 0;
}

