// func _sensor_test_build_bssid_cb @ 004f47a8 size=664

undefined4 _sensor_test_build_bssid_cb(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int local_38;
  int local_34;
  undefined4 local_30;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_build_bssid_cb ENTER\n",
           "_sensor_test_build_bssid_cb",0x6ac);
  }
  local_34 = 0;
  local_38 = 0;
  if (((param_2 == (undefined4 *)0x0) || (param_2[2] == 0)) || (param_2[1] == 0)) {
    uVar5 = 2;
    if (sensor_test_err_switch == '\0') {
      return 2;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d input error\n";
    uVar7 = 0x6bd;
  }
  else {
    if (*(int *)(param_1 + 0x2ac) != 2) {
      return 0;
    }
    iVar6 = 0;
    iVar1 = rdmngr_db_get_radio_cnt_by_ap_id(*(undefined2 *)(param_1 + 0x10),&local_34,&local_38);
    if (iVar1 != -1) {
      while (iVar6 < (int)param_2[1]) {
        uVar7 = param_2[3];
        puVar8 = (undefined4 *)(param_2[2] + iVar6 * 0x14);
        local_30 = *param_2;
        uVar4 = puVar8[1];
        uVar5 = *puVar8;
        if (((uVar4 & 1) != 0) && (iVar1 = 1, 0 < local_34)) {
          while (iVar1 <= local_34) {
            iVar2 = rdmngr_db_get_freq_band_rd_id(*(undefined2 *)(param_1 + 0x10),0,iVar1);
            if ((iVar2 == -1) || (iVar3 = wserv_db_is_wserv_bind_to_rd(iVar2,uVar5), iVar3 != 1)) {
              iVar1 = iVar1 + 1;
            }
            else {
              iVar1 = iVar1 + 1;
              _sensor_test_build_bssid_add_to_hash_and_list
                        (*(undefined2 *)(param_1 + 0x10),iVar2,uVar5,uVar4,local_30,uVar7,puVar8 + 2
                        );
            }
          }
        }
        if ((uVar4 & 0x10) == 0) {
          iVar6 = iVar6 + 1;
        }
        else {
          iVar1 = 1;
          if (local_38 < 1) {
            iVar6 = iVar6 + 1;
          }
          else {
            while (iVar1 <= local_38) {
              iVar2 = rdmngr_db_get_freq_band_rd_id(*(undefined2 *)(param_1 + 0x10),1,iVar1);
              if ((iVar2 == -1) || (iVar3 = wserv_db_is_wserv_bind_to_rd(iVar2,uVar5), iVar3 != 1))
              {
                iVar1 = iVar1 + 1;
              }
              else {
                iVar1 = iVar1 + 1;
                _sensor_test_build_bssid_add_to_hash_and_list
                          (*(undefined2 *)(param_1 + 0x10),iVar2,uVar5,uVar4,local_30,uVar7,
                           puVar8 + 2);
              }
            }
            iVar6 = iVar6 + 1;
          }
        }
      }
      return 0;
    }
    uVar5 = 1;
    if (sensor_test_err_switch == '\0') {
      return 1;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d rdmngr_db_get_radio_cnt_by_ap_id fail\n";
    uVar7 = 0x6c8;
  }
  printf(__format,"_sensor_test_build_bssid_cb",uVar7);
  return uVar5;
}

