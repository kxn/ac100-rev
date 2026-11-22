// func _trans_sta_entry_to_json @ 004b3f58 size=1280

int _trans_sta_entry_to_json(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  tm *ptVar3;
  int extraout_v1;
  char *__format;
  undefined4 uVar4;
  char acStack_640 [272];
  tm tStack_530;
  undefined1 auStack_504 [304];
  undefined1 auStack_3d4 [220];
  undefined1 auStack_2f8 [12];
  int local_2ec;
  undefined2 local_2e8;
  ushort local_2e6;
  undefined4 local_2b8;
  byte local_2b0;
  byte local_2af;
  byte local_2ae;
  byte local_2ad;
  byte local_2ac;
  byte local_2ab;
  undefined1 auStack_2aa [458];
  undefined1 auStack_e0 [192];
  
  memset(auStack_2f8,0,0x2d8);
  memset(auStack_504,0,0x205);
  memset(&tStack_530,0,0x2c);
  if (param_1 == 0) {
    if (report_err_switch != 0) {
      __format = "[REPORT_ERROR]%s()/line %d : sta_entry is NULL.\n";
      uVar4 = 0x1c9;
LAB_004b43e4:
      printf(__format,"_trans_sta_entry_to_json",uVar4);
      return 0;
    }
  }
  else {
    iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x22),auStack_2f8);
    if (iVar1 == 0) {
      if (local_2ec != 0) {
        if (*(short *)(DAT_00767d58 + (uint)local_2e6 * 2) == 0) {
          return 0;
        }
        uVar4 = uac_wservice_get_wserv_id
                          (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                           *(undefined1 *)(param_1 + 0x25));
        iVar1 = wserv_db_get_entry_by_id(uVar4,auStack_504);
        if (iVar1 == 0) {
          iVar1 = json_object_new_object();
          if (iVar1 == 0) {
            if (report_err_switch != 0) {
              __format = "[REPORT_ERROR]%s()/line %d : malloc json obj failed.\n";
              uVar4 = 0x1e5;
              goto LAB_004b43e4;
            }
          }
          else {
            iVar2 = json_object_new_object();
            if (iVar2 != 0) {
              snprintf(acStack_640,0x100,"client_list_%d",param_2);
              json_object_object_add(iVar1,acStack_640,iVar2);
              snprintf(acStack_640,0x100,"%02X-%02X-%02X-%02X-%02X-%02X",
                       (uint)*(byte *)(param_1 + 0x68),(uint)*(byte *)(param_1 + 0x69),
                       (uint)*(byte *)(param_1 + 0x6a),(uint)*(byte *)(param_1 + 0x6b),
                       (uint)*(byte *)(param_1 + 0x6c),(uint)*(byte *)(param_1 + 0x6d));
              uVar4 = json_object_new_string(acStack_640);
              json_object_object_add(iVar2,"mac",uVar4);
              FUN_00408190(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x40),
                           *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),
                           *(undefined4 *)(param_1 + 0x4c),acStack_640,0x100,"---");
              uVar4 = json_object_new_string(acStack_640);
              json_object_object_add(iVar2,&DAT_00677c24,uVar4);
              FUN_00408190(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x54),
                           *(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x5c),
                           *(undefined4 *)(param_1 + 0x60),acStack_640,0x100,&DAT_00698ca0);
              uVar4 = json_object_new_string(acStack_640);
              json_object_object_add(iVar2,&DAT_00698ca4,uVar4);
              uVar4 = json_object_new_string(auStack_3d4);
              json_object_object_add(iVar2,"ssid",uVar4);
              uVar4 = apdb_get_dft_radio_freq_by_id
                                (local_2b8,auStack_e0,*(undefined1 *)(param_1 + 0x24));
              uVar4 = apdb_get_radio_freq_name_by_freq(uVar4);
              uVar4 = json_object_new_string(uVar4);
              json_object_object_add(iVar2,"freq_name",uVar4);
              uVar4 = json_object_new_string(auStack_2aa);
              json_object_object_add(iVar2,"ap_name",uVar4);
              snprintf(acStack_640,0x100,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2b0,
                       (uint)local_2af,(uint)local_2ae,(uint)local_2ad,(uint)local_2ac,
                       (uint)local_2ab);
              uVar4 = json_object_new_string(acStack_640);
              json_object_object_add(iVar2,"ap_mac",uVar4);
              uVar4 = rdmngr_db_generate_rd_id(local_2e8,*(undefined1 *)(param_1 + 0x24));
              uVar4 = rdmngr_db_get_rd_entry_chnl(uVar4);
              snprintf(acStack_640,0x100,"%d",uVar4);
              uVar4 = json_object_new_string(acStack_640);
              json_object_object_add(iVar2,"channel",uVar4);
              snprintf(acStack_640,0x100,"%d",(int)*(char *)(param_1 + 0x35));
              uVar4 = json_object_new_string(acStack_640);
              json_object_object_add(iVar2,"rssi",uVar4);
              ptVar3 = localtime_r((time_t *)(param_1 + 0x70),&tStack_530);
              strftime(acStack_640,0x100,"%Y/%m/%d",ptVar3);
              uVar4 = json_object_new_string(acStack_640);
              json_object_object_add(iVar2,"connect_date",uVar4);
              ptVar3 = localtime_r((time_t *)(param_1 + 0x70),&tStack_530);
              strftime(acStack_640,0x100,"%H:%M:%S",ptVar3);
              uVar4 = json_object_new_string(acStack_640);
              json_object_object_add(iVar2,"connect_time",uVar4);
              FUN_00407e70();
              snprintf(acStack_640,0x100,"%d",extraout_v1 - *(int *)(param_1 + 0x78));
              uVar4 = json_object_new_string(acStack_640);
              json_object_object_add(iVar2,"online_time",uVar4);
              return iVar1;
            }
            if (report_err_switch != 0) {
              printf("[REPORT_ERROR]%s()/line %d : malloc json obj failed.\n",
                     "_trans_sta_entry_to_json",0x1eb);
            }
            json_object_put(iVar1);
          }
        }
      }
    }
    else if (report_err_switch != 0) {
      __format = "[REPORT_ERROR]%s()/line %d : sta_entry get ap_entry failed.\n";
      uVar4 = 0x1cf;
      goto LAB_004b43e4;
    }
  }
  return 0;
}

