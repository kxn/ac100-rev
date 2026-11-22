// func _sensor_test_generate_serv_list_cb @ 004f5b80 size=1

undefined4 _sensor_test_generate_serv_list_cb(int param_1,int param_2)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uStack_238;
  int iStack_234;
  undefined1 auStack_230 [283];
  undefined1 auStack_115 [237];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_generate_serv_list_cb ENTER\n",
           "_sensor_test_generate_serv_list_cb",0x248);
  }
  iStack_234 = 0;
  uStack_238 = 0;
  memset(auStack_230,0,0x205);
  if (param_2 == 0) {
    uVar7 = 2;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d Input error\n","_sensor_test_generate_serv_list_cb",0x255);
    }
  }
  else {
    iVar4 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218);
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d ap_id=%d, rd_cnt=%d\n","_sensor_test_generate_serv_list_cb"
             ,0x25c,(uint)*(ushort *)(param_1 + 0x10),iVar4);
    }
    uVar7 = 0;
    if (0 < iVar4) {
      iVar9 = 1;
      uVar1 = *(undefined2 *)(param_1 + 0x10);
      do {
        uVar8 = 1;
        uVar7 = rdmngr_db_generate_rd_id(uVar1,iVar9);
        while (iVar5 = rdmngr_db_rd_entry_max_ssid_get(uVar7), (int)uVar8 <= iVar5) {
          iVar5 = wserv_db_is_wlanid_bind(uVar7,uVar8 & 0xff);
          if (iVar5 == 1) {
            rdmngr_db_get_freq_band_idx(uVar7,&iStack_234,&uStack_238);
            uVar10 = 1;
            if ((iStack_234 != 0) && (uVar10 = 0x10, iStack_234 != 1)) {
              uVar10 = 0;
            }
            iVar5 = wserv_db_rd_get_wserv_id(uVar7,uVar8 & 0xff);
            iVar6 = wserv_db_get_entry_by_id(iVar5,auStack_230);
            if (iVar6 == 0) {
              uVar2 = (uint)auStack_115 & 3;
              uVar3 = (uint)(auStack_115 + 3) & 3;
              if (((*(int *)(auStack_115 + -uVar2) << uVar2 * 8 |
                   (int)sensor_test_warning_switch & 0xffffffffU >> (4 - uVar2) * 8) &
                   -1 << (uVar3 + 1) * 8 | *(uint *)(auStack_115 + 3 + -uVar3) >> (3 - uVar3) * 8)
                  == 1) {
                if (iVar5 == -1) {
                  uVar8 = uVar8 + 1;
                }
                else {
                  iVar6 = sensor_get_backhaul_wserv_id();
                  if (iVar5 == iVar6) {
                    uVar8 = uVar8 + 1;
                  }
                  else {
                    iVar6 = sensor_get_default_backhaul_wserv_id();
                    if (iVar5 == iVar6) goto code_r0x004f5c50;
                    _sensor_test_insert_serv_id_into_list
                              (iVar5,uVar10,param_2,*(undefined4 *)(param_2 + 4));
                    uVar8 = uVar8 + 1;
                  }
                }
              }
              else {
                uVar8 = uVar8 + 1;
              }
            }
            else if ((int)sensor_test_warning_switch == 0) {
              uVar8 = uVar8 + 1;
            }
            else {
              printf("[SENSOR_TEST_WARNING]%s()/%d get wserv_entry fail\n",
                     "_sensor_test_generate_serv_list_cb",0x27d);
              uVar8 = uVar8 + 1;
            }
          }
          else {
code_r0x004f5c50:
            uVar8 = uVar8 + 1;
          }
        }
        iVar9 = iVar9 + 1;
        if (iVar4 < iVar9) {
          return 0;
        }
        uVar1 = *(undefined2 *)(param_1 + 0x10);
      } while( true );
    }
  }
  return uVar7;
}

