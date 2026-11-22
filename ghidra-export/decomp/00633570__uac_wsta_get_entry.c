// func _uac_wsta_get_entry @ 00633570 size=2224

int _uac_wsta_get_entry(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  tm *ptVar7;
  char *pcVar8;
  byte *pbVar9;
  tm tStack_520;
  undefined1 auStack_4f4 [18];
  byte local_4e2;
  byte local_4e0 [2];
  undefined1 auStack_4de [34];
  undefined1 auStack_4bc [53];
  char local_487;
  ushort local_440;
  char acStack_43c [256];
  char acStack_33c [256];
  undefined1 auStack_23c [300];
  undefined4 local_110;
  undefined1 auStack_10c [220];
  int local_30;
  
  memset(acStack_33c,0,0x100);
  memset(&tStack_520,0,0x2c);
  local_30 = param_2[7];
  memset(auStack_4f4,0,0x38);
  memset(auStack_4bc,0,0x80);
  if (((code *)param_2[5] != (code *)0x0) &&
     (iVar1 = (*(code *)param_2[5])(param_1,param_2[6]), iVar1 == 1)) {
    return 0;
  }
  param_2[4] = param_2[4] + 1;
  if (param_2[1] <= param_2[3]) {
    return 0;
  }
  if (param_2[2] < *param_2) {
    param_2[2] = param_2[2] + 1;
    return 0;
  }
  param_2[3] = param_2[3] + 1;
  iVar1 = json_object_new_object();
  if (iVar1 == 0) {
    if (g_wsta_error == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    pcVar8 = "<wsta>[error]%s(): %d  -> no memory!\r\n";
    uVar3 = 0x1f8;
  }
  else {
    iVar2 = json_object_new_array();
    if (iVar2 != 0) {
      snprintf(acStack_33c,0x100,"%d",*(undefined4 *)(param_1 + 0x1c));
      uVar3 = json_object_new_string(acStack_33c);
      json_object_object_add(iVar1,"entry_id",uVar3);
      snprintf(acStack_33c,0x100,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x68),
               (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
               (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
               (uint)*(byte *)(param_1 + 0x6d));
      uVar3 = json_object_new_string(acStack_33c);
      json_object_object_add(iVar1,"mac",uVar3);
      uVar3 = FUN_0063240c(*(undefined4 *)(param_1 + 0x20),acStack_33c);
      uVar3 = json_object_new_string(uVar3);
      json_object_object_add(iVar1,"ap_name",uVar3);
      iVar4 = wsta_db_get_mac_entry_by_mld(param_1 + 0x68,auStack_4f4);
      if (iVar4 == 0) {
        if ((g_wsta_debug != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("<wsta>[debug]%s(): %d  -> %02X-%02X-%02X-%02X-%02X-%02X is mld mac!\r\n",
                 "_uac_wsta_get_entry",0x210,(uint)*(byte *)(param_1 + 0x68),
                 (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
                 (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
                 (uint)*(byte *)(param_1 + 0x6d));
        }
        pbVar9 = local_4e0;
        for (iVar4 = 0; iVar4 < (int)(uint)local_4e2; iVar4 = iVar4 + 1) {
          iVar5 = json_object_new_object();
          if (iVar5 == 0) {
            if ((g_wsta_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
            goto LAB_00633bf4;
            uVar3 = 0x216;
            goto LAB_00633ddc;
          }
          memset(acStack_43c,0,0x100);
          snprintf(acStack_43c,0x100,"%d",(uint)*pbVar9);
          uVar3 = json_object_new_string(acStack_43c);
          json_object_object_add(iVar5,"freq_unit",uVar3);
          uVar3 = _uac_wsta_get_rd_freq_unit_name(*(undefined4 *)(param_1 + 0x20),*pbVar9);
          uVar3 = json_object_new_string(uVar3);
          json_object_object_add(iVar5,"freq_name",uVar3);
          iVar6 = wsta_db_get_entry_by_mac(auStack_4de + iVar4 * 0xc,auStack_4bc);
          if (iVar6 == 0) {
            snprintf(acStack_33c,0x100,"%d",(uint)local_440);
            uVar3 = json_object_new_string(acStack_33c);
            json_object_object_add(iVar5,"nego_rate",uVar3);
            snprintf(acStack_33c,0x100,"%d",(int)local_487);
            pcVar8 = acStack_33c;
          }
          else {
            uVar3 = json_object_new_string("---");
            json_object_object_add(iVar5,"nego_rate",uVar3);
            pcVar8 = "---";
          }
          uVar3 = json_object_new_string(pcVar8);
          json_object_object_add(iVar5,"rssi",uVar3);
          pbVar9 = pbVar9 + 0xc;
          json_object_array_add(iVar2,iVar5);
        }
LAB_006339f8:
        json_object_object_add(iVar1,"rf_entry",iVar2);
        iVar2 = uac_wsta_get_wserv_entry
                          (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                           *(undefined1 *)(param_1 + 0x25),auStack_23c);
        if (iVar2 == 0) {
          uVar3 = json_object_new_string(auStack_10c);
          json_object_object_add(iVar1,"ssid",uVar3);
          memset(acStack_43c,0,0x100);
        }
        else {
          uVar3 = json_object_new_string("---");
          json_object_object_add(iVar1,"ssid",uVar3);
          memset(acStack_43c,0,0x100);
          local_110 = 1;
        }
        snprintf(acStack_43c,0x100,"%d",local_110);
        uVar3 = json_object_new_string(acStack_43c);
        json_object_object_add(iVar1,"encode",uVar3);
        snprintf(acStack_33c,0x100,"%d",(uint)*(ushort *)(param_1 + 0x2e));
        uVar3 = json_object_new_string(acStack_33c);
        json_object_object_add(iVar1,"vlan_id",uVar3);
        ptVar7 = localtime_r((time_t *)(param_1 + 0x70),&tStack_520);
        strftime(acStack_33c,0x100,"%Y/%m/%d",ptVar7);
        uVar3 = json_object_new_string(acStack_33c);
        json_object_object_add(iVar1,"connect_date",uVar3);
        ptVar7 = localtime_r((time_t *)(param_1 + 0x70),&tStack_520);
        strftime(acStack_33c,0x100,"%H:%M:%S",ptVar7);
        uVar3 = json_object_new_string(acStack_33c);
        json_object_object_add(iVar1,"connect_time",uVar3);
        pcVar8 = "0.0.0.0";
        if (*(char *)(param_1 + 0x3c) == '\x01') {
          pcVar8 = acStack_43c;
          memset(pcVar8,0,0x40);
          FUN_00408190(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x40),
                       *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),
                       *(undefined4 *)(param_1 + 0x4c),pcVar8,0x40,"0.0.0.0");
        }
        uVar3 = json_object_new_string(pcVar8);
        json_object_object_add(iVar1,&DAT_00677c24,uVar3);
        pcVar8 = "::";
        if (*(char *)(param_1 + 0x50) == '\x02') {
          pcVar8 = acStack_43c;
          memset(pcVar8,0,0x40);
          FUN_00408190(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x54),
                       *(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x5c),
                       *(undefined4 *)(param_1 + 0x60),pcVar8,0x40,&DAT_00698ca0);
        }
        uVar3 = json_object_new_string(pcVar8);
        json_object_object_add(iVar1,&DAT_00698ca4,uVar3);
        json_object_array_add(local_30,iVar1);
        return iVar2;
      }
      iVar4 = wsta_db_get_mac_entry_by_peer(param_1 + 0x68,auStack_4f4);
      if (iVar4 == 0) {
        if ((g_wsta_debug != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("<wsta>[debug]%s(): %d  -> %02X-%02X-%02X-%02X-%02X-%02X is peer mac!\r\n",
                 "_uac_wsta_get_entry",0x22e,(uint)*(byte *)(param_1 + 0x68),
                 (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
                 (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
                 (uint)*(byte *)(param_1 + 0x6d));
        }
      }
      else {
        iVar4 = json_object_new_object();
        if (iVar4 != 0) {
          memset(acStack_43c,0,0x100);
          snprintf(acStack_43c,0x100,"%d",(uint)*(byte *)(param_1 + 0x24));
          uVar3 = json_object_new_string(acStack_43c);
          json_object_object_add(iVar4,"freq_unit",uVar3);
          uVar3 = _uac_wsta_get_rd_freq_unit_name
                            (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24));
          uVar3 = json_object_new_string(uVar3);
          json_object_object_add(iVar4,"freq_name",uVar3);
          snprintf(acStack_33c,0x100,"%d",(uint)*(ushort *)(param_1 + 0x7c));
          uVar3 = json_object_new_string(acStack_33c);
          json_object_object_add(iVar4,"nego_rate",uVar3);
          snprintf(acStack_33c,0x100,"%d",(int)*(char *)(param_1 + 0x35));
          uVar3 = json_object_new_string(acStack_33c);
          json_object_object_add(iVar4,"rssi",uVar3);
          json_object_array_add(iVar2,iVar4);
          goto LAB_006339f8;
        }
        if ((g_wsta_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          uVar3 = 0x236;
LAB_00633ddc:
          printf("<wsta>[error]%s(): %d  -> Create json object failed.\r\n","_uac_wsta_get_entry",
                 uVar3);
        }
      }
LAB_00633bf4:
      json_object_put(iVar1);
      json_object_put(iVar2);
      return -1;
    }
    json_object_put(iVar1);
    if (g_wsta_error == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    pcVar8 = "<wsta>[error]%s(): %d  -> Create json object failed.\r\n";
    uVar3 = 0x200;
  }
  printf(pcVar8,"_uac_wsta_get_entry",uVar3);
  return -1;
}

