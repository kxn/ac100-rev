// func _uac_wserv_jcs_global_set @ 005d62dc size=1784

void _uac_wserv_jcs_global_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  byte bVar10;
  byte bVar11;
  char cVar12;
  
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_jcs_global_set() start\r\n",
           "_uac_wserv_jcs_global_set",0xe92);
  }
  iVar1 = json_object_object_get(param_1,"is_set_snp");
  if (iVar1 == 0) {
LAB_005d6358:
    if (jcs_err_switch == 0) {
      cVar12 = -1;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
             "_uac_wserv_jcs_global_set",0xe9d);
      cVar12 = -1;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    iVar6 = 0;
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        pcVar5 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_005d6830:
        printf(pcVar5,"_uac_wserv_jcs_global_set",0xe9d);
      }
      goto LAB_005d6358;
    }
    do {
      while( true ) {
        if (onoff_map <= iVar6) {
          if (jcs_err_switch == 0) goto LAB_005d6358;
          pcVar5 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
          goto LAB_005d6830;
        }
        iVar2 = iVar6 * 0x10;
        pcVar5 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
        if (pcVar5 != (char *)0x0) break;
        iVar6 = iVar6 + 1;
      }
      pcVar3 = (char *)json_object_get_string(iVar1);
      iVar4 = strcmp(pcVar5,pcVar3);
      iVar6 = iVar6 + 1;
    } while (iVar4 != 0);
    cVar12 = PTR__mt_onoff_00731f8c[iVar2 + 0xf];
  }
  iVar1 = json_object_object_get(param_1,"igmp_snooping_enable");
  if (iVar1 == 0) {
LAB_005d63a8:
    if (jcs_err_switch == 0) {
      bVar11 = 0xff;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
             "_uac_wserv_jcs_global_set",0xea0);
      bVar11 = 0xff;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    iVar6 = 0;
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        pcVar5 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_005d6814:
        printf(pcVar5,"_uac_wserv_jcs_global_set",0xea0);
      }
      goto LAB_005d63a8;
    }
    do {
      while( true ) {
        if (onoff_map <= iVar6) {
          if (jcs_err_switch == 0) goto LAB_005d63a8;
          pcVar5 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
          goto LAB_005d6814;
        }
        iVar2 = iVar6 * 0x10;
        pcVar5 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
        if (pcVar5 != (char *)0x0) break;
        iVar6 = iVar6 + 1;
      }
      pcVar3 = (char *)json_object_get_string(iVar1);
      iVar4 = strcmp(pcVar5,pcVar3);
      iVar6 = iVar6 + 1;
    } while (iVar4 != 0);
    bVar11 = PTR__mt_onoff_00731f8c[iVar2 + 0xf];
  }
  iVar1 = json_object_object_get(param_1,"igmp_drop_unknown");
  if (iVar1 == 0) {
LAB_005d63f8:
    if (jcs_err_switch == 0) {
      bVar10 = 0xff;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
             "_uac_wserv_jcs_global_set",0xea3);
      bVar10 = 0xff;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_uac_wserv_jcs_global_set",0xea3);
      }
      goto LAB_005d63f8;
    }
    pcVar5 = (char *)json_object_get_string(iVar1);
    iVar1 = atoi(pcVar5);
    bVar10 = (byte)iVar1;
  }
  iVar1 = json_object_object_get(param_1,"igmp_2g_rate");
  if (iVar1 == 0) {
LAB_005d6448:
    if (jcs_err_switch == 0) {
      uVar9 = 0xffff;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
             "_uac_wserv_jcs_global_set",0xea6);
      uVar9 = 0xffff;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_uac_wserv_jcs_global_set",0xea6);
      }
      goto LAB_005d6448;
    }
    pcVar5 = (char *)json_object_get_string(iVar1);
    iVar1 = atoi(pcVar5);
    uVar9 = (ushort)iVar1;
  }
  iVar1 = json_object_object_get(param_1,"igmp_5g_rate");
  if (iVar1 == 0) {
LAB_005d6498:
    if (jcs_err_switch == 0) {
      uVar8 = 0xffff;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
             "_uac_wserv_jcs_global_set",0xea9);
      uVar8 = 0xffff;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_uac_wserv_jcs_global_set",0xea9);
      }
      goto LAB_005d6498;
    }
    pcVar5 = (char *)json_object_get_string(iVar1);
    iVar1 = atoi(pcVar5);
    uVar8 = (ushort)iVar1;
  }
  iVar1 = json_object_object_get(param_1,"igmp_query_interval");
  if (iVar1 == 0) {
LAB_005d64e8:
    if (jcs_err_switch == 0) {
      uVar7 = 0xffff;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
             "_uac_wserv_jcs_global_set",0xeac);
      uVar7 = 0xffff;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_uac_wserv_jcs_global_set",0xeac);
      }
      goto LAB_005d64e8;
    }
    pcVar5 = (char *)json_object_get_string(iVar1);
    iVar1 = atoi(pcVar5);
    uVar7 = (ushort)iVar1;
  }
  iVar1 = json_object_object_get(param_1,"igmp_max_resp_time");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar5 = (char *)json_object_get_string(iVar1);
      iVar1 = atoi(pcVar5);
      DAT_0074fe60 = (byte)iVar1;
      goto LAB_005d6548;
    }
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
             "_uac_wserv_jcs_global_set",0xeaf);
    }
  }
  if (jcs_err_switch == 0) {
    DAT_0074fe60 = 0xff;
  }
  else {
    printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_uac_wserv_jcs_global_set",
           0xeaf);
    DAT_0074fe60 = 0xff;
  }
LAB_005d6548:
  g_wserv_igmp_entry = bVar11;
  DAT_0074fe59 = bVar10;
  DAT_0074fe5a = uVar9;
  DAT_0074fe5c = uVar8;
  DAT_0074fe5e = uVar7;
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> ignp_snp_enable = %d,igmp_drop_unknown=  %d, igmp_2g_rate = %d, igmp_5g_rate = %d, igmp_query_interval = %d, igmp_max_resp_time = %d\r\n"
           ,"_uac_wserv_jcs_global_set",0xeba,(uint)g_wserv_igmp_entry,(uint)DAT_0074fe59,
           (uint)DAT_0074fe5a,(uint)DAT_0074fe5c,(uint)DAT_0074fe5e,(uint)DAT_0074fe60);
  }
  if (cVar12 == '\x01') {
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> _uac_wserv_set_igmp_snooping_parameter_to_all_wserv() start.\r\n"
             ,"_uac_wserv_set_igmp_snooping_parameter_to_all_wserv",0x6bd);
    }
    wserv_db_entry_for_each_set_igmp_parameter(&g_wserv_igmp_entry);
    apmngr_db_foreach_proc
              (0x15f0000,_uac_wserv_send_igmp_snooping_parameter_to_all_ap_cb,&g_wserv_igmp_entry);
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> _uac_wserv_set_igmp_snooping_parameter_to_all_wserv() end.\r\n"
             ,"_uac_wserv_set_igmp_snooping_parameter_to_all_wserv",0x6cb);
    }
  }
  else {
    wserv_db_entry_for_each_set_igmp_parameter(&g_wserv_igmp_entry);
    apmngr_db_foreach_proc
              (0x15f0000,_uac_wserv_send_igmp_query_parameter_to_all_ap_cb,&g_wserv_igmp_entry);
  }
  rdmngr_set_multi_rate((undefined1)DAT_0074fe5a,(undefined1)DAT_0074fe5c);
  return;
}

