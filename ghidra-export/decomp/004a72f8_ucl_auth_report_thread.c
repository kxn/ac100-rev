// func ucl_auth_report_thread @ 004a72f8 size=500

void ucl_auth_report_thread(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_t9;
  code *pcVar5;
  
  iVar4 = 0;
  iVar3 = 0;
  do {
    iVar1 = ucl_auth_db_get_notify_swtich_report();
    if ((iVar1 == 2) && (iVar1 = ucl_auth_report_switch_enable_status(), iVar1 == 0)) {
      ucl_auth_db_set_notify_switch_report(3);
    }
    iVar1 = ucl_auth_db_get_notify_first_report();
    if (iVar1 == 2) {
      ucl_auth_add_first_report_from_wportal();
      ucl_auth_db_set_first_report_finish(0);
    }
    else {
      iVar1 = ucl_auth_db_get_notify_first_report();
      if (iVar1 == 3) {
        iVar4 = 0;
        ucl_auth_db_set_first_report_finish(1);
        ucl_auth_db_clear_first_report_station();
      }
    }
    iVar1 = ucl_auth_db_get_first_report_finish();
    if (iVar1 == 0) {
      if (iVar4 == 0) {
        iVar1 = ucl_auth_report_first_report_station();
        if (iVar1 == 0) {
          ucl_auth_db_set_notify_first_report(3);
          uVar2 = 1;
          pcVar5 = *(code **)(in_t9 + 0x2b2050);
        }
        else {
          iVar4 = 3;
          iVar1 = ucl_auth_db_get_notify_first_report();
          if (iVar1 != 2) goto LAB_004a7368;
          uVar2 = 4;
          pcVar5 = *(code **)(in_t9 + 0x2b1fd4);
        }
        (*pcVar5)(uVar2);
      }
      else {
        iVar4 = iVar4 + -1;
      }
    }
LAB_004a7368:
    iVar1 = ucl_auth_db_is_station_report_switch_enable();
    if ((iVar1 == 1) && (iVar1 = ucl_auth_db_get_first_report_finish(), iVar1 == 1)) {
      if (iVar3 == 0) {
        iVar3 = 3;
        iVar1 = ucl_auth_report_offline_station();
        if (iVar1 != -1) {
          iVar3 = 0;
        }
      }
      else {
        iVar3 = iVar3 + -1;
      }
    }
    else {
      iVar1 = ucl_auth_db_is_station_report_switch_enable();
      if (iVar1 == 0) {
        iVar3 = 0;
        ucl_auth_db_clear_offline_station();
      }
    }
    (**(code **)(in_t9 + 0x2b2334))(1);
  } while( true );
}

